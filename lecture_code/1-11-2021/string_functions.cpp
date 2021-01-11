#include <iostream>
#include <string>
using namespace std;

// These are "prototypes" which tell the compiler what a functions looks like
// before it is defined
string promptUser();
void printName(string n);

int main()
{
    // string name = promptUser();
    // printName(name);
    // Shorter version of the above commands
    printName(promptUser());
    return 0;
}

// This function prompts the user for their name and returns it as a string
string promptUser()
{
    // Variable of type string
    string myName;
    // Prompt provided to user through cout
    cout << "What is your name? ";
    // cin allows the user to respond to the prompt
    // and stores their response in a variable
    cin >> myName;
    // Return statement replaces the function call with the specified value
    return myName;
}

// This function prints a message about the user's name.
// The user's name is passed in as a string.
void printName(string theString)
{
    // Prints the message.
    cout << "Oh? Your name is " << theString << "? That's a funny name.\n";
    // Use stringVariable.size() to get the number of characters in a string
    for (int i = 0; i < theString.size(); i++)
    {
        // Strings can be indexed, EXACTLY like arrays
        cout << i << ": " << theString[i] << '\n';
    }
}