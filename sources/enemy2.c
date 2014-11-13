#include <stdio.h>
#include <stdlib.h>


#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 300

typedef struct tower *tower;

typedef struct enemy {
  int x, y;
  int pathProgress;
  int health;
  int speed;
} *enemy;



enemy getEnemy(int **path) {
  enemy e = malloc(sizeof(*e));
  e->pathProgress = 0;
  e->x = path[0][0];
  e->y = path[0][1];
  e->health = 100;
  e->speed = 4;
  
  return e;
}

void freeEnemy(enemy e) {
  free(e);
}

int moveEnemy(enemy e, int **path) {
  
  if(e->x < SCREEN_WIDTH - e->speed) {
    e->pathProgress += e->speed;
    e->x = path[e->pathProgress][0];
    e->y = path[e->pathProgress][1];
    return 0;
  }
  return 1;
}

int isDead(enemy e) {
  if(e->health <= 0) {
    return 1;
  } else {
    return 0;
  }
}


int inRange(int tX, int tY, int tRange, enemy en) {
  
  if(en->x >= tX - tRange && en->x <= tX + tRange){
    if(en->y >= tY-tRange && en->y <= tY + tRange) {
      return 1;
    }
  }
  else {
    return 0;
  }

  return 2;
}

void damageEnemy(int damage, enemy e) {

  e->health -= damage;
}


void getTarget(int *towerTarget, enemy e) {

  towerTarget[0] = e->x;
  towerTarget[1] = e->y;
  
}

void printEnemy(enemy e) {

  printf("Enemy x = %d, enemy y = %d, enemy health = %d\n\n", e->x, e->y, e->health);

}







































