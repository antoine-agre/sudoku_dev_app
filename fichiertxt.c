#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#define MAX 9
typedef int Grid[MAX][MAX];
FILE* fichier = NULL;


void saveGrid(Grid grille){

    char name[30];
    printf("entrez le nom de la grille \n");
    scanf("%s",name);
    strcat(name, ".txt");
    fichier = fopen(name, "w");
    //printf("\n\n");
    fputs("\n", fichier);
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
