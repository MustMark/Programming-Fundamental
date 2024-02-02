#include <stdio.h>

int main(){

  int num,mid;

  scanf("%d",&mid);
  num=(mid*2)-1;
  
  for(int y=1 ; y<=num ; y++){
    if(y <= mid){
      for(int x=1 ; x<=num ; x++){
        if(x<=y){
          printf("*");
        }
        else if(x>num-y){
          printf("*");
        }
        else{
          printf(" ");
        }
      }
    }
    else if(y > mid){
      for(int x=1 ; x<=num ; x++){

        if(x<=num-y+1){
          printf("*");
        }
        else if(x>=y){
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