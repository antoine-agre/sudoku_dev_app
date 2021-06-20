#include "Header.h"

int main(){
    rules();
    srand(time(NULL));
    Grid grid;
    Option option;
    int jouer=1, reponse=0, nbHint=3;
    while(jouer==1){
        options(option);
        //initializeGrid(grid,option);
        printf("\nGrilles disponibles : grille1, grille2, grille3\n");
        readGrid(grid);
        printGrid(grid);
        while(isGridComplete(grid)==false){
            if(option[2]==1 && nbHint>0){
                do{
                    reponse=0;
                    printf("Il te reste %d indice(s). Veux-tu un indice? (Regarde bien la grille avant de reponse)\nEntre 1 si tu en veux un et n'importe quel autre nombre sinon : ",nbHint);
                    scanf("%d",&reponse);
                    if(reponse==1){
                        nbHint=hint(grid,nbHint);
                        printf("\n");
                        printGrid(grid);
                    }
                }while(reponse==1 && nbHint>0);
            }
            if(option[1]==1){
                playWithDetection(grid);
                printGrid(grid);
            }
            else{
                play(grid);
                printGrid(grid);
            }
        }
        saveGrid(grid);
        do{
            printf("Veux-tu rejouer?\nEntre 1 si tu en veux rejouer et 0 sinon : ");
            scanf("%d",&jouer);
            if(jouer!=0 && jouer!=1){
                printf("Oups! La valeur n'est pas bonne. Entre 1 si tu veux rejouer et 0 sinon : ");
            }
        }while(jouer!=0 && jouer!=1);
    }
    return 0;
}
