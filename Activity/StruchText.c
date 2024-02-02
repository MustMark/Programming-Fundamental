#include <stdio.h>
#include <string.h>

int main(){
    
    struct player{

        char name[100];
        int level;
        int score;
    };
    
    struct player p[5];

    for(int i=0 ; i<5 ; i++){

        printf("Enter Player %d (Name Level Score) : ",i+1);
        scanf("%s %d %d",&p[i].name,&p[i].level,&p[i].score);
    }
        
    FILE *fp;
    fp = fopen("C:\\Users\\asus\\OneDrive\\Desktop\\textfile.txt", "w");

    for(int i=0 ; i<5 ; i++){
        
        fprintf(fp, "(Player %d) Name : %s\t Level : %d\t Score : %d\n",i+1,p[i].name,p[i].level,p[i].score);
    }
    fclose(fp);

    return 0;
}

//66011442 พีรวัส อิงคสันตติกุล