#include "Header.h"

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

void printGrid(Grid grid){
    /**Affiche la grille en interface graphique*/
    int car = 0, separateur = 0;
    //Coordonnées
    for(int i = 1; i <= MAX; i++){
        if(i > 10){printf("C%d ", i);}
        else{printf(" C%d ", i);}
    }
    printf("\n");
    //Première ligne
    printf("%c",B_UPPER_LEFT);
    for(int i = 0; i < sqrt(MAX); i++){
        for(int j = 0; j < 4*sqrt(MAX)-1; j++){
            printf("%c", B_HORIZONTAL);
        }
        if(i < sqrt(MAX)-1){printf("%c",B_T_LOW);}
    }
    printf("%c\n", B_UPPER_RIGHT);
    //Boucle centrale
    for(int i = 0; i < MAX-1; i++){
        //ligne chiffres
        printf("%c", B_VERTICAL);
        for(int j = 0; j < MAX; j++){
            if(j%(int)sqrt(MAX) == sqrt(MAX)-1){separateur = B_VERTICAL;}
            else{separateur = VERTICAL;}
            printf(" %c %c", intToChar(grid[i][j]), separateur);
        }
        printf(" L%d\n", i+1);
        //ligne séparateurs
        printf("%c",B_VERTICAL);
        if(i%(int)sqrt(MAX) == sqrt(MAX)-1){car = B_HORIZONTAL; separateur = B_HORIZONTAL;}
        else{car = HORIZONTAL; separateur = CROSS;}
        for(int j = 0; j < sqrt(MAX); j++){
            for(int k = 0; k < sqrt(MAX) - 1; k++){
                printf("%c%c%c%c", car, car, car, separateur);
            }
            printf("%c%c%c%c", car, car, car, B_VERTICAL);
        }
        printf("\n");
    }
    //Dernière ligne
    printf("%c", B_VERTICAL);
    for(int j = 0; j < MAX; j++){
        if(j%(int)sqrt(MAX) == sqrt(MAX)-1){separateur = B_VERTICAL;}
        else{separateur = VERTICAL;}
        printf(" %c %c", intToChar(grid[MAX-1][j]), separateur);
    }
    printf(" L%d\n", MAX);
    printf("%c",B_LOWER_LEFT);
    for(int i = 0; i < sqrt(MAX); i++){
        for(int j = 0; j < 4*sqrt(MAX)-1; j++){
            printf("%c", B_HORIZONTAL);
        }
        if(i < sqrt(MAX)-1){printf("%c",B_T_UP);}
    }
    printf("%c\n", B_LOWER_RIGHT);
}

void fillZero(Grid grid){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            grid[i][j] = 0;
            //printf("%d %d : %d\n", i, j, grid[i][j]);
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
    int count = 0, x, y, candidate;
    //r = rand();
    while(count <nbClues){
        //printf("Nombre numero : %d\n", count+1);
        //srand(rand());
        x = rand()%MAX;
        y = rand()%MAX;
        if(grid[x][y] == 0){
            candidate = rand()%MAX + 1;
            //printf("Position  : %d %d ; candidat : %d\n", x, y, candidate);
            if(isValidMove(grid, x, y, candidate)==true){grid[x][y] = candidate; count++; /*printf("valide\n");*/}
            //else {printf("non valide\n");}
        }
    }
}

int intToChar(int input){
    if(input == 0){return 32;}
    else if(input <= 9){return 48 + input;}
    else{return 55 + input;}
}

void initializeGrid(Grid grid, Option option){
    fillZero(grid);
    if(option[0]<0 || option[0]>4){ //sécurité
        printf("Une erreur est survenue. Il semblerai qu'aucune difficulte n'est ete selectionnee. Pourrai-tu en selectionner une?\n1: facile 2: normale 3: difficile 4: demoniaque : ");
        do{
            scanf("%d",&option[0]);
            if(option[0]<0 || option[0]>4){
                printf("Oups! La valeur n'est pas bonne. Selectionne ta difficulte\n1: facile 2: normale 3: difficile 4: demoniaque : ");
            }
        }while(option[0]<0 || option[0]>4);
    }
    if(option[0]==1){
        randomGenerate(grid,35);
    }
    if(option[0]==2){
        randomGenerate(grid,30);
    }
    if(option[0]==3){
        randomGenerate(grid,27);
    }
    if(option[0]==4){
        randomGenerate(grid,25);
    }
}
