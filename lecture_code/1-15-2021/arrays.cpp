#include <iostream>
using namespace std;

int main() {
    // Basic matrix creation and traversal
    int matrix[3][3];
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            matrix[r][c] = r + c;
        }
    }
    for (int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            cout << matrix[r][c] << ' ';
        }
        cout << '\n';
    }
    // Initializer lists
    int arr[] = {6, 3, 1, 123};
    int M[3][3] = {{0}};
    for (int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            cout << M[r][c] << ' ';
        }
        cout << '\n';
    }
}