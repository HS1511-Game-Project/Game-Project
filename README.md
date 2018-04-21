
# Game-Project

## Purpose
The aim of this is to create a program to host the game for people (AIs) to play on.

## Functions To Be Tested And Implemented
void nextTurn(playersInfo players); // Tells the next player it is their turn.

int getCurrentTurn(); // Find out who's turn it is right now, to find out who's turn it is next.

playersInfo addStudent(char studentType, int player); // Add a student to a specific player. Returns the struct of the players.

board buildCampus(char \* location, int player); // Build a campus for that player. Returns a struct of the board.

char \* getTileInfo(char \* location); // Returns a string with the information about that tile.

int rollDice(); // Returns a value on a dice.
