// Created by Harris Borman, Djimon Jayasundera, and Zachary Chengy
// This programs aims to host a game for AIs to play on.

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

typedef struct _game {
  int maxPoints;
  int currentTurn; // This can be used to work out who's turn it is... as player 1 will go first.
  int diceNumber;
  
  int p1Campuses; // These show the number of Unis that each player has.
  int p2Campuses; // They are only used for the strings below.
  int p3Campuses;
  char *p1Campuses[player1Unis]; // The string will look like "lrlrlr llll rrll lll r" so this person has 5 campuses at locations
  char *p2Campuses[player2Unis]; // separated by a space in the string.
  char *p3Campuses[player3Unis];
  
  int p1ThdStudents; // These show how many of each type of student each player has.
  int p1BpsStudents;
  int p1BqnStudents;
  int p1MjStudents;
  int p1MtvStudents;
  int p1MmoneyStudents;

  int p2ThdStudents;
  int p2BpsStudents;
  int p2BqnStudents;
  int p2MjStudents;
  int p2MtvStudents;
  int p2MmoneyStudents;
  
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

// Does not return 0 if Terra Nullis.
int getWhoseTurn(Game g) { 
  int id;
  if (g.currentTurn -1 % 3 == 0) {
    id = UNI_A;
  } else if (g.currentTurn % 3 == 0) {
    id = UNI_B;
  } else {
    id = UNI_C;
  }
  return id;
}


