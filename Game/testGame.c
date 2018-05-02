
// Created by Harris Borman, Djimon Jayasundera, and Zachary Chengy
// This program aims to test the game and see if it is valid.

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

int main(/* Add argv stuff here */) {
  
  // TEST 1 // getWhoseTurn and makeAction - Djimon
  printf("Testing getWhoseTurn and makeAction.");
  Game newBoard = newGame(DEFAULT_DISCIPLINES, DEFAULT_DICE);
  playerID = getWhoseTurn(newBoard);
  makeAction(newBoard, NEXT_TURN); // MUST BE DEFINED IN GAME.H TO BE A NUMBER FOR THE FUNCTION
  assert(playerID != getWhoseTurn(newBoard)); // Check that it is now a different person's turn.
  
  // TEST 2 //  isLegalAction, board coordinates - Zac
  printf("Testing isLegalAction and board coordinates.");
  newBoard = newGame(DEFAULT_DISCIPLINES, DEFAULT_DICE);
  // Supposed to be false ( out of the board )
  assert(isLegalAction(newBoard,path "llll") == 0);
  assert(isLegalAction(newBoard,path "rrrr") == 0);
  
  assert(isLegalAction(newBoard,path "lrlrlrlrlr") == 1);
  assert(isLegalAction(newBoard,path "rlrlrlrlrl") == 1);
  
  assert(isLegalAction(newBoard,path "llrlrrrr") == 1);
  assert(isLegalAction(newBoard,path "rrlrllll") == 1);
  
  printf("Testing Passed!");
  
  // TEST 3 // getCampuses - Djimon
  printf("Testing getCampuses.");
  newBoard = newGame(DEFAULT_DISCIPLINES, DEFAULT_DICE);
  assert(getCampuses(newBoard, 1) == 0); // Make sure that player 1 has no campuses to start with.
  assert(getCampuses(newBoard, 2) == 0);
  assert(getCampuses(newBoard, 3) == 0);
  printf("Testing Passed!");
  
  
  // DONE
  printf("All Tests Passed!\nYou Are AWESOME!!!");

}
