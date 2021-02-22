#include <iostream>
using namespace std;

class Matrix {
public:
    // Runs every time we create a Matrix
    Matrix(int rsize, int csize){
        // Store sizes in the class
        numRows = rsize;
        numColumns = csize;
        // Create the array representing rows (int* array)
        _grid = new int*[numRows];
        // For every row...
        for(int r = 0; r < numRows; r++){
            // Create an array representing column values (int array)
            _grid[r] = new int[numColumns];
            // To initialize the values, we
            // loop through every column in every row
            for(int c = 0; c < numColumns; c++){
                _grid[r][c] = -1;
            }
        }
    }
    // Destructor
    ~Matrix(){
        // First we delete each set of columns
        for(int r = 0; r < numRows; r++){
            delete[] _grid[r];
        }
        // Now actually delete the row array (pointers array)
        delete[] _grid;
    }
    // Gets a value in the matrix
    int get(int r, int c){
        return _grid[r][c];
    }
    // Sets a value in the matrix
    void set(int r, int c, int val){
        _grid[r][c] = val;
    }
    // Prints the matrix
    void print(){
        for(int r = 0; r < numRows; r++){
            for(int c = 0; c < numColumns; c++){
                cout << _grid[r][c] << ' ';
            }
            cout << endl;
        }
    }
private:
    int** _grid;
    int numRows;
    int numColumns;
};

int main() {
    Matrix m1(3,2); // destroyed when out of scope
    m1.print();
    cout << endl;
    Matrix* mptr = new Matrix(2,2); // destroyed when I say 'delete'
    // (*mptr).print();
    // Testing get and set
    mptr->set(1,1, 15);
    cout << "Testing Matrix get() method: " << mptr->get(1,1) << "\n\n";
    // Shortcut to dereference and
    // use dot operator at the same time
    mptr->print();
    delete mptr;
    return 0;
}