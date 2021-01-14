#include <iostream>
#include <string>
using namespace std;

float sum(float arr[], int size);
int sum(int arr[], int size);
// These are the prototypes, definitions are farther down
void showInBox(int n);
// Note that we have overloaded these functions, they all have the same name!
void showInBox(double d);
// The 'void' return type means that nothing will be returned from these
void showInBox(string s);
// 'int' and 'double' are our parameter types which, along with the identifier,
// form the signature that the compiler uses to find a function.
void showInBox(int n, double d);

int main()
{
    // Creating arrays
    int narray[5] = {1, 2, 3, 4, 5};
    // Floats are fine! They use less memory.
    float farray[4] = {4.3, 2.5, 1.89, 4.22};
    // Calling overloaded function sum, the compiler will know which to use
    // based on the arguments we pass to the function
    float nsum = sum(narray, 5);
    // Explicit cast of float value to double because one of our functions
    // has "double" not "float" as a parameter. We could let it implicitly
    // convert by just passing the float in, and it would work fine here.
    // But being explicit in code is usually a good thing.
    double fsum = (double)sum(farray, 4);
    // Lots of overloaded functions being called here, see how smart C++ is?
    showInBox(nsum);
    showInBox(fsum);
    showInBox(nsum, fsum);
    // Neat trick for repeating characters.
    // This means the character 'A' repeated 80 times.
    cout << string(80, 'A') << '\n';
}

// Definitions for the overloaded array sum functions
float sum(float arr[], int size)
{
    // Variable to accumulate sum
    float total = 0;
    // For loop that runs for each item in the array
    // "size" must be passed in to function
    for (int i = 0; i < size; i++)
    {
        // This adds the number at the correct index to total
        total += arr[i];
    }
    // Replace the function call with this value
    return total;
}
int sum(int arr[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    return total;
}

// These are the definitions for the overloaded box printing functions
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