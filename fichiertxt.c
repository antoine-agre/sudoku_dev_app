#include "Header.h"
FILE* fichier = NULL;

void saveGrid(Grid grid){
    char name[30];
    printf("Entre le nom de la grille \n");
    scanf("%s",name);
    strcat(name, ".txt");
    fichier = fopen(name, "w");
    //printf("\n\n");
    //fputs("\n", fichier);
    for (int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(grid[i][j] == 0){
                    //printf(".\t");
                    fputs("0", fichier);}
            else {
                    //printf("%d\t", grille[i][j]);
                    fprintf(fichier,"%d", grid[i][j]);
            }
        }
        //printf("\n\n");
        fputs("\n", fichier);
    }
}


void readGrid(Grid grid){
    char grilles[30];
    printf("Entrez la grille que vous voulez lire \n");
    scanf("%s", grilles);
    strcat(grilles, ".txt");
    fichier = fopen(grilles, "r");
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            grid[i][j]=fgetc(fichier)-48;
        }
        fseek(fichier, 2, SEEK_CUR);
    }
}
