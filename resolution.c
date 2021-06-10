#include "Header.h"

/*On va traiter un cube.
Soit (x, y, z) les coordonnées dans ce cube, où x : ligne, y : colonne, z : plan.
Le cube contient des 1/0 pour 1 <= x <= MAX, 1 <= y <= MAX, 1 <= Z <= MAX; et des compteurs pour le reste (avec des cases inutilisées).*/

void printCube(Cube cube){
//Affiche le contenu du cube, sous forme de plans successifs.
//Utilisé uniquement en debug.

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
//Initialise cube comme correspondant à une grille vide.

    //0 initiaux
    for(int i = 0; i <= MAX+1; i++){
        for(int j = 0; j <= MAX; j++){
            for(int k = 0; k <= MAX; k++){
                cube[i][j][k] = 0;
            }
        }
    }

    //Grilles principales
    for(int i = 1; i <= MAX; i++){
        for(int j = 1; j <= MAX; j++){
            for(int k = 1; k <= MAX; k++){
                cube[i][j][k] = 1;
            }
        }
    }

    //grille de compteurs du plan 0
    for(int i = 1; i <= MAX; i++){
        for(int j = 1; j <= MAX; j++){
            cube[i][j][0] = MAX;
        }
    }

    //compteurs des plans non-nuls
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

void updateCube(Cube cube, int l, int c, int x){
//Met à jour le cube pour un entier x placé aux coordonnées l c de la grille.

    //0 sur ligne
    /*for(int i = 1; i <= MAX; i++){
        cube[l][i][x] = 0;
    }

    //0 sur colonne
    for(int i = 1; i <= MAX; i++){
        cube[i][c][x] = 0;
    }

    //0 sur "colonne" plan
    for(int i = 1; i <= MAX; i++){
        cube[l][c][i] = 0;
    }*/

    for(int i = 1; i <= MAX; i++){
        cube[l][i][x] = 0;//0 sur ligne
        cube[i][c][x] = 0;//0 sur colonne
        cube[l][c][i] = 0;//0 sur "colonne" plan
    }

    //maj compteurs
    for(int i = 0; i <= MAX; i++){
        updateCompteurs(cube, i);
    }

}

void generateCube(Cube cube, Grid grid){
//Génere un cube correspondant à la grille passée en paramètre.

    initCube(cube);

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            //Pour chaque indice de la grille
            if(grid[i][j] != 0){

                updateCube(cube, i+1, j+1, grid[i][j]);
                //printCube(cube);

            }
        }
    }

}

void updateCompteurs(Cube cube, int plan){
//Met à jour les compteurs du plan donné du cube.

    int count;

    if(plan == 0){

        for(int i = 1; i <= MAX; i++){
            for(int j = 1; j <= MAX; j++){

                count = 0;
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

            count = 0;
            for(int j = 1; j <= MAX; j++){
                if(cube[i][j][plan] == 1){count++;}
            }
            cube[i][0][plan] = count;
        }

        //Colonnes
        for(int j = 1; j <= MAX; j++){

            count = 0;
            for(int i = 1; i <= MAX; i++){
                if(cube[i][j][plan] == 1){count++;}
            }
            cube[0][j][plan] = count;
        }

        //Régions
        for(int i = 1; i <= sqrt(MAX); i++){
            for(int j = 1; j <= sqrt(MAX); j++){
                count = 0;

                for(int m = 1; m <= sqrt(MAX); m++){
                    for(int n = 1; n <= sqrt(MAX); n++){
                        if(cube[(int)(m+sqrt(MAX)*(i-1))][(int)(n+sqrt(MAX)*(j-1))][plan]==1){count++;}

                    }
                }
                cube[MAX+1][j+3*(i-1)][plan] = count;

            }
        }

    }

}

//void createCube pour une grille existante ?
