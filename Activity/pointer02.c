#include <stdio.h>
#include <string.h>

int main(){

    char *first,*last,str[128];
    int Palindrome=0;

    scanf("%s",str);
    
    first=&str[0];
    last=&str[strlen(str)-1];

    while(first < last){

        if(*first != *last){

            Palindrome = 1;
        }
        first++;
        last--;
    }

    if(Palindrome == 0){

        printf("Palindrome");
    }
    else{

        printf("Not Palindrome");
    }

    return 0;
}