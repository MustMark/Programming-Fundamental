#include <stdio.h>

int main(){

    int num;
    scanf("%d",&num);

    for(int x=1 ; x<num-1 ; x++){
        for(int y=2 ; y<num ; y++){
            for(int z=3 ; z<=num ; z++){
                if(x<y && y<z){
                    printf("(%d,%d,%d)\n",x,y,z);
                }
            }
        }
    }

    return 0;
}