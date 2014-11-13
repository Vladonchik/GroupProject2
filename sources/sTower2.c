#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 300

#include "./../includes/tower.h"



int main (void) {
  int **path;
  path = getPathArray(SCREEN_WIDTH, 2);
  layPath(path);
  
  
  enemy creep;
  creep = getEnemy(path);
  
  tower tower1;
  tower1 = getTower();
  
  while(moveEnemy(creep, path) != 1 && isDead(creep) != 1){
    fire(tower1, creep);
    printTower(tower1);
    printEnemy(creep);
  }
  
  if(isDead(creep)) {
    printf("Enemy died\n");
  }
  else {
    printf("Game over\n");
  }
  
  freeEnemy(creep);
  freeTower(tower1);
  
  
  return 0;
}



int **getPathArray(int rows, int columns) {

  int **array = (int **)malloc(sizeof(int *) * rows);
  
  for(int i = 0; i < rows; i++) {
    array[i] = (int *)malloc(sizeof(int) * columns);
  }
  
  return array;
}

void layPath(int **path) {
  for(int i = 0; i < SCREEN_WIDTH; i++) {
    path[i][0] = i;
    path[i][1] = SCREEN_HEIGHT/2;
  }
}

  

