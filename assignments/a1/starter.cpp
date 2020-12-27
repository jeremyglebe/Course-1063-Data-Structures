// Convenient way to use special characters, if your terminal supports it
#define KNIGHT "♞ "
#define QUEEN "♕ "
#define DARK_BLOCK "██"
#define LIGHT_BLOCK "░░"

#include <iostream>
#include <string>

using namespace std;

struct ChessPiece{
    // Must include symbol (string, char?), row, column
};
struct ChessBoard{
    // Must include a 2D char array and a ChessPiece
};
// Functions must be prototyped/forward declared
void printBoard(ChessBoard game);
ChessPiece newPiece(string symbol, int row, int col);

// If your structs and functions are made correctly,
// you will NOT need to modify this main function
int main() {
    ChessBoard board;
    // Board with a queen
    board.piece = newPiece(QUEEN, 4, 3);
    printBoard(board);
    // Board with a knight
    board.piece = newPiece(KNIGHT, 1, 2);
    printBoard(board);
}
