#include <string>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

class List
{
public:
    List();
    // Gets the current size (# of nodes) of the list
    int size();
    // Add an item to the start of the list
    void prepend(string element);
    // Find and remove an item from the list
    void remove(string key);
    // Get the first value in the list
    string getHead();
    // Get value at tracker (used for display in the menu)
    string getTracker();
    // Move the tracker (used for display in the menu)
    void trackForward();
    void trackReset();

private:
    // First item in the list
    Node *head;
    // Counter to track number of items
    int count = 0;
    // Tracker used for display in the menu
    Node *tracker;
};