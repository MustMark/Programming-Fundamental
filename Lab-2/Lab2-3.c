#include <stdio.h>

int main(){

    int num;
    int x,y;

    printf("Enter number : ");
    scanf("%d",&num);

    for(y=1 ; y<=num ; y=y+1){

        for(x=1 ; x<=num ; x=x+1){

            if(y==1 || y==num){

                printf("*");
            }
            else{

                if(x==1 || x==num){

                    printf("*");
                }
                else{

                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}