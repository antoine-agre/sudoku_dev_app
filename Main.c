#include "Header.h"

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
