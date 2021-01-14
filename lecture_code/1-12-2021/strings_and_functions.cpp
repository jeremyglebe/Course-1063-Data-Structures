#include <iostream>
#include <string>
using namespace std;

// Function prototypes
string promptUser();
void printName(string name = "Joe");
// Overloaded functions share an identifer with different parameters,
// like the sum() functions below.
int sum(int arr[3]); // Signature could be sumINTARRAY
double sum(double arr[3]); // Signature could be sumDOUBLEARRAY

int main() {
    // string myName = promptUser();
    // printName(myName);
    // This statement is equivalent to the above commented out code
    // Remember promptUser() is "replaced" with it's return
    printName(promptUser());
    // printName is not overloaded, but it includes a "default" argument
    // So when we pass in no arguments, it uses that.
    printName();

    // Explicit typecast will truncate the value of d when stored in n
    double d = 55.9;
    int n = (int)d;

    // Createing arrays of doubles and ints
    double darr[3] = {42.42, 0.111111, -3.0};
    int narr[3] = {1,2,3};
    // Using overloaded functions, compiler will choose the
    // best option based on arguments provided
    cout << sum(darr) << '\n';
    cout << sum(narr) << '\n';
}

// Prompts the user for their name and returns it as a string
string promptUser(){
    string theName;
    cout << "What is your name? ";
    cin >> theName;
    return theName;
}

// Prints some stuff about a name, including the size of the name string
// and a vertical print of the name
void printName(string name){
    cout << "Oh, your name is " << name << "? That's a funny name!\n";

    cout << name.size() << '\n';

    for(int i = 0; i < name.size(); i++){
        cout << name[i] << '\n';
    }
}

// Sums the values in an integer array (of size 3)
int sum(int arr[3]){
    int total = 0;
    for(int i = 0; i < 3; i++){
        total += arr[i];
    }
    return total;
}
// Sums the values in a double array (of size 3)
double sum(double arr[3]){
    double total = 0;
    for(int i = 0; i < 3; i++){
        total += arr[i];
    }
    return total;
}