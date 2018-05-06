// Created by Harris Borman, Djimon Jayasundera, and Zachary Chengy
// This programs aims to host a game for AIs to play on.

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

typedef struct _game {
  int maxPoints;
  int currentTurn; // This can be used to work out who's turn it is... as player 1 will go first.
  int diceNumber;
  
  // campusMap only contains information about whether a campus is on a vertex.
  int campusMap[12][11] = {0}; // The map has 11 rows and 12 columns. Initialize everything as 0.
  campusMap[7][1] = CAMPUS_A; // Locations of initial campuses.
  campusMap[1][8] = CAMPUS_B;
  campusMap[2][3] = CAMPUS_C;
  campusMap[6][11] = CAMPUS_A;
  campusMap[12][4] = CAMPUS_B;
  campusMap[11][9] = CAMPUS_C;

  int p1Campuses = 2;
  int p1ThdStudents = 0; // These show how many of each type of student each player has.
  int p1BpsStudents = 3;
  int p1BqnStudents = 3;
  int p1MjStudents = 1;
  int p1MtvStudents = 1;
  int p1MmoneyStudents = 1;

  int p2Campuses = 2;
  int p2ThdStudents = 0;
  int p2BpsStudents = 3;
  int p2BqnStudents = 3;
  int p2MjStudents = 1;
  int p2MtvStudents = 1;
  int p2MmoneyStudents = 1;
  
  int p3Campuses = 2;
  int p3ThdStudents = 0;
  int p3BpsStudents = 3;
  int p3BqnStudents = 3;
  int p3MjStudents = 1;
  int p3MtvStudents = 1;
  int p3MmoneyStudents = 1;
  
} game;

int main(/* Put the argv argc stuff here plz. */) {
  // I have no clue what to put here.
  return EXIT_SUCCESS;
}

int getWhoseTurn(Game g) { 
  int id;
  if (g.currentTurn == -1) {
    id = NO_ONE;
  } else if (g.currentTurn % 3 == 0) {
    id = UNI_A;
  } else if (g.currentTurn +1 % 3 == 0) {
    id = UNI_B;
  } else {
    id = UNI_C;
  }
  return id;
}

int getCampuses(Game g, int player) {
  int numCampuses;
  if (player == 1) {
    numCampuses = game.p1Campuses;
  } else if (player == 2) {
    numCampuses = game.p2Campuses;
  } else {
    numCampuses = game.p3Campuses;
  }
  return numCampuses;
}

int getStudents(Game g, int player, int discipline) {
  int numStudents;
  if (player == 1) {
    if (discipline == STUDENT_THD) {
      numStudents = game.p1ThdStudents;
    } else if (discipline == STUDENT_BPS) {
      numStudents = game.p1BpsStudents;
    } else if (discipline == STUDENT_BQN) {
      numStudents = game.p1BqnStudents;
    } else if (discipline == STUDENT_MJ) {
      numStudents = game.p1MjStudents;
    } else if (discipline == STUDENT_MTV) {
      numStudents = game.p1MtvStudents;
    } else { // else if (discipline == STUDENT_MMONEY) 
      numStudents = game.p1MmoneyStudents;
    }
  } else if (player == 2) {
    if (discipline == STUDENT_THD) {
      numStudents = game.p2ThdStudents;
    } else if (discipline == STUDENT_BPS) {
      numStudents = game.p2BpsStudents;
    } else if (discipline == STUDENT_BQN) {
      numStudents = game.p2BqnStudents;
    } else if (discipline == STUDENT_MJ) {
      numStudents = game.p2MjStudents;
    } else if (discipline == STUDENT_MTV) {
      numStudents = game.p2MtvStudents;
    } else { // else if (discipline == STUDENT_MMONEY) 
      numStudents = game.p2MmoneyStudents;
    }
  } else { // else if (player == 3) {
    if (discipline == STUDENT_THD) {
      numStudents = game.p3ThdStudents;
    } else if (discipline == STUDENT_BPS) {
      numStudents = game.p3BpsStudents;
    } else if (discipline == STUDENT_BQN) {
      numStudents = game.p3BqnStudents;
    } else if (discipline == STUDENT_MJ) {
      numStudents = game.p3MjStudents;
    } else if (discipline == STUDENT_MTV) {
      numStudents = game.p3MtvStudents;
    } else { // else if (discipline == STUDENT_MMONEY) 
      numStudents = game.p3MmoneyStudents;
    }
  }
  return numStudents;
}

