#include <iostream>
#include <string>
#include "List.h"
using namespace std;

void printScreen(List);

int main()
{
    List myList;
    char command = ' ';
    // When user enters Q, we exit the loop
    while (command != 'Q')
    {
        // Every time, re-prompt the user
        printScreen(myList);
        // Get user's command
        cin >> command;
        // Move the tracker forward
        if (command == 'F')
        {
            myList.trackForward();
        }
        // Reset the tracker to front of list
        else if (command == 'R')
        {
            myList.trackReset();
        }
        // Add new item to the list
        else if (command == 'A')
        {
            // Prompt user for data to add
            string nElement;
            cout << "Enter Element: ";
            cin >> nElement;
            myList.prepend(nElement);
            // Move to the newly created item
            myList.trackReset();
        }
        // Delete an item from the list
        else if (command == 'D')
        {
            // Prompt user for key of item to delete
            string fElement;
            cout << "Enter Key: ";
            cin >> fElement;
            myList.remove(fElement);
        }
    }
}

void printScreen(List theList)
{
    // Sort of a dumb way of clearing the screen
    cout << string(40, '\n');
    // Title card
    cout << "_________________________\n";
    cout << " |List Traversal System| \n";
    cout << "---------------------------------\n\n";
    // Print the value the tracker is currently pointing to
    if (theList.size() > 0)
    {
        cout << theList.getTracker();
    }
    else
    {
        cout << "[EMPTY LIST]";
    }
    // Get the next item so we can print a preview of it
    // This doesn't actually update the original object, because we passed a copy!
    theList.trackForward();
    // Print a preview of the next item, just the first 3 characters
    cout << " -> " << theList.getTracker().substr(0, 3) << "...\n\n";
    // Print a prompt to the user of what commands are available
    cout << "Enter a command:\n"
         << "[F] Move tracker forward; [R] Reset tracker to head of list\n"
         << "[A] Add an element; [D] Delete an element\n"
         << "[Q] Quit\n";
}