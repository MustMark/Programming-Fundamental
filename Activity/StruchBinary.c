#include <stdio.h>

int main(){
    
    FILE *fptr;

    struct player{

        char name[100];
        int level;
        int score;
    } p;

    fptr = fopen("C:\\Users\\asus\\OneDrive\\Desktop\\Binaryfile.txt", "w");

    for(int i=0 ; i<5 ; i++){

        printf("Enter Player %d (Name Level Score) : ",i+1);
        scanf("%s %d %d",p.name,&p.level,&p.score);
        fwrite(&p,sizeof(struct player),1,fptr);
    }

    fclose(fptr);

    return 0;
}

//66011442 พีรวัส อิงคสันตติกุล