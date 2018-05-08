
// Created by Harris Borman, Djimon Jayasundera, and Zachary Chengy
// This program aims to test the game and see if it is valid.

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

int main(/* Add argv stuff here */) {
  
  // TEST 1 // getWhoseTurn,cnewGame and makeAction - Djimon
  printf("Testing getWhoseTurn, newGame and makeAction.\n");
  Game newBoard = newGame(DEFAULT_DISCIPLINES, DEFAULT_DICE);
  playerID = getWhoseTurn(newBoard);
  makeAction(newBoard, NEXT_TURN); // MUST BE DEFINED IN GAME.H TO BE A NUMBER FOR THE FUNCTION
  assert(playerID != getWhoseTurn(newBoard)); // Check that it is now a different person's turn.
  
  // TEST 2 //  isLegalAction, board coordinates - Zac
  printf("Testing isLegalAction and board coordinates.\n");
  newBoard = newGame(DEFAULT_DISCIPLINES, DEFAULT_DICE);
  // Supposed to be false ( out of the board )
  assert(isLegalAction(newBoard,path "llll") == 0);
  assert(isLegalAction(newBoard,path "rrrr") == 0);
  
  assert(isLegalAction(newBoard,path "lrlrlrlrlr") == 1);
  assert(isLegalAction(newBoard,path "rlrlrlrlrl") == 1);
  
  assert(isLegalAction(newBoard,path "llrlrrrr") == 1);
  assert(isLegalAction(newBoard,path "rrlrllll") == 1);
  
  // TEST 3 // getCampuses - Djimon
  printf("Testing getCampuses.\n");
  newBoard = newGame(DEFAULT_DISCIPLINES, DEFAULT_DICE);
  assert(getCampuses(newBoard, 1) == 0); // Make sure that player 1 has no campuses to start with.
  assert(getCampuses(newBoard, 2) == 0);
  assert(getCampuses(newBoard, 3) == 0);
  
  // TEST 4 // getDiscipline
  Game newBoard = newGame(DEFAULT_DISCIPLINES, DEFAULT_DICE);
  printf ("Testing getDiscipline.");
  assert (getDiscipline (testGame, 0) == STUDENT_BQN);
  assert (getDiscipline (testGame, 1) == STUDENT_MMONEY);
  assert (getDiscipline (testGame, 2) == STUDENT_MJ);
  assert (getDiscipline (testGame, 3) == STUDENT_MMONEY);
  assert (getDiscipline (testGame, 4) == STUDENT_MJ);
  assert (getDiscipline (testGame, 5) == STUDENT_BPS);
  assert (getDiscipline (testGame, 6) == STUDENT_MTV);
  assert (getDiscipline (testGame, 7) == STUDENT_MTV);
  assert (getDiscipline (testGame, 8) == STUDENT_BPS);
  assert (getDiscipline (testGame, 9) == STUDENT_MTV);
  assert (getDiscipline (testGame, 10) == STUDENT_BQN);
  assert (getDiscipline (testGame, 11) == STUDENT_MJ);
  assert (getDiscipline (testGame, 12) == STUDENT_BQN);
  assert (getDiscipline (testGame, 13) == STUDENT_THD);
  assert (getDiscipline (testGame, 14) == STUDENT_MJ);
  assert (getDiscipline (testGame, 15) == STUDENT_MMONEY);
  assert (getDiscipline (testGame, 16) == STUDENT_MTV);
  assert (getDiscipline (testGame, 17) == STUDENT_BQN);
  assert (getDiscipline (testGame, 18) == STUDENT_BPS);
  
  // TEST 5 // getDiceValue
  printf ("Testing getDiceValue.\n");
  assert (getDiceValue (testGame, 0) == 9);
  assert (getDiceValue (testGame, 1) == 10);
  assert (getDiceValue (testGame, 2) == 8);
  assert (getDiceValue (testGame, 3) == 12);
  assert (getDiceValue (testGame, 4) == 6);
  assert (getDiceValue (testGame, 5) == 5);
  assert (getDiceValue (testGame, 6) == 3);
  assert (getDiceValue (testGame, 7) == 11);
  assert (getDiceValue (testGame, 8) == 3);
  assert (getDiceValue (testGame, 9) == 11);
  assert (getDiceValue (testGame, 10) == 4);
  assert (getDiceValue (testGame, 11) == 6);
  assert (getDiceValue (testGame, 12) == 4);
  assert (getDiceValue (testGame, 13) == 7);
  assert (getDiceValue (testGame, 14) == 9);
  assert (getDiceValue (testGame, 15) == 2);
  assert (getDiceValue (testGame, 16) == 8);
  assert (getDiceValue (testGame, 17) == 10);
  assert (getDiceValue (testGame, 18) == 5);
  
  // TEST 6 // getMostArcs
  printf ("Testing getMostARCs\n");
  assert (getMostARCs (testGame) == NO_ONE);

  printf ("Testing getMostPublications\n");
  assert (getMostPublications (testGame) == NO_ONE);
  
  printf ("Testing getTurnNumber\n");
  assert (getTurnNumber (testGame) == -1);

  printf ("Testing getWhoseTurn\n");
  assert (getWhoseTurn (testGame) == NO_ONE);

  printf ("Testing getKPIpoints\n");
  assert (getKPIpoints (testGame, UNI_A) == 0);
  assert (getKPIpoints (testGame, UNI_B) == 0);
  assert (getKPIpoints (testGame, UNI_C) == 0);

  printf ("Testing getARCs\n");
  assert (getARCs (testGame, UNI_A) == 0);
  assert (getARCs (testGame, UNI_B) == 0);
  assert (getARCs (testGame, UNI_C) == 0);

  printf ("Testing getGO8s\n");
  assert (getGO8s (testGame, UNI_A) == 0);
  assert (getGO8s (testGame, UNI_B) == 0);
  assert (getGO8s (testGame, UNI_C) == 0);
  
  printf ("Testing getCampuses\n");
  assert (getCampuses (testGame, UNI_A) == 0);
  assert (getCampuses (testGame, UNI_B) == 0);
  assert (getCampuses (testGame, UNI_C) == 0);

  printf ("Testing getIPs\n");
  assert (getIPs (testGame, UNI_A) == 0);
  assert (getIPs (testGame, UNI_B) == 0);
  assert (getIPs (testGame, UNI_C) == 0);

  printf ("Testing getPublications\n");
  assert (getPublications (testGame, UNI_A) == 0);
  assert (getPublications (testGame, UNI_B) == 0);
  assert (getPublications (testGame, UNI_C) == 0);
  
  printf ("Testing getStudents\n");
  assert (getStudents (testGame, UNI_A, STUDENT_THD) == 0);
  assert (getStudents (testGame, UNI_A, STUDENT_BPS) == 3);
  assert (getStudents (testGame, UNI_A, STUDENT_BQN) == 3);
  assert (getStudents (testGame, UNI_A, STUDENT_MJ) == 1);
  assert (getStudents (testGame, UNI_A, STUDENT_MTV) == 1);
  assert (getStudents (testGame, UNI_A, STUDENT_MMONEY) == 1);
  
  printf ("Disposing testGame\n");
  disposeGame (testGame);

  
  // DONE
  printf("All Tests Passed!\nYou Are AWESOME!!!");

}
