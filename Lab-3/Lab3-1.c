#include <stdio.h>
#include <string.h>

int main(){

    int result;
    char str[100];

    scanf("%d",&result);
    printf("%d ->",result);

    while(result>=10){

        sprintf(str,"%d",result);
        int x=strlen(str)-1;
        result=0;

        for(int y=0 ; y<=x ; y++){

            result=result+(str[y]-48);
        }
        if(result>=10){

            printf(" %d ->",result);
        }
    }

    printf(" %d",result);

    return 0;
}