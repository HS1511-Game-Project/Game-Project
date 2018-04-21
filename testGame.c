// Created by [insert names here]
// This program aims to test the game and see if it is valid.

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

#define BOARD_SIZE 100
#define CAMPUS 1
int main(/* Add argv stuff here */) {
  // TEST 1 // buildCampus, getTileInfo
  char * newBoard[BOARD_SIZE] = setBoardUp();
  newBoard = buildCampus("lr");
  assert(getTileInfo("lr", newBoard) == CAMPUS);
  // TEST 2 // 
  
}
