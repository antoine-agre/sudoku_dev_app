#include <stdio.h>
#include <stdlib.h>
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

void afficherGrille(Grid grille){

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
