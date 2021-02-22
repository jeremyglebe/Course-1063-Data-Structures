#include <iostream>
using namespace std;

// Function to print a 2D array (dynamic sizes)
void printMatrix(int**, int rows, int cols);

int main() {
    // Size variables, we could read these from keyboard or file if we wanted
    int numRow = 5;
    int numCol = 8;
    // Double pointer that we will make into a 2D array
    int** matrix;
    // Create an array of pointers, this serves as the "rows"
    matrix = new int*[numRow];
    // For each pointer in the array (each row)
    for(int r =0; r < numRow; r++){
        // For each row we create an array of integers representing columns
        matrix[r] = new int[numCol];
        // Now, if we choose to loop through those columns, we can go ahead and initialize values
        for(int c = 0; c < numCol; c++){
            matrix[r][c] = r*c;
        }
    }
    // Call the print function
    printMatrix(matrix, numRow, numCol);

    // Deletion of a 2D array means first deleting the columns of every row
    // Remember, for every "new" there must be a "delete"!
    for(int r = 0; r < numRow; r++){
        delete[] matrix[r];
    }
    // After deleting all the columns, we can delete the array of pointers (rows)
    delete[] matrix;

    return 0;
}

// Print function
void printMatrix(int** grid, int rows, int cols){
    // Very simple 2D array print, only now we get sizes as parameters!
    for(int r =0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            cout << grid[r][c] << ' ';
        }
        cout << endl;
    }
}