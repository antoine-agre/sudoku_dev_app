#include "Header.h"
FILE* fichier = NULL;


void saveGrid(Grid grille){
    char name[30];
    printf("entrez le nom de la grille \n");
    scanf("%s",name);
    strcat(name, ".txt");
    fichier = fopen(name, "w");
    //printf("\n\n");
    //fputs("\n", fichier);
    for (int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(grille[i][j] == 0){
                    //printf(".\t");
                    fputs("0", fichier);}
            else {
                    //printf("%d\t", grille[i][j]);
                    fprintf(fichier,"%d", grille[i][j]);
            }
        }
        //printf("\n\n");
        fputs("\n", fichier);
    }

}


void readGrille(Grid grille)
{
    fichier = fopen("grille1.txt", "r");
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            grille[i][j]=fgetc(fichier)-48;
        }
        fseek(fichier, 2, SEEK_CUR);
    }

}
