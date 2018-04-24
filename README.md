![macOS Build Status](https://circleci.com/gh/atom/atom/tree/master.svg?style=shield)


# Game-Project

## Purpose
The aim of this is to create a program to host the game for people (AIs) to play on.

## Functions To Be Tested And Implemented
```c
void makeAction (Game g, action a); 

void throwDice (Game g, int diceScore);

void disposeGame (Game g);

int getDiscipline (Game g, int regionID);

int getDiceValue (Game g, int regionID);

int getMostARCs (Game g);

int getMostPublications (Game g);

int getTurnNumber (Game g);

int getWhoseTurn (Game g);

int getCampus(Game g, path pathToVertex);

int getARC(Game g, path pathToEdge);

int isLegalAction (Game g, action a);

int getKPIpoints (Game g, int player);

int getARCs (Game g, int player);

int getGO8s (Game g, int player);

int getCampuses (Game g, int player);

int getIPs (Game g, int player);

int getPublications (Game g, int player);

int getStudents (Game g, int player, int discipline);

int getExchangeRate (Game g, int player, int disciplineFrom, int disciplineTo);
```

## NOTES
- Remember that all of the information about the functions are available on the Game.h page.
