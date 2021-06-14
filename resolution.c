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

    for(int i = 1; i <= MAX; i++){
        cube[l][i][x] = 0;//0 sur ligne
        //printf("ligne : %d - %d %d : 0\n",x, l, i);
        cube[i][c][x] = 0;//0 sur colonne
        //printf("colonne : %d - %d %d : 0\n",x, i, c);
        cube[l][c][i] = 0;//0 sur "colonne" plan
        //printf("col plan : %d - %d %d : 0\n",i, l, c);
    }

    //Régions

    //origine régions
    int u = (int)(sqrt(MAX));
    int ox = 1 + u * ((l - 1)/u);
    int oy = 1 + u * ((c - 1)/u);

    for(int m = 0; m < u; m++){
        for(int n = 0; n < u; n++){
            cube[ox+m][oy+n][x] = 0;

        }
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

        int u = (int)(sqrt(MAX));
        int xr, yr, ox, oy, count;


        for(int r = 1; r <= MAX; r++){//région r
            xr = 1 + ((r-1)/u);//id région
            yr = 1 + ((r-1)%u);
            ox = 1 + ((xr-1)*u);//origine région
            oy = 1 + ((yr-1)*u);
            count = 0;
            for(int m = 0; m < u; m++){
                for(int n = 0; n < u; n++){
                    if(cube[ox + m][oy + n][plan] == 1){count++;}
                }
            }
            cube[MAX+1][r][plan] = count;

        }
    }
}

void solveCube(Grid grid){
//Tente de résoudre la grille avec un cube

    Cube cube;
    generateCube(cube, grid);
    //printCube(cube);//

    if(stepSolveCube(grid, cube) == 1){
        printf("\nOn a resolu\n");
        printGrid(grid);
    }
    else{
        printf("\nPAS SOLVABLE AVEC CUBE\n");
        printGrid(grid);
    }

}

int stepSolveCube(Grid grid, Cube cube){
//Fonction récursive, essaie de trouver un chiffre à remplir et, si elle réussit, se rappelle.
//Retourne 1 si la grille est complète, 0 si on n'arrive pas à continuer

    //Vérifie compteurs
    //Plan 0
    for(int i = 1; i <= MAX; i++){
        for(int j = 1; j <= MAX; j++){

            if(cube[i][j][0] == 1){
                for(int k = 1; k <= MAX; k++){

                    if(cube[i][j][k] == 1){//On a trouvé un chiffre à remplir
                        //printf("plan 0 : %d %d %d\n", i, j, k);//
                        grid[i-1][j-1] = k;
                        //printGrid(grid);//
                        updateCube(cube, i, j, k);
                        //printCube(cube);//
                        if(isGridComplete(grid)){return 1;}
                        else{return stepSolveCube(grid, cube);}
                    }

                }
            }

        }
    }

    //Lignes
    for(int i = 1; i <= MAX; i++){
        for(int k = 1; k <= MAX; k++){

            if(cube[i][0][k] == 1){
                for(int j = 1; j <= MAX; j++){

                    if(cube[i][j][k] == 1){
                        //printf("ligne : %d %d %d\n", i, j, k);//
                        grid[i-1][j-1] = k;
                        //printGrid(grid);//
                        updateCube(cube, i, j, k);
                        //printCube(cube);//
                        if(isGridComplete(grid)){return 1;}
                        else{return stepSolveCube(grid, cube);}
                    }

                }
            }

        }
    }

    //Colonnes
    for(int j = 1; j <= MAX; j++){
        for(int k = 1; k <= MAX; k++){

            if(cube[0][j][k] == 1){
                for(int i = 1; i <= MAX; i++){

                    if(cube[i][j][k] == 1){
                        //printf("colonne : %d %d %d\n", i, j, k);//
                        grid[i-1][j-1] = k;
                        //printGrid(grid);//
                        updateCube(cube, i, j, k);
                        //printCube(cube);//
                        if(isGridComplete(grid)){return 1;}
                        else{return stepSolveCube(grid, cube);}
                    }

                }
            }

        }
    }

    //Régions
    for(int j = 1; j <= MAX; j++){
        for(int k = 1; k <= MAX; k++){

            if(cube[MAX+1][j][k] == 1){
                for(int i = 1; i <= MAX; i++){

                    for(int m = 1; m <= sqrt(MAX); m++){
                        for(int n = 1; n <= sqrt(MAX); n++){
                            if(cube[(int)(m+sqrt(MAX)*(i-1))][(int)(n+sqrt(MAX)*(j-1))][k] == 1){
                                printf("region : %d %d %d\n", i, j, k);//
                                grid[i-1][j-1] = k;
                                //printGrid(grid);//
                                updateCube(cube, i, j, k);
                                //printCube(cube);//
                                if(isGridComplete(grid)){return 1;}
                                else{return stepSolveCube(grid, cube);}
                            }

                        }
                    }

                }
            }

        }
    }

    //On n'a rien trouvé
    return 0;

}
