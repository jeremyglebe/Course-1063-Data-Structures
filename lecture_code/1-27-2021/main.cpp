#include <iostream>
using namespace std;

// TYPE * VAR -> Declares a pointer
// *VAR -> Dereferences a pointer (gets the object pointed to)
// VAR1 * VAR2 -> Multiplies two variables
// TYPE & VAR -> Declares a reference
// &VAR -> "Address of" operator, gets the address
// VAR1 & VAR2 -> "Bitwise AND"

int main() {
    // New integer of value 521
    int *nPtr = new int(521);
    // Print pointer and print object pointed to
    cout << "Pointer is stored at: " << &nPtr << '\n';
    cout << "Pointer is pointing to: " << nPtr << '\n';
    cout << "Value of object being pointed to: " << *nPtr << '\n';
    // Make sure to free memory!!!
    delete nPtr;

    // Ask how many characters should be in the array
    int numChars;
    cout << "How big should our array be? ";
    cin >> numChars;
    // Create dynamically allocated array
    char *chPtr;
    chPtr = new char[numChars];
    // Subscript operator, what is it?
    *(chPtr + 3) = 13; // Really ugly pointer arithmetic
    chPtr[3] = 14; // This is allowed! Subscript is an alias for the above

    // Pointing to existing variables
    char existingArr[200];
    char ch = 't';
    chPtr = existingArr; // array is already a pointer!
    chPtr = &ch; // get the address of ch
}

