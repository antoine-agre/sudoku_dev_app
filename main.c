#include <stdio.h>
#include <stdlib.h>
#define MAX 9                   //dimension de la grille
#define nbOption 4              //nombre d'options existantes dans notre programme  (possible de faire un tableau qui enregistre si les option sont selectionnées ou non ex : premiere case = 0 donc l'option n'est pas selectionnées)

typedef int Grid[MAX][MAX];

int main(){
    srand(time(NULL));           //mise en place de l'aléatoire
    Grid grid;                  //Création de la grille
    fillZero(grid);             //initialisation avec des zeros
    randomGenerate(grid,35);    //rempliçage de la grille
    printGrid(grid);            //Affichage de la grille
    //saveGrid(grid);
    //Selection des options
    //boucle qui pour chaque itération fait jouer un coup au joueur et applique les options selectionnés précédement
    return 0;
}
