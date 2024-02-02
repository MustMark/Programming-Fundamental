#include <string.h>
#include <stdio.h>

int main(){

    struct student{

        char name[100];
        int id;
        int age;
    };
    
    struct student p[3];

    for(int i=0 ; i<3 ; i++){

        printf("Enter Student %d (Name ID Age) : ",i+1);
        scanf("%s %d %d",&p[i].name,&p[i].id,&p[i].age);
    }

    for(int i=0 ; i<3 ; i++){

        printf("[Student %d] Name : %s\t Student ID : %d\t Age : %d\n",i+1,p[i].name,p[i].id,p[i].age);
    }

    return 0;
}