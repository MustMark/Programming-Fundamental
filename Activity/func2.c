#include <stdio.h>

float area(float x1,float y1,float x2,float y2,float x3,float y3){

    float area;

    area=((x1*y2)+(x2*y3)+(x3*y1)-(x2*y1)-(x3*y2)-(x1*y3))/2;
    
    if(area < 0){

        area = area*-1;
    }

    return area;
}

int main(){

    int x1,y1,x2,y2,x3,y3;
    float num;

    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);

    printf("%.2f",area(x1,y1,x2,y2,x3,y3));
    return 0;
}