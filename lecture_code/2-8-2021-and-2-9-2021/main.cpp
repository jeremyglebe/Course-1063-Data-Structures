#include <iostream>
using namespace std;

// Pointers can be used in functions
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    // Use address operator to get the variable address
    int num = -23;
    cout << "Address of num: " << &num << endl; // prints address
    // Pointers are variables that store these addresses
    // and provide alternate methods of accessing memory locations
    // The following is a pointer which points to objects of type (int)
    // The pointer's type is (int pointer)
    int * intptr; // Declaring a pointer with type followed by asterisk
                  // Spacing does not matter when declaring pointers
    // Assign the pointer an address
    intptr = &num;
    // Access address of num and value of num, using the pointer
    cout << "Address stored by intptr: " << intptr << endl; // Should print the SAME address as before
    cout << "Value of num (accessed by intptr): " << *intptr << endl; // This is the DEREFERENCE operator,
                                                                      // gets value pointed to
                                                                      // Book calls this "indirection" operator,
                                                                      // that's cool ig
    *intptr = 20; // Update the value of the object pointed to, so num
                  // should be updated, let's try
    cout << "Value of num (updated by intptr): " << num << endl; // This is 20, right?

    // ARRAYS ARE POINTERS
    int vals[] = {4,7,11};
    cout << "Address stored by vals (an array): " << vals << endl; // Prints an address, because
                                                                   // ARRAYS ARE POINTERS
    cout << "First item in vals: " << vals[0] << endl; // Displays the first item, 4

    int* valptr = vals;
    // Math with pointers, eww
    // What happens if I add to a pointer?
    cout << "valptr + 1 = " << valptr + 1 << endl; // Increases address by size of 1 int
    // For pointers, addition means (address + (index * size of single object))
    cout << "Second item in valptr/vals: " << *(valptr+1) << endl; // Parentheses b/c order of operations
    cout << "Subscript is a shortcut for *(ptr + i): " << valptr[1] << endl; // Subscript is the EXACT same thing, but prettier

    // Initializing: a few options for blank pointers
    int *ptr = NULL; // NULL is actually 0
    int *ptr2 = nullptr; // nullptr is a pre-defined pointer, technically faster
    int *ptr3{}; // This is just ugly, why?
                 // You can also initialize them to actual values
                 // like &num or a new variable

    // Comparing pointers
    // THIS COMPARES THE ADDRESSES
    if(vals == valptr){
        cout << "Addresses are equal!\n";
    }
    // THIS COMPARES THE VALUES
    if(*intptr != *valptr){
        cout << "Values are not the same!\n";
    }

    // Testing a function call using pointers
    cout << "intptr, valptr, index 0 before swap(): "
        << *intptr << ", " << *valptr << endl;
    swap(intptr, valptr);
    cout << "intptr, valptr, index 0 after swap(): "
        << *intptr << ", " << *valptr << endl;

    // Dynamic memory allocation
    double* dptr;
    dptr = new double;
    double* aptr;
    // aptr = new double[20];
    // aptr = new double[*intptr];
    aptr = new double[num];

    // Make sure to delete dynamic memory
    delete dptr;
    delete[] aptr;
    dptr = nullptr;
    aptr = nullptr;
    // Memory which is not deleted stays reserved but useless
    // That is called a MEMORY LEAK
    // Also, if re-using the pointer, set it to NULL again, or it
    // will point to garbage. (a DANGLING POINTER)

    // Staggered 2D array because a student asked about it
    // Staggered means every row doesn't necessarily have the same
    // number of columns.
    int** matrix;
    matrix = new int*[10];
    for(int r = 0; r < 10; r++){
        matrix[r] = new int[r+1];
        // Going to r+1 should make a sort of staircase staggered pattern
        // Just thought it would be fun
        for(int c =0; c < r+1; c++){
            matrix[r][c] = 0;
        }
    }
    //print the matrix
    for(int r = 0; r < 10; r++){
        for(int c =0; c < r+1; c++){
            cout << matrix[r][c] << ' ';
        }
        cout << endl;
    }
}