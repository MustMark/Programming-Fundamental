#include <stdio.h>
#include <string.h>

void uniq(char *str){

    int x=0,length=strlen(str);
    
    if(length==1){

        return;
    }

    for(int i=0 ; i<length ; i++){

        if(i==0 || str[i] != str[i-1]){

            str[x]=str[i];
            x++;
        }
    }
    str[x] = '\0';
}

int main(){

    char A[128],B[128];

    printf("Enter string A : ");
    scanf("%s",A);
    printf("Enter string B : ");
    scanf("%s",B);

    uniq(A);
    uniq(B);
    
    if(strcmp(A,B)==0){

        printf("TRUE");
    }
    else{

        printf("FALSE");
    }
    
    return 0;
}