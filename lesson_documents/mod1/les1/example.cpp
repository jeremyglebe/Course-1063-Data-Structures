#include <iostream>
#include <string> // This is how we include the string class!
using namespace std;

int main()
{
    string username; // This is how we declare a string,
                     // no different from a regular variable!
    cout << "What is your name? ";
    cin >> username; // We can get strings from the keyboard.
    cout << "Oh, your name is "
         << username // We can print strings just like other variables.
         << "? That's kind of funny!\n";
}