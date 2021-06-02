#include <stdio.h>
#include <stdlib.h>
#define MAX 9

typedef int Grid[MAX][MAX];

int main(){
srand(time(NULL));
Grid grid;
fillZero(grid);
randomGenerate(grid,35);
printGrid(grid);
return 0;
}
