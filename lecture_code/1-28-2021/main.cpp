#include <iostream>
using namespace std;

void printArr(char* arr, int size);
void printMatrix(int** arr, int row, int col);
char* resize(char* arr, int oldSz, int newSz);

int main() {
    // Dynamic allocation of memory on the heap, stored address in pointer
    int * nptr = new int(42);
    // Let's print out some information about our pointer, pay attention to the syntax!
    cout << "Address the pointer is pointing to: " << nptr << '\n';
    cout << "Object the pointer is pointing to: " << *nptr << '\n';
    cout << "Address the pointer is stored at: " << &nptr << '\n';
    // Always release memory allocated dynamically
    delete nptr;

    // Prompt user for array size
    int size;
    cout << "How big is the array? ";
    cin >> size;
    // Dynamically sizing arrays using pointers
    char * chptr = new char[size];
    // Have the user enter each value for the array
    for(int i = 0; i < size; i++){
        cout << '[' << i << "]: ";
        cin >> chptr[i];
    }
    // Print the array
    printArr(chptr, size);
    // We wrote a function to "resize" an array (really creates a new one and deletes original)
    chptr = resize(chptr, size, size + 1);
    // We incrased size by 1, so "size" is the last index, just testing to see if it works
    chptr[size] = '@';
    // Printing
    printArr(chptr, size + 1);
    // Always delete your dynamically allocated memory!
    delete[] chptr;

    // 2D arrays anyone? We can use variables for sizes now!
    int numRows = 8;
    int numCols = 8;
    // Creating the array of rows
    int** matrix = new int*[numRows];
    for (int r = 0; r < numRows; r++){
        // For each row, we create an array representing the columns
        matrix[r] = new int[numCols];
        for(int c=0; c < numCols; c++){
            // Now for each row/column, we initialize it's value
            matrix[r][c] = r * c;
        }
    }
    // Print the matrix
    printMatrix(matrix, numRows, numCols);

    // We must delete all the columns first!
    for(int r = 0; r < numRows; r++){
        delete[] matrix[r];
    }
    // Now delete the rows
    delete[] matrix;
}

// Pretty basic function to print arrays
void printArr(char* arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

char* resize(char* arr, int oldSz, int newSz){
    // Create a new array of the new size
    char* temp = new char[newSz];
    // Copy all the old values to the new array
    for(int i = 0; i < oldSz; i++){
        temp[i] = arr[i];
    }
    // Delet the old array
    delete[] arr;
    // Return the new array location (ADDRESS)
    return temp;
}

// Basic function to print 2D array, now with variables for sizes
void printMatrix(int** arr, int row, int col){
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            cout << arr[r][c] << ' ';
        }
        cout << '\n';
    }
}