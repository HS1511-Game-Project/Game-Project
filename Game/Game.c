// Created by Harris Borman, Djimon Jayasundera, and Zachary Chengy
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
    
    g.players[c].campusLocations[PATH_LIMIT] = {0};
    g.players[c].arcLocations[PATH_LIMIT] = {0};
    g.players[c].go8Locations[PATH_LIMIT] = {0};
    
    g.players[c].pub = 0;
    g.players[c].ip = 0;
    g.players[c].kpi = 0;
  }
	return g;
}

void disposeGame (Game g) {
	free(g);
}

int getTurnNumber(Game g) { // Djimon
  return g.currentTurn;
}

int getWhoseTurn(Game g) { // Djimon
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

int getARCs(Game g, int player) { // Djimon
  int numARCs;
  if (player == 1) {
    numARCs = game.p1ARCs;
  } else if (player == 2) {
    numARCs = game.p2ARCs;
  } else {
    numARCs = game.p3ARCs;
  }
  return numARCs;
}

int getGO8s(Game g, int player) { // Djimon
  int numGO8s;
  if (player == 1) {
    numGO8s = game.p1GO8s;
  } else if (player == 2) {
    numGO8s = game.p2GO8s;
  } else {
    numGO8s = game.p3GO8s;
  }
  return numGO8s;
}

int getCampuses(Game g, int player) { // Djimon
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

int getIPs(Game g, int player) { // Djimon
  int IPs;
  if (player == 1) {
    IPs = game.p1IPs;
  } else if (player == 2) {
    IPs = game.p2IPs;
  } else {
    IPs = game.p3IPs;
  }
  return IPs;
}

int getStudents(Game g, int player, int discipline) { // Djimon
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

int isLegalAction(Game g, action a) { // Zac
    int legal = True; //assumes true
    int player = getWhoseTurn(g);
    if (getTurnNumber(g )== TERRA_NULLIS) {
        legal = False;
    } else if (a.actionCode == PASS) {
        continue;
    } else if (a.actionCode == BUILD_CAMPUS) {
        bool enoughBps = getStudents(g, player, STUDENT_BPS)<1;
        bool enoughBqn = getStudents(g, player, STUDENT_BQN)<1;
        bool enoughMj = getStudents(g, player, STUDENT_MJ)<1;
        bool enoughMtv = getStudents(g, player, STUDENT_MTV)<1;
        if (enoughBps || enoughBqn || enoughMj || enoughMtv) { 
            legal = False;
        }
    } else if (a.actionCode == BUILD_GO8) {
        // I am not even gonna try keeping that next line under 72 characters.
        if((g->players[player].disciplines[STUDENT_MJ]<2) || (g->players[player].disciplines[STUDENT_MMONEY]<3) || (getCampuses(g, player)<1)){
            legal = False;
        }
    } else if (a.actionCode == OBTAIN_ARC) {
        if((g->players[player].disciplines[STUDENT_BPS]<1) || (g->players[player].disciplines[STUDENT_BQN]<1)){
            legal = False;
        }
    } else if (a.actionCode == START_SPINOFF) {
        if((getStudents(g, player, STUDENT_MJ)<1) || (getStudents(g, player, STUDENT_MTV)<1) || (getStudents(g, player, STUDENT_MMONEY)<1)){
            legal = False;
        }
    } else if (a.actionCode == OBTAIN_PUBLICATION) {
        legal = False;
    } else if (a.actionCode == OBTAIN_IP_PATENT) {
        legal = False;
        p += 1; // umm.. what is this?
    return legal;
}


                     

