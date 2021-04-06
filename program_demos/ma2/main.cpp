#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"
#include "Storybook.h"
using namespace std;

void printPage(Page *page);

int main()
{
    // Storybook read from a file
    Storybook fileStory("book.txt");
    // Stack which tracks the path the user has taken
    Stack path;
    // User's command each iteration stored here
    char command = ' ';
    // Ask the user for a scary monster
    string scaryMonster;
    cout << "Name a flying monster that is *really* scary. ";
    cin >> scaryMonster;
    // Lowercase the monster
    for (int i = 0; i < scaryMonster.size(); i++)
    {
        scaryMonster[i] = tolower(scaryMonster[i]);
    }
    // Find and replace instances of $DRAGON with the monster of choice
    fileStory.findAndReplace("$DRAGON", scaryMonster);
    // Add the first page to the stack
    path.push(0);
    // Start the reading loop
    while (command != 'q' && command != 'Q')
    {
        // Get the current page
        Page *peekPage = fileStory.getPage(path.peek());
        // Print the page
        printPage(peekPage);
        // Get the user's command
        cin >> command;
        // If the command is 'q' or 'Q', we let them know the book is ending
        if (command == 'q' || command == 'Q')
        {
            cout << "Thanks for reading! Bye!\n";
        }
        // If the command is to go to the previous page, do that
        else if (command == 'p' || command == 'P')
        {
            // Remove the last page visited
            path.pop();
            // Make sure the path isn't empty for next iteration
            if (path.empty())
                path.push(0);
        }
        // If the command is numeric, it might be a command
        // (Also check that it is less than the number of choices)
        else if (command >= '0' && command <= '9' && command - '0' < peekPage->getNumChoices())
        {
            // Add the choice's "nextIndex" to the path
            path.push(peekPage->getChoice(command - '0')->getNextIndex());
        }
        // Any other conditions means the input is invalid
        else
        {
            cout << "Use a real input! C'mon! You had one job!\n";
        }
    }
}

void printPage(Page *page)
{
    cout << string(20, '\n');
    cout << page->getBody() << "\n\n";
    for (int ch = 0; ch < page->getNumChoices(); ch++)
    {
        cout << '[' << ch << "] " << page->getChoice(ch)->getBody() << '\n';
    }
    cout << "[P] Previous Page\n[Q] Quit Reading\n";
    cout << flush;
}