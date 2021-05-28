#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef int Grid[9][9];

void afficherGrille(Grid grille){

    printf("\n\n");
    for (int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(grille[i][j] == 0){printf(".\t");}
            else {printf("%d\t", grille[i][j]);}
        }
        printf("\n\n");
    }

}

bool isValidMove(Grid grille, int x, int y, int n){
    //Vérifie si colonne + ligne + carré de la case x y ne contiennent jamais l'entier n (y compris case x y)

    for(int i = 0; i < 9; i++){ //ligne
        if(grille[x][i] == n){return false;}
    }

    for(int i = 0; i < 9; i++){
        if(grille[i][y] == n){return false;}
    }

    //k/l : décalage ligne/colonne
    int k,l;

    if(x >= 0 && x <= 2){k = 0;}
    else if(x >= 3 && x <= 5){k = 3;}
    else if(x >= 6 && x <= 8){k = 6;}
    if(y >= 0 && y <= 2){l = 0;}
    else if(y >= 3 && y <= 5){l = 3;}
    else if(y >= 6 && y <= 8){l = 6;}

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grille[i+k][j+l] == n){return false;}
        }
    }

    return true;

}

void fillZero(Grid grille){

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            grille[i][j] = 0;
        }
    }

}

void randomGenerate(Grid grille, int nbClues){

    int count = 0, x, y, candidate, *current;
    bool ok;

    //r = rand();
    while(count < nbClues){
        printf("count : %d\n", count);

        //srand(rand());
        x = rand()%9;
        y = rand()%9;
        printf("zboub");
        //*current = &grille[x][y];
        printf("pos random : %d %d ; grille à cet emplacement : %d\n", x, y, grille[x][y]/*current*/);

        if(/*current == 0*/grille[x][y] == 0){

            ok = false;
            while (!ok){
                candidate = rand()%9 + 1;
                printf("Position %d %d, candidat %d\n", x, y, candidate);
                if(isValidMove(grille, x, y, candidate)){grille[x][y] = candidate; /*current = candidate;*/ ok = true; printf("valide\n");}
                else {printf("non valide\n");}
            }
            count++;
        }
    }
}

int main()
{
    srand(time(NULL));//seed aléatoire
    Grid test;

    /*for (int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            test[i][j] = 18;
        }
    }

    int *current = &test[rand()%9][rand()%9];
    printf("truc hasard : %d\n", *current);

    afficherGrille(test);
    *current = 14;
    afficherGrille(test);*/

    fillZero(test);
    afficherGrille(test);
    randomGenerate(test, 35);
    afficherGrille(test);

    /*test[1][1] = 8;
    afficherGrille(test);

    int *z = &test[1][1];
    printf("grille : %d \npointeur : %d \n", test[1][1], *z);
    test[2][2] = 5;
    afficherGrille(test);
    *z = 9;
    afficherGrille(test);*/

    return 0;
}
