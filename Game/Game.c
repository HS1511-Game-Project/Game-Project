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
  int p1ThdStudents; // These show how many of each type of student each player has.
  int p1BpsStudents;
  int p1BqnStudents;
  int p1MjStudents;
  int p1MtvStudents;
  int p1MmoneyStudents;

  int p2Campuses = 2;
  int p2ThdStudents;
  int p2BpsStudents;
  int p2BqnStudents;
  int p2MjStudents;
  int p2MtvStudents;
  int p2MmoneyStudents;
  
  int p3Campuses = 2;
  int p3ThdStudents;
  int p3BpsStudents;
  int p3BqnStudents;
  int p3MjStudents;
  int p3MtvStudents;
  int p3MmoneyStudents;
  
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

