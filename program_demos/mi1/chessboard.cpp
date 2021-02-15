// Convenient way to use special characters, if your terminal supports it
#define KING "♔ "
#define QUEEN "♕ "
#define BISHOP "♗ "
#define KNIGHT "♘ "
#define ROOK "♖ "
#define PAWN "♙ "
#define DARK_BLOCK "▓▓"
#define LIGHT_BLOCK "░░"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Functions must be prototyped
string promptUser();
void readFile(string filepath, char board[8][8]);
void printBoard(char board[8][8]);

int main() {
    // Create board
    char board[8][8];
    // Read board data from file that user specifies from prompt
    readFile(promptUser(), board);
    // Print the board as a board
    printBoard(board);
}

string promptUser(){
    string file;
    // Print a prompt
    cout << "<Input File>: ";
    // Get the file string from the user
    cin >> file;
    // Return the result
    return file;
}

void readFile(string filepath, char board[8][8]){
    // Open a filestream
    ifstream ifile(filepath);
    // For every row and column of the chessboard
    for (int r = 0; r < 8; r++){
        for (int c = 0; c < 8; c++){
            // Read the next character into the array
            ifile >> board[r][c];
        }
        // Throw away the newline character
        ifile.ignore(2, '\n');
    }
    // Close the file stream
    ifile.close();
}

void printBoard(char board[8][8]){
    // Print the top labels
    cout << "   1 2 3 4 5 6 7 8\n";
    // Loop through every space
    for (int r = 0; r < 8; r++){
        // Print the lefthand labels
        cout << r + 1 << ' ';
        for (int c = 0; c < 8; c++){
            // Using even/odd patterns, determine whether this would be a light or dark block
            string block = (r+c) % 2 ? DARK_BLOCK : LIGHT_BLOCK;
            // Print either a piece or a block, based on input char
            switch(board[r][c]){
                case 'K':
                    cout << KING;
                    break;
                case 'Q':
                    cout << QUEEN;
                    break;
                case 'B':
                    cout << BISHOP;
                    break;
                case 'N':
                    cout << KNIGHT;
                    break;
                case 'R':
                    cout << ROOK;
                    break;
                case 'p':
                    cout << PAWN;
                    break;
                default:
                    cout << block;
                    break;
            }
        }
        // Newline after every row
        cout << '\n';
    }
}