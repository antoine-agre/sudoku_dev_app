#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 4                  //dimension de la grille
#define nbOption 4              //nombre d'options existantes dans notre programme  (possible de faire un tableau qui enregistre si les option sont selectionnées ou non ex : premiere case = 0 donc l'option n'est pas selectionnées)

typedef int Grid[MAX][MAX];
typedef int Cube[MAX+2][MAX+1][MAX+1];

int main(){
    srand(time(NULL));           //mise en place de l'aléatoire
    Grid grid;                  //Création de la grille
    fillZero(grid);             //initialisation avec des zeros
    randomGenerate(grid,4);    //remplissage de la grille
    printGrid(grid);            //Affichage de la grille
    //play(grid);
    //printGrid(grid);

    Cube cube;
    //initCube(cube);
    //printCube(cube);
    //updateCube(cube, 7, 7, 9);
    //printCube(cube);
    generateCube(cube, grid);
    printCube(cube);
    //saveGrid(grid);
    //Selection des options
    //boucle qui pour chaque itération fait jouer un coup au joueur et applique les options selectionnés précédement

    return 0;
}
