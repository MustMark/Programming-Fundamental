#include <stdio.h>

int main(){

    for(int x=1 ; x<=10000 ; x++){

        int result=0;

        for(int y=1 ; y<x ; y++){
            
            if(x%y==0){

                result=result+y;
            }
        }

        if(x==result){

            printf("%d\n",x);
        }
    }

    return 0;
}