// We're going to define two functions, and one of them will be overloaded
// First we'll make showInBox(), which will print a variable in a neat little
// box. Then we'll define square() which will accept an integer and return the
// number squared. showInBox() will be overloaded to print multiple types of
// variables.

#include <iostream>
#include <string>
using namespace std;

// These are the prototypes, definitions are farther down
void showInBox(int n);
// Note that we have overloaded these functions, they all have the same name!
void showInBox(double d);
// The 'void' return type means that nothing will be returned from these
void showInBox(string s);
// 'int' and 'double' are our parameter types which, along with the identifier,
// form the signature that the compiler uses to find a function.
void showInBox(int n, double d);

// We'll create one function with a return type, just to show it off
int square(int n);

int main()
{
    // 999, 42.42, "Hello!", 10, and 1.5 are all considered arguments
    showInBox(999);
    showInBox(42.42);
    showInBox("Hello!");
    showInBox(10, 1.5);
    // Let's get 5 squared, should be 25, right?
    int sq = square(5);
    // We could print with cout, but let's use our cool box function instead!
    showInBox(sq);
    // Note that the main function returns 0, this is actually a code for the
    // operating system to use, it tells it that the program ended correctly!
    return 0;
}

// Definition for our square function
int square(int n)
{
    // We "return" n * itself, or the square
    // This value will be used wherever the function call occured in main()
    return n * n;
}

// These are the definitions for the overloaded functions
void showInBox(int n)
{
    // Turn the integer into a string (because we can count the characters in
    // the string, useful for drawing a box!)
    string var = to_string(n);
    // Get the number of characters in the string and add 2 (because the box
    // goes AROUND the variable)
    int size = var.size() + 2;
    // This prints a string made of a number of dashes equal to size,
    // it's a pretty cool trick!
    cout << string(size, '-') << '\n';
    // Print the sides of the boxes with the variable in the middle
    cout << '|' << var << "|\n";
    // Same as up above
    cout << string(size, '-') << '\n';
    // All the other functions are pretty much going to look like this.
}
void showInBox(double d)
{
    string var = to_string(d);
    int size = var.size() + 2;
    cout << string(size, '-') << '\n';
    cout << '|' << var << "|\n";
    cout << string(size, '-') << '\n';
}
void showInBox(string s)
{
    int size = s.size() + 2;
    cout << string(size, '-') << '\n';
    cout << '|' << s << "|\n";
    cout << string(size, '-') << '\n';
}
void showInBox(int n, double d)
{
    string var = to_string(n * d);
    int size = var.size() + 2;
    cout << string(size, '-') << '\n';
    cout << '|' << var << "|\n";
    cout << string(size, '-') << '\n';
}
