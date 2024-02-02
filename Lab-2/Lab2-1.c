#include <stdio.h>

int main (){

    int num;
    int x;

    printf("Enter number:");
    scanf("%d",&num);
    printf("Factoring Result : ");

    while (num%2 == 0){

        printf("%d",2);
        printf(" x ");
        num = num/2;

    }

    for (x=3 ; x<=num ; x = x+2){

        while (num%x == 0){

            printf("%d",x);

            if (num/x != 1){

                printf(" x ");

            }
            num = num/x;
        }


    }

    return 0;

}