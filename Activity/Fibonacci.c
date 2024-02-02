#include <stdio.h>

int main(){

    int n,fi[100]={0,1};

    scanf("%d",&n);
    
    if(n==1 || n==2){

        printf("%d",fi[n-1]);
    }
    else if(n>2){

        for(int x=2 ; x<n ; x++){

            fi[x]=fi[x-1]+fi[x-2];
        }
        printf("%d\n",fi[n-1]);
    }

    return 0;
}