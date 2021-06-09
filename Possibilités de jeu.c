#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 9

typedef int Grid[MAX][MAX];

void rules(){
    printf("\nLe Sudoku\n");
    printf("Les règles sont les suivantes :\n");
    printf("Une seule fois le même nombre par ligne/colonne.\n");
    printf("Une seule fois le même nombre dans une sous-grille (tableau ayant un autre nombre de lignes/colonnes inférieur à celui de la grille).\n");
    printf("Notre jeu propose plusieurs options que tu pourra selectionner avant la partie.\n");
    printf("Normes de saisie du jeu :\n");
    printf("Lors de la selectin des options, ecris o pour l'avoir ou n pour la desactiver.\n");
    printf("Lors d'un coup, il faut écrire le numero de la ligne, puis le numero de la colonne et enfin le nombre que tu veux jouer.\n");
    printf("Bon courage!\n");
}

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
            printf("Ah mince, ce coup n'est pas possible. Mais ne t'en fais pas tu n'as qu'a reessayer!");
        }
        else{
            grid[x-1][y-1]=n;
        }
    }
}

void play(Grid grid){
  //Fait jouer le joueur sur une case vide.
    int x,y,n;
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
    grid[x-1][y-1]=n;

}

int hint(grid,nb_hint){
    //Donne (avec demande préalable) un indice.
    randomGenerate(grid,1);
    printf("Voila une petite aide. Ne t'inquiete pas cela restera entre nous.");
    printGrid(grid);
    return nb_hint-1;
}
