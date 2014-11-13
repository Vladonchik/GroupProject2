//
//  Header.h
//  TEST
//
//  Created by Vlad Vyshnevskyy on 12/11/2014.
//  Copyright (c) 2014 VV-SD. All rights reserved.
//

#ifndef TEST_Header_h
#define TEST_Header_h
typedef struct enemy *enemy;
typedef struct tower *tower;

enemy getEnemy(int **path);
void freeEnemy(enemy e);
tower getTower();
void freeTower(tower t);
int **getPathArray(int rows, int columns);
void layPath(int **path);
int moveEnemy(enemy e, int **path);
void fire(tower t, enemy e);
int isDead(enemy e);
void printTower(tower t);
void printEnemy(enemy e);

#endif
