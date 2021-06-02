#include <stdio.h>
#include <stdlib.h>
#define MAX 9

typedef int Grid[MAX][MAX];

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
