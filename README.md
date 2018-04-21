
# Game-Project

## Purpose
The aim of this is to create a program to host the game for people (AIs) to play on.

## Functions To Be Tested And Implemented
```c
void nextTurn(allPlayersInfo players); // Tells the next player it is their turn.

int getCurrentTurn(); // Find out who's turn it is right now, to find out who's turn it is next.

allPlayersInfo addStudent(char studentType, int playerID, allPlayersInfo players); // Add a student to a specific player. Returns the struct of the players.

board buildCampus(char* location, int playerID); // Build a campus for that player. Returns a struct of the board.

char* getTileInfo(char* location); // Returns a string with the information about that tile.

int rollDice(); // Returns a value on a dice.

board setBoardUp(); // Creates the board.

playerInfo getPlayerInfo(int playerID); // Returns the information about a player.

allPlayersInfo getAllPlayersInfo(); // Returns a struct containing structs for every single player and info about them (e.g. How many of each type of student they have).
```

## Important Things To Note
allPlayersInfo is a struct of the structs of playerInfo.
