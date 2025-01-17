// Created by Harris Borman, Djimon Jayasundera, and Zachary Cheng
// This programs aims to host a game for AIs to play on.

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"


/*/////
STRUCTS
/////*/

struct player { 
  path campusLocations[PATH_LIMIT];
  path arcLocations[PATH_LIMIT];
  path go8Locations[PATH_LIMIT];
  int numCampuses;
  int numArcs;
  int numGo8s;
  
  int thd = 0; // These show how many of each type of student each player has.
  int bps = 3;
  int bqn = 3;
  int mj = 1;
  int mtv = 1;
  int mmoney = 1;

  int pub; // Publications
  int ip;
  int kpi;
} player;

typedef struct _game {
  struct player players[3];
  int turnNum;
  int disciplines[NUM_REGIONS];
  int diceValues[NUM_REGIONS];
  int maxPoints;
} game;

/*///////
FUNCTIONS
///////*/

Game newGame(int disciplinesValues[],int diceValues[]) {
  // Set up game
    Game g = malloc(sizeof(game));
    int c = 0;
    while (c < NUM_REGIONS) {
      g.disciplines[c] = disciplinesValues[c];
      g.diceValues[c] = diceValues[c];
      count ++;
    }
  g.turnNum = -1;
  g.disciplines[NUM_REGIONS] = disciplinesValues[];
  g.diceValues[NUM_REGIONS] = diceValues[];
  // Set up players
  c = 0;
  while (c < 3) {
    g.players[c].thd = 0;
    g.players[c].bps = 3;
    g.players[c].bqn = 3;
    g.players[c].mj = 1;
    g.players[c].mtv = 1;
    g.players[c].mmoney = 1;
    
    g.players[c].campusLocations[PATH_LIMIT] = {0}; // Someone fix this
    g.players[c].arcLocations[PATH_LIMIT] = {0}; // And this
    g.players[c].go8Locations[PATH_LIMIT] = {0}; // And this. Because you start with 2 campuses so put in their locations
    g.players[c].numCampuses = 2;
    g.players[c].numArcs = 0;
    g.players[c].numGo8s = 0;
    
    g.players[c].pub = 0;
    g.players[c].ip = 0;
    g.players[c].kpi = 0;
  }
  return g;
}

void disposeGame (Game g) {
  free(g);
}

void makeAction (Game g, action a) { // Harris
  assert(isLegalAction(g, a) == TRUE);
  if (a.actionCode == PASS) {
    continue;
    
  } else if (a.actionCode == BUILD_CAMPUS) {
    g.players[getWhoseTurn(g) - 1].numCampuses++;
    g.players[getWhoseTurn(g) - 1].campusLocations[numCampuses-1] = a.path;
    // ALSO ADD MINUSING THE PLAYERS STUDENTS BASED ON HOW MUCH IT COSTS
    g.players[getWhoseTurn(g) - 1].bps--;
    g.players[getWhoseTurn(g) - 1].bqn--;
    g.players[getWhoseTurn(g) - 1].mj--;
    g.players[getWhoseTurn(g) - 1].mtv--;
    
  } else if (a.actionCode == BUILD_GO8) {
    g.players[getWhoseTurn(g) - 1].numGo8s++;
    g.players[getWhoseTurn(g) - 1].go8Locations[numGo8s-1] = a.path;
    // ALSO ADD MINUSING THE PLAYERS STUDENTS BASED ON HOW MUCH IT COSTS
    g.players[getWhoseTurn(g) - 1].mj -= 2;
    g.players[getWhoseTurn(g) - 1].mmoney -= 3;

    
  } else if (a.actionCode == OBTAIN_ARC) {
    g.players[getWhoseTurn(g) - 1].numarcs++;
    g.players[getWhoseTurn(g) - 1].arcLocations[numGo8s-1] = a.path;
    g.players[getWhoseTurn(g) - 1].bps--;
    g.players[getWhoseTurn(g) - 1].bqn--;;
    continue; // This is weird, well.... it shouldn't pass isLegalAction.
  } else if (a.actionCode == START_SPINOFF) {
    if startSpinoff() {
        g.players[getWhoseTurn(g) - 1].numGo8s++;
    } else {
        g.players[getWhoseTurn(g) - 1].numGo8s++;
    }
    g.players[getWhoseTurn(g) - 1].mtv--;
    g.players[getWhoseTurn(g) - 1].mj--;
    g.players[getWhoseTurn(g) - 1].mmoney--;

  } else if  (a.actionCode == OBTAIN_PUBLICATION) {
    continue; 
  } else if (a.actionCode == OBTAIN_IP_PATENT) {
    continue; 
  } else if (a.actionCode == RETRAIN_STUDENTS) {
    
    continue; // Put stuff here
  } else {
    assert(False); // Something is wrong
  }
}

