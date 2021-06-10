#include "Header.h"

void rules(){
    printf("\nLe Sudoku\n");
    printf("Les regles sont les suivantes :\n");
    printf("Une seule fois le meme nombre par ligne/colonne.\n");
    printf("Une seule fois le meme nombre dans une sous-grille (tableau ayant un autre nombre de lignes/colonnes inferieur a celui de la grille).\n");
    printf("Notre jeu propose plusieurs options que tu pourra selectionner avant la partie.\n");
    printf("Normes de saisie du jeu :\n");
    printf("Lors de la selectin des options, ecris 'o' pour l'avoir ou 'n' pour la desactiver.\n");
    printf("Lors d'un coup, il faut ecrire le numero de la ligne, puis le numero de la colonne et enfin le nombre que tu veux jouer.\n");
    printf("Bon courage!\n");
}

void playWithDetection(Grid grid){
  //Cette fonction permet de jouer en regardant si le coup est jouable ou non.
    int x,y,n;
    bool possible=false;
    while(possible==false){
        do{
            printf("\nEntre les coordonnees de la case que tu veux jouer (compris entre 1 et %d)\n",MAX);
            printf("ligne / colonne : ");
            scanf("%d%d",&x,&y);
            if(x<1 || x>MAX){
                printf("Oups! La ligne n'existe pas... Essaye en une autre.");
            }
            else if(y<1 || y>MAX){
                printf("Oups! La colonne n'existe pas... Essaye en une autre.");
            }
            else if(grid[x-1][y-1]!=0){
                printf("Cette case est deja remplie. Essaye en une autre");
            }
        }while(grid[x-1][y-1]!=0 || x<1 || x>MAX || y<1 || y>MAX);
        do{
            printf("\nEntre le nombre que tu veux jouer dans la case (%d,%d) (compris entre 1 et %d) : ",x,y,MAX);
            scanf("%d",&n);
            if(n<1 || n>MAX){
                printf("Malheureusement ce nombre ne convient pas a ce type de grille. Choisis en un autre.");
            }
        }while(n<1 || n>MAX);
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
        printf("ligne / colonne : ");
        scanf("%d%d",&x,&y);
        if(x<1 || x>MAX){
            printf("Oups! La ligne n'existe pas... Essaye en une autre.");
        }
        else if(y<1 || y>MAX){
            printf("Oups! La colonne n'existe pas... Essaye en une autre.");
        }
        else if(grid[x-1][y-1]!=0){
            printf("Cette case est deja remplie. Essaye en une autre");
        }
    }while(grid[x-1][y-1]!=0 || x<1 || x>MAX || y<1 || y>MAX);
    do{
        printf("\nEntre le nombre que tu veux jouer dans la case (%d,%d) (compris entre 1 et %d) : ",x,y,MAX);
        scanf("%d",&n);
        if(n<1 || n>MAX){
            printf("Malheureusement ce nombre ne convient pas a ce type de grille. Choisis en un autre.");
        }
    }while(n<1 || n>MAX);
    grid[x-1][y-1]=n;

}

int hint(Grid grid,int nb_hint){
    //Donne (avec demande préalable) un indice.
    randomGenerate(grid,1);
    printf("Voila une petite aide. Ne t'inquiete pas cela restera entre nous.");
    printGrid(grid);
    return nb_hint-1;
}
