#include <stdio.h>

int main(){

    char *p,str[50];
    p=str;

    scanf("%s",str);

    while(*p != '\0'){
        
        if(*p >= 'A' && *p <= 'Z'){

            printf("%c",*p+32);
        }
        else if(*p >= 'a' && *p <= 'z'){

            printf("%c",*p-32);
        }
        p++;
        
    }

    return 0;
}