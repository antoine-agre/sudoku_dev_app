#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX 9
#define B_UPPER_LEFT 201
#define B_UPPER_RIGHT 187
#define B_LOWER_LEFT 200
#define B_LOWER_RIGHT 188
#define B_HORIZONTAL 205
#define B_VERTICAL 186
#define B_CROSS 206
#define B_T_LOW 203
#define B_T_UP 202
#define B_T_LEFT 185
#define B_T_RIGHT 204
#define UPPER_LEFT 218
#define UPPER_RIGHT 191
#define LOWER_LEFT 192
#define LOWER_RIGHT 217
#define HORIZONTAL 196
#define VERTICAL 179
#define CROSS 197

typedef int Grid[MAX][MAX];

void compareGrid(Grid grid1, Grid grid2){
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

void printGrid(Grid grille){

    printf("\n\n");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", B_UPPER_LEFT, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL,
           B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_T_LOW,
           B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL,
           B_HORIZONTAL, B_HORIZONTAL, B_T_LOW, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL,
           B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_UPPER_RIGHT);

    for (int i = 0; i < MAX; i++){

        printf("%c",B_VERTICAL);

        for(int j = 0; j < MAX; j++){


            if(grille[i][j] == 0){printf("   ");}
            else {printf(" %d ", grille[i][j]);}

            if(j%3==2){printf("%c",B_VERTICAL);}//thick or not
            else {printf("%c", VERTICAL);}


        }

        if(i == 8){
            printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", B_LOWER_LEFT, B_HORIZONTAL, B_HORIZONTAL,
                   B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL,
                   B_HORIZONTAL, B_T_UP, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL,
                   B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL,
                   B_HORIZONTAL, B_T_UP, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL,
                   B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_LOWER_RIGHT);
        }

        else{

            printf("\n");

            if(! (i == 2 || i == 5)) {
                printf("%c", B_VERTICAL);
                for(int k = 0; k < 3; k++){//3 fois
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c", HORIZONTAL, HORIZONTAL, HORIZONTAL, CROSS, HORIZONTAL, HORIZONTAL, HORIZONTAL, CROSS,
                           HORIZONTAL, HORIZONTAL, HORIZONTAL, B_VERTICAL);
                }
            }

            else{
                printf("%c", B_T_RIGHT);
                for(int k = 0; k < 3; k++){//3 fois
                    printf("%c%c%c%c%c%c%c%c%c%c%c", B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL,
                           B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL, B_HORIZONTAL);
                    if(k == 2){printf("%c", B_T_LEFT);}
                    else{printf("%c",B_CROSS);}
                }
            }
            printf("\n");
        }
    }

}

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
