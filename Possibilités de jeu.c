#include <stdio.h>
#include <stdlib.h>
#define MAX 9

typedef int Grid[MAX][MAX];

void playWithDetection(Grid grid){
  //Cette fonction permet de jouer en regardant si le coup est jouable ou non.
    int x,y,n;
    bool possible=false;
    while(possible==false){
        do{
            printf("\nEntre les coordonnees de la case que tu veux jouer (compris entre 1 et %d)\n",MAX);
            printf("ligne : ");
            scanf("%d",&x);
            printf("colonne : ");
            scanf("%d",&y);
            if(grid[x-1][y-1]!=0){
                printf("Cette case est deja remplie. Essaye une autre");
            }
        }while(grid[x-1][y-1]!=0);
        printf("Entre le nombre que tu veux jouer (compris entre 1 et %d) : ",MAX);
        scanf("%d",&n);
        possible=isValidMove(grid,x-1,y-1,n);
        if(possible==false){
            printf("Ah mince, ce n'est coup n'est pas possible. Mais ne t'en fais pas tu n'as qu'a reessayer!");
        }
        else{
            grid[x-1][y-1]=n;
        }
    }
}


//Pour la fonction qui place un nombre aléatoire sur la grille, on utilise la fonction randomGenerate avec un bnClues=1

//Pour la fonction de détection d'erreur à chaque tout, on utilise la fonction isValidMove
