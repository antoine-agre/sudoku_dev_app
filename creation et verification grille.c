#include <stdio.h>
#include <stdlib.h>
#define MAX 9
typedef int Grid[MAX][MAX]

void compareGrig(Grid grid1,Grid grid2){
//procédure qui compare deux grilles et affiche en rouge les cases non identiques. (grid1 = grille de vérification)
int i,j; //i lignes ; j colonnes
for(i=0;i<MAX;i++){
        printf("\n");
    for(j=0;j<MAX;j++){
        if(grid1[i][j]!=grid2[i][j]){
            printf("\t !=");
        }
        else{
            printf("\t %d",grid2[i][j]);
        }
    }
}
}