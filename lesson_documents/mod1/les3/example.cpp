#include <iostream>
using namespace std;

int sumArray(int arr[], int numItems);
int sumMatrix(int matrix[][3], int num_rows);

int main()
{
    // create a 1D array
    int myArray[5] = {7, 6, 5, 4, 3};
    // create a 2D array
    int matrix[2][3] = {
        {1, 1, 1},
        {9, 6, 3}}; // This could be done as one line, but I think this is
                    // more visual and C++ accepts it!
    cout << sumArray(myArray, 5) << '\n';
    cout << sumMatrix(matrix, 2) << '\n';
}

int sumArray(int arr[], int numItems)
{
    int sum = 0;
    for (int i = 0; i < numItems; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int sumMatrix(int matrix[][3], int num_rows)
{
    int sum = 0;
    // Traverse the rows, which we can have any number of
    // I just named the variable r for "rows", it's common but not essential
    for (int r = 0; r < num_rows; r++)
    {
        // For each row, we need to traverse each column so we can access all
        // For now, we just have to assume the matrix will have 3 columns. :(
        // This will be better later...
        for (int c = 0; c < 3; c++)
        {
            sum += matrix[r][c]; // Item at row r and column c in the matrix
        }
    }
    return sum;
}