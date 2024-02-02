#include <stdio.h>

int main(){
    
    int num;

    printf("Enter number : ");
    scanf("%d",&num);

    for(int y=1 ; y<=num ; y++){

        int ascii=96+y;

        for(int x=1 ; x<=num ; x++){

            printf("%c",ascii);
            ascii++;
        }
        printf("\n");
    }
    return 0;
}