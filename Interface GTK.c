#include "Header.h"

typedef int Grid[MAX][MAX];
FILE* fichier = NULL;

static int grid[9][9];
static GtkWidget *wid [9][9] , *window;
bool to_show;



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
    while(count <nbClues){
        x = rand()%MAX;
        y = rand()%MAX;
        if(grid[x][y] == 0){
            candidate = rand()%MAX + 1;
            if(isValidMove(grid, x, y, candidate)==true){grid[x][y] = candidate; count++; }
        }
    }
}

 int main(int argc, char* argv[])
    {
        Grid grille;
        randomGenerate(grille, 35);
        gtk_init(&argc,&argv);

        GtkWidget *vbox , *hbox , *separator , *button , *toggle , *file_menu , *menu_bar , *menu_item;
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);

        vbox = gtk_vbox_new(0,0);

        for ( int i = 0 ; i < 9 ; i++ )
        {
            hbox = gtk_hbox_new(0,0);

            for ( int j = 0 ; j < 9 ; j++ )
            {
                wid[i][j] = gtk_entry_new();
                gtk_entry_set_max_length(GTK_ENTRY(wid[i][j]),1);
                gtk_widget_set_size_request(wid[i][j],50,50);
                gtk_box_pack_start(GTK_BOX(hbox),wid[i][j],1,1,0);

                if ( (j+1)%3 == 0 )
                {
                    separator = gtk_vseparator_new();
                    gtk_box_pack_start(GTK_BOX(hbox),separator,1,1,0);
                    separator = gtk_vseparator_new();
                    gtk_box_pack_start(GTK_BOX(hbox),separator,1,1,0);
                }

            }

            gtk_box_pack_start(GTK_BOX(vbox),hbox,1,1,0);

            if ( (+1)%3 == 0 )
            {
                separator = gtk_hseparator_new();
                gtk_box_pack_start(GTK_BOX(vbox),separator,1,1,0);
                separator = gtk_hseparator_new();
                gtk_box_pack_start(GTK_BOX(vbox),separator,1,1,0);
            }
        }

        gtk_box_pack_start(GTK_BOX(vbox),hbox,0,0,0);

        gtk_container_add(GTK_CONTAINER(window),vbox);

        gtk_window_set_title(GTK_WINDOW(window),"Solver Sudoku");

        gtk_widget_show_all(window);

        gtk_main();

        return 0;
    }
