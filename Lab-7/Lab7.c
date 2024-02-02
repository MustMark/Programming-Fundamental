#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define MAX 5

void gotoxy(int x, int y) {

    COORD c = { x,y };
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setcolor(int fg, int bg) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void draw_ship(int x, int y) {

    gotoxy(x, y);
    setcolor(2, 4);
    printf("<-0->");
}

void erase_ship(int x, int y) {

    gotoxy(x, y);
    setcolor(0, 0);
    printf("     ");
}

void setcursor(int visible) {

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}

void draw_bullet(int x, int y) {

    setcolor(0, 2);
    gotoxy(x, y);
    printf("^");
}

void erase_bullet(int x, int y) {

    setcolor(0, 0);
    gotoxy(x, y);
    printf(" ");
}

void draw_star(int x,int y) {

    setcolor (0,6);
    gotoxy(x,y);
    printf("*");
}

char cursor(int x, int y) {

    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2]; COORD c = {x,y}; DWORD num_read;
    if(!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read)){

        return '\0';
    }
    else{

        return buf[0];
    }
}

int main() {

    char ch = ' ', move = ' ';
    int x = 1, y = 15, score = 0;
    int bx[MAX], by[MAX];
    int Bullet[MAX] = {1,1,1,1,1};
    setcursor(0);
    draw_ship(x, y);
    srand(time(NULL));

    for (int i = 0 ; i < 20 ; i++){
        
        draw_star(rand()%61 + 10, rand()%4 + 2);
    }

    do {
        setcolor(0,8);
        gotoxy(105,1);
        printf("Score : %d",score);
        if (move == 'a' && x > 0) {

            erase_ship(x, y);
            draw_ship(--x, y);
        }
        if (move == 'd' && x < 100) {

            erase_ship(x, y);
            draw_ship(++x, y);
        }
        for (int i = 0; i < MAX; ++i) {
            if (Bullet[i] == 0) {

                erase_bullet(bx[i], by[i]);
                if (by[i] > 0) {

                    if (cursor(bx[i],by[i]-1) == '*'){

                        Beep(700, 100);
                        score = score+10;
                        draw_star(rand()%61 + 10, rand()%4 + 2);                       
                    }
                    draw_bullet(bx[i], --by[i]);
                }
                else {

                    Bullet[i] = 1;
                }
            }
        }
        Sleep(20);

        if (_kbhit()) {

            ch = _getch();

            if (ch == 'a' && x > 0) {

                move = 'a';
            }
            if (ch == 'd' && x < 100) {

                move = 'd';
            }
            if (ch == 's') {

                move = 's';
            }
            if (ch == 'p') {

                for (int i = 0; i < MAX; ++i) {

                    if (Bullet[i] == 1) {
                        bx[i] = x + 2;
                        by[i] = y - 1;
                        Bullet[i] = 0;
                        break;
                    }
                }
            }
            fflush(stdin);
        }
    } while (ch != 'x');

    return 0;
}