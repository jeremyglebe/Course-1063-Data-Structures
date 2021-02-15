// Convenient way to use special characters, if your terminal supports it
#define KING "♚"
#define QUEEN "♛"
#define BISHOP "♝"
#define KNIGHT "♞"
#define ROOK "♜"
#define PAWN "♟︎"
#define DARK_BLOCK "▓▓"
#define LIGHT_BLOCK "░░"

#include <iostream>
#include <string>

using namespace std;

// Functions must be prototyped
string promptUser();
void readFile(string filepath, char board[8][8]);
void printBoard(char board[8][8]);

int main() { }
