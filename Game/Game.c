// Created by Harris Borman, Djimon Jayasundera, and Zachary Chengy
// This programs aims to host a game for AIs to play on.

#include <stdio.h>
#include <stdlib.h>

typedef struct _game {
  int maxPoints;
  int currentTurn;
  int diceNumber;
  
  int player1Unis;
  int player2Unis;
  int player3Unis;
  char *player1Campuses[player1Unis];
  char *player2Campuses[player2Unis];
  char *player3Campuses[player3Unis];
  
} game;

int main(/* Put the argv argc stuff here plz */) {
  
}
