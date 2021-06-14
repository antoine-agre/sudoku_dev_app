#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 9                  //dimension de la grille
#define nbOption 4              //nombre d'options existantes dans notre programme  (possible de faire un tableau qui enregistre si les option sont selectionnées ou non ex : premiere case = 0 donc l'option n'est pas selectionnées)

typedef int Grid[MAX][MAX];
typedef int Cube[MAX+2][MAX+1][MAX+1];

int main(){
    srand(time(NULL));           //mise en place de l'aléatoire
    Grid grid;                  //Création de la grille
    fillZero(grid);             //initialisation avec des zeros
    //randomGenerate(grid,25);    //remplissage de la grille
    //printGrid(grid);            //Affichage de la grille

    //play(grid);
    //printGrid(grid);

    //char name[30];
    //strcat(name, "read");
    //readGrid(grid, name);
    //printGrid(grid);

    grid[0][1] = 7;
    grid[0][8] = 9;
    grid[1][0] = 5;
    grid[1][1] = 1;
    grid[1][3] = 4;
    grid[1][4] = 2;
    grid[1][6] = 6;
    grid[2][1] = 8;
    grid[2][3] = 3;
    grid[2][6] = 7;
    grid[3][2] = 8;
    grid[3][5] = 1;
    grid[3][6] = 3;
    grid[3][7] = 7;
    grid[4][1] = 2;
    grid[4][2] = 3;
    grid[4][4] = 8;
    grid[4][7] = 4;
    grid[5][0] = 4;
    grid[5][3] = 9;
    grid[5][6] = 1;
    grid[6][0] = 9;
    grid[6][1] = 6;
    grid[6][2] = 2;
    grid[6][3] = 8;
    grid[6][7] = 3;
    grid[7][4] = 1;
    grid[7][6] = 4;
    grid[8][0] = 7;
    grid[8][3] = 2;
    grid[8][5] = 3;
    grid[8][7] = 9;
    grid[8][8] = 6;
    printGrid(grid);


    Cube cube;
    generateCube(cube, grid);
    //printCube(cube);
    solveCube(grid);
    //updateCube(cube, )
    //generateCube(cube, grid);
    //printCube()
    //solveCube(grid);
    //Cube cube;
    //initCube(cube);
    //printCube(cube);
    //updateCube(cube, 7, 7, 9);
    //printCube(cube);
    //generateCube(cube, grid);
    //printCube(cube);
    //saveGrid(grid);
    //Selection des options
    //boucle qui pour chaque itération fait jouer un coup au joueur et applique les options selectionnés précédement

    return 0;
}
