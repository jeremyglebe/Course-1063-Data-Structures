#include <iostream>
// Allows us to easily type a placeholder
// for the string containing the king's symbol
#define KING "♚"

// Typedef just provides an alternate name of your choice
// for an existing type
// This is sometimes called an "alias"
typedef double Number;
// The syntax is weird for typedef'd arrays, but whatever
typedef int Matrix[4][4];
// Nothing wrong with multiple aliases
typedef int Grid[4][4];
typedef int Table[4][4];

using namespace std;

// 2D array column size MUST be hardcoded
// (in declaration and parameters)
void printMatrix(int M[4][4]);

int main() {
    // KING is replaced with "♚"
    cout << KING << '\n';

    Number num = 5.34;

    // Create a 2D array, remember ROW then COLUMN
    int matrix[4][4];
    // For loop for every row
    for (int r = 0; r < 4; r++){
        // For loop for every column
        for (int c = 0; c < 4; c++){
            // matrix[r][c] will access EVERY item
            // This is the most basic traversal of a 2D array
            matrix[r][c] = r + c;
        }
    }
    // Cool ways to intialize arrays
    int narr[] = {5, 3, 4};
    int twod[4][4] = {
        {1, 5, 6, -306},
        {0, 1, 2, -9},
        {9, 9, 42, 2},
        {9, 9, 42, 1111}
        };

    // Calling the print function
    printMatrix(twod);
    printMatrix(matrix);
}

// Printing the 2D array
void printMatrix(Matrix M){
    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            cout << M[row][col] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}