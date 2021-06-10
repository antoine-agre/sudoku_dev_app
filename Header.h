#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#define MAX 9
#define nb_option 3
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

void compareGrid(Grid grid1, Grid grid2);
void printGrid(Grid grid);
void fillZero(Grid grid);
bool isValidMove(Grid grid, int x, int y, int n);
void randomGenerate(Grid grid, int nbClues);
int intToChar(int input);
void rules();
void playWithDetection(Grid grid);
void play(Grid grid);
int hint(Grid grid,int nb_hint);
