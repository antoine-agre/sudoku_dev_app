#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include <stdbool.h>
#define MAX 9

typedef int Grid[MAX][MAX];

void fillZero(Grid grid){

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            grid[i][j] = 0;
        }
    }

}


bool isValidMove(Grid grid, int x, int y, int n){
    //il faut des nombre avec une racine carré parfaite
    //Vérifie si colonne + ligne + carré de la case x y ne contiennent jamais l'entier n (y compris case x y)

    for(int i = 0; i < MAX; i++){ //ligne
        if(grid[x][i] == n){return false;}
    }

    for(int i = 0; i < MAX; i++){//colonne
        if(grid[i][y] == n){return false;}
    }

    // k et l : décalage ligne/colonne
    int k,l;

    if(x >= 0 && x < sqrt(MAX)){k = 0;}
    else if(x >= sqrt(MAX) && x < 2*sqrt(MAX)){k = sqrt(MAX);}
    else if(x >= 2*sqrt(MAX) && x < MAX){k = 2*sqrt(MAX);}
    if(y >= 0 && y < sqrt(MAX)){l = 0;}
    else if(y >= sqrt(MAX) && y < 2*sqrt(MAX)){l = sqrt(MAX);}
    else if(y >= 2*sqrt(MAX) && y < MAX){l = 2*sqrt(MAX);}

    for(int i = 0; i <sqrt(MAX); i++){
        for(int j = 0; j <sqrt(MAX); j++){
            if(grid[i+k][j+l] == n){return false;}
        }
    }

    return true;

}

void randomGenerate(Grid grid, int nbClues){

    int count = 0, x, y, candidate, *current;
    bool ok;

    //r = rand();
    while(count <nbClues){
        printf("Nombre numero : %d\n", count+1);

        //srand(rand());
        x = rand()%MAX;
        y = rand()%MAX;
        //*current = &grid[x][y];
        printf("Position aleatoire : %d %d ; nombre dans cette case : %d\n", x, y, grid[x][y]/*current*/);

        if(/*current == 0*/grid[x][y] == 0){

            ok = false;
            while (ok!=true){
                candidate = rand()%MAX + 1;
                printf("Position %d %d, candidat %d\n", x, y, candidate);
                if(isValidMove(grid, x, y, candidate)==true){grid[x][y] = candidate; /*current = candidate;*/ ok = true; printf("valide\n");}
                else {printf("non valide\n");}
            }
            count++;
        }
    }
}
