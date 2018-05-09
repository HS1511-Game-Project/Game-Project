// By Djimon Jayasundera, Zac Cheng, and Harris Borman
// 5/9/2018

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Game.h"
#include "mechanicalTurk.h"

#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
  STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
  STUDENT_MTV, STUDENT_BPS, STUDENT_MTV, STUDENT_BQN, \
  STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
  STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}


int main() {
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  Game g = newGame(disciplines, dice);
  int gameOver = getKPIpoints(g, UNI_A)>=150 && getKPIpoints(g, UNI_B)>=150 && getKPIpoints(g, UNI_C)>=150;
  while (!gameOver) {
    int diceValue = throwDice(g, dice);
    action move;
    int currentTurn = getWhoseTurn(g);
    gameOver = getKPIpoints(g, UNI_A)<150 && getKPIpoints(g, UNI_B)<150 && getKPIpoints(g, UNI_C)<150;
    while (getWhoseTurn(g) == currentTurn && !gameOver) {
      move = decideAction(g);
      assert(isLegalAction(g, move) == TRUE);
      if (move.actionCode == START_SPINOFF) {
        int decision = rand()%6+1; // Number between 1 and 6 (inclusive)
        if (decision == 1 || decision == 2) {
          move.actionCode = OBTAIN_PUBLICATION;
        } else {
          move.actionCode = OBTAIN_IP;
        }
      }
      makeAction(g, move);
    }
  }
  return EXIT_SUCCESS;
}