#include <stdio.h>
#include <windows.h>
#include <time.h>

#define scount 80
#define screen_x 80
#define screen_y 25

HANDLE wHnd;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
COORD shipPos = { 40,12 };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
COORD star[scount];
HANDLE rHnd;
DWORD fdwMode;
int count = 0;

int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);

	return 0;
}

int setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
		ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}

void clear_buffer()
{
	for (int y = 0; y < screen_y; ++y) {

		for (int x = 0; x < screen_x; ++x) {

			consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
			consoleBuffer[x + screen_x * y].Attributes = 0;
		}
	}
}
void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
}

void init_star()
{
	for (int j = 0; j < scount; j++) {

		star[j].X = rand() % 81;
		star[j].Y = rand() % 26;
	}

}

void star_fall()
{
	int i;
	for (i = 0; i < scount; i++) {
		if (star[i].Y >= screen_y - 1) {

			star[i].X = rand() % screen_x;
			star[i].Y = 1;
		}
		else {

			star[i] = { star[i].X, star[i].Y + 1 };
		}
	}
}

void fill_star_to_buffer()
{
	for (int i = 0; i < screen_x; i++) {
		if (star[i].X != 0 && star[i].Y != 0)

			consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
		consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 6;
	}
}

void fill_ship_to_buffer(int color)
{
	consoleBuffer[shipPos.X - 2 + screen_x * shipPos.Y].Char.AsciiChar = '<';
	consoleBuffer[shipPos.X - 2 + screen_x * shipPos.Y].Attributes = color;

	consoleBuffer[shipPos.X - 1 + screen_x * shipPos.Y].Char.AsciiChar = '-';
	consoleBuffer[shipPos.X - 1 + screen_x * shipPos.Y].Attributes = color;

	consoleBuffer[shipPos.X + screen_x * shipPos.Y].Char.AsciiChar = '0';
	consoleBuffer[shipPos.X + screen_x * shipPos.Y].Attributes = color;

	consoleBuffer[shipPos.X + 1 + screen_x * shipPos.Y].Char.AsciiChar = '-';
	consoleBuffer[shipPos.X + 1 + screen_x * shipPos.Y].Attributes = color;

	consoleBuffer[shipPos.X + 2 + screen_x * shipPos.Y].Char.AsciiChar = '>';
	consoleBuffer[shipPos.X + 2 + screen_x * shipPos.Y].Attributes = color;
}

void setcursor(int visible) 
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

void collision(int x, int y) 
{
	for (int i = 0; i < scount; i++) {

		if (x == star[i].X && y == star[i].Y) {

			star[i].X = rand() % 81;
			star[i].Y = rand() % 26;

			count++;
		}
	}
}

int main()
{
	int shipcolor=4;
	bool play = true;

	DWORD numEvents = 0;
	DWORD numEventsRead = 0;

	srand(time(NULL));
	setConsole(screen_x, screen_y);
	setMode();
	setcursor(0);
	init_star();

	while (play)
	{
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0) {
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
			for (DWORD i = 0; i < numEventsRead; ++i) {
				if (eventBuffer[i].EventType == KEY_EVENT &&
					eventBuffer[i].Event.KeyEvent.bKeyDown == true) {
					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
						play = false;
					}
					else if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == 'C') {

						shipcolor = rand() % 16;
					}
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT) {
					shipPos.X = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					shipPos.Y = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
					if (eventBuffer[i].Event.MouseEvent.dwButtonState &
						FROM_LEFT_1ST_BUTTON_PRESSED) {

						shipcolor = rand() % 16;
					}
				}
			}
			delete[] eventBuffer;
		}

		clear_buffer();
		fill_star_to_buffer();
		fill_ship_to_buffer(shipcolor);
		collision(shipPos.X, shipPos.Y);

		if (count >= 10) {

			play = false;
		}

		fill_buffer_to_console();
		Sleep(100);
	}

	return 0;
}