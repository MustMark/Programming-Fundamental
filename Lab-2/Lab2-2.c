#include <stdio.h>

int main(){

    int num1;
    int num2;
    int result;

    printf("Enter first number:");
    scanf("%d",&num1);
    printf("Enter second number:");
    scanf("%d",&num2);

    while(num1 != num2){

        if(num1 > num2){
            num1 = num1-num2;
        }

        else{
            num2 = num2-num1;
        }
    }

    result = num1;
    printf("Greatest common divisor = %d",result);

    return 0;

}
