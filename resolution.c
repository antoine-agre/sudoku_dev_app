#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 9

typedef int Grid[MAX][MAX];
typedef int Cube[MAX+2][MAX+1][MAX+1];

/*On va traiter un cube.
Soit (x, y, z) les coordonnées dans ce cube, où x : ligne, y : colonne, z : plan.
Le cube contient des 1/0 pour 1 <= x <= MAX, 1 <= y <= MAX, 1 <= Z <= MAX; et des compteurs pour le reste (avec des cases inutilisées).*/

void printCube(Cube cube){

    for(int k = 0; k <= MAX; k++){
        printf("PLAN %d\n",k);
        for(int i = 0; i <= MAX+1; i++){
            for(int j = 0; j <= MAX; j++){
                printf("%d\t",cube[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

}

void initCube(Cube cube){
    //Pour une grille vide

    //0 initiaux
    printf("0 initiaux");
    for(int i = 0; i <= MAX+1; i++){
        for(int j = 0; j <= MAX; j++){
            for(int k = 0; k <= MAX; k++){
                cube[i][j][k] = 0;
            }
        }
    }

    //Grilles principales
    printf("grilles principales");
    for(int i = 1; i <= MAX; i++){
        for(int j = 1; j <= MAX; j++){
            for(int k = 1; k <= MAX; k++){
                cube[i][j][k] = 1;
            }
        }
    }

    //grille de compteurs du plan 0
    printf("grille de compteurs du plan 0");
    for(int i = 1; i <= MAX; i++){
        for(int j = 1; j <= MAX; j++){
            cube[i][j][0] = MAX;
        }
    }

    //compteurs des plans non-nuls
    printf("compteurs des plans non-nuls");
    for(int i = 0; i <= MAX+1; i+=MAX+1){
        for(int j = 1; j <= MAX; j++){
            for(int k = 1; k <= MAX; k++){
                cube[i][j][k] = MAX;
            }
        }
    }

    for(int i = 1; i <= MAX; i++){
        for(int k = 1; k <= MAX; k++){
            cube[i][0][k] = MAX;
        }
    }
}

void updateCube(Cube cube, int l, int c){
//Met à jour le cube pour un chiffre placé aux coordonnées l c

    //

}

void updateCompteurs(Cube cube, int plan){
//Met à jour les compteurs du plan donné du cube

    if(plan == 0){

        for(int i = 1; i <= MAX; i++){
            for(int j = 1; j <= MAX; j++){

                int count = 0;
                for(int k = 1; k <= MAX; k++){
                    if(cube[i][j][k] == 1){count++;}
                }
                cube[i][j][0] = count;
            }
        }
    }

    else{

        //Lignes
        for(int i = 1; i <= MAX; i++){

            int count = 0;
            for(int j = 1; j <= MAX; j++){
                if(cube[i][j][plan] == 1){count++;}
            }
            cube[i][0][plan] = count;
        }

        //Colonnes
        for(int j = 1; j <= MAX; j++){

            int count = 0;
            for(int i = 1; i <= MAX; i++){
                if(cube[i][j][plan] == 1){count++;}
            }
            cube[0][j][plan] = count;
        }

        //Régions
        for(int i = 1; i <= sqrt(MAX); i++){
            for(int j = 1; j <= sqrt(MAX); j++){
                int count = 0;

                for(int m = 1; m <= sqrt(MAX); m++){
                    for(int n = 1; n <= sqrt(MAX); n++){
                        if(cube[(int)(m+sqrt(MAX)*i)][(int)(n+sqrt(MAX)*j)][plan]==1){count++;}
                    }
                }
                cube[MAX+1][i+j-1][plan] = count;

            }
        }

    }

}

//void createCube pour une grille existante ?
