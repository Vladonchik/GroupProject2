#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 300

typedef struct enemy *enemy;

int inRange(int tX, int tY, int tRange, enemy en);
void damageEnemy(int damage, enemy e);
void *getTarget(int * towerTarget, enemy e);

typedef struct tower {
  int x, y;
  int damage;
  int range;
  int firing;
  int target[2];
} *tower;

tower getTower() {
  
  tower t = malloc(sizeof(*t));
  
  t->x = SCREEN_WIDTH/2;
  t->y = (SCREEN_HEIGHT/2)+10;
  t->damage = 10;
  t->range = 10;
  t->firing = 0;
  
  return t;
}
  

void freeTower(tower t) {
  free(t);
}

void fire(tower t, enemy e) {
  
  if(inRange(t->x, t->y, t->range, e) == 1) {
      t->firing = 1;
      getTarget(&t->target[0], e);
      damageEnemy (t->damage, e);
  } else {
      t->firing = 0;
  }
}


void printTower(tower t) {

  printf("tower x = %d, tower y = %d, tower firing = %d", t->x, t->y, t->firing);
  if(t->firing) {
    printf(" Tower firing coords x = %d, tower firing coords y = %d ", t->target[0], t->target[1]);
  } else {
    printf(" ");
  }
}