int IPOrPublication() {
    int randomValue = rand() % 3
    if (randomValue == 0) {
        return 1
    } else {
        return 0
    }
}

int getTurnNumber(Game g) { // Djimon
  return g.turnNum;
}

int getWhoseTurn(Game g) { // Djimon
  int id;
  if (g.turnNum == -1) {
    id = NO_ONE;
  } else if (g.turnNum % 3 == 0) {
    id = UNI_A;
  } else if (g.turnNum +1 % 3 == 0) {
    id = UNI_B;
  } else {
    id = UNI_C;
  }
  return id;
}

int getARCs(Game g, int player) { // Djimon
  return g.players[player-1].numArcs;
}

int getGO8s(Game g, int player) { // Djimon
  return g.players[player-1].numGo8s;
}

int getCampuses(Game g, int player) { // Djimon
  return g.players[player-1].numGo8s;
}

int getIPs(Game g, int player) { // Djimon
  return g.players[player-1].ip;
}

int getStudents(Game g, int player, int discipline) { // Djimon
  int numStudents;
  if (discipline == STUDENT_THD) {
    numStudents = g.players[player-1].thd;
  } else if (discipline == STUDENT_BPS) {
    numStudents = g.players[player-1].bps;
  } else if (discipline == STUDENT_BQN) {
    numStudents = g.players[player-1].bqn;
  } else if (discipline == STUDENT_MJ) {
    numStudents = g.players[player-1].mj;
  } else if (discipline == STUDENT_MTV) {
    numStudents = g.players[player-1].mtv;
  } else { // else if (discipline == STUDENT_MMONEY) 
    numStudents = g.players[player-1].mmoney;
  }
  return numStudents;
}

int isLegalAction(Game g, action a) { // Zac & Harris
    int legal = TRUE;
    int player = getWhoseTurn(g);
    if (getTurnNumber(g )== TERRA_NULLIS) {
        legal = FALSE;
    } else if (a.actionCode == PASS) {
        continue;
    } else if (a.actionCode == BUILD_CAMPUS) {
        int enoughBps = getStudents(g, player, STUDENT_BPS) >= 1;
        int enoughBqn = getStudents(g, player, STUDENT_BQN) >= 1;
        int enoughMj = getStudents(g, player, STUDENT_MJ) >= 1;
        int enoughMtv = getStudents(g, player, STUDENT_MTV) >= 1;

        if (enoughBps && enoughBqn && enoughMj && enoughMtv) { 
            legal = TRUE;
        } else {
            legal = FALSE;
        }

    } else if (a.actionCode == BUILD_GO8) {
        int enoughMj = getStudents(g,player,STUDENT_MJ)>=2;
        int enoughMmoney = getStudents(g,player,STUDENT_MMONEY)>=3;
        int enoughCampus = getCampuses(g, player) >= 1;

        if(enoughMj && enoughMmoney && enoughCampus){
            legal = TRUE;
        } else {
            legal = FALSE;
        }
    } else if (a.actionCode == OBTAIN_ARC) {
        int enoughBps = getStudents(g,player,STUDENT_BPS) >= 1;
        int enoughBqn = getStudents(g,player,STUDENT_BQN) >= 1;
        if(enoughBps && enoughBqn){
            legal = TRUE;
        } else {
            legal = FALSE;
        }

    } else if (a.actionCode == START_SPINOFF) {
        int enoughMj = getStudents(g, player, STUDENT_MJ) >= 1;
        int enoughMTV = getStudents(g, player, STUDENT_MTV) >= 1;
        int enoughMMONEY = getStudents(g, player, STUDENT_MMONEY) >= 1;

        if(enoughMj && enoughMTV && enoughMMONEY){
            legal = TRUE;
        } else {
            legal = FALSE;
        }
    }
    return legal;
}


                     

