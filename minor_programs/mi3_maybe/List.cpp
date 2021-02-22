#include "List.h"

List::List()
{
    // Construct List by setting both pointers to NULL initially
    head = NULL;
    tracker = NULL;
}

int List::size() { return count; }

void List::prepend(string element)
{
    // Insert an item at the front of the list
    // Use a temporary pointer to create new memory
    Node *temp = new Node;
    // Set the data of the new object
    temp->data = element;
    // Point the new node to the head of the list
    temp->next = head;
    // Update the head of the list to be the new node
    head = temp;
    // Increase the counter for size of list
    count++;
    // Confused? Draw out the algorithm!
}

void List::remove(string key)
{
    // The "trail" pointer will traverse the list
    Node *trail = head;
    // First, check if the head of the list matches the delete key
    if (head && head->data == key)
    {
        // If we're deleting head, and the tracker points to the same
        // location, we need to update the tracker
        if (tracker == head)
        {
            tracker = head->next;
        }
        // Update the head before deletion
        head = head->next;
        // Delete "trail", which still points to the old head
        delete trail;
        // Decrease the counter which tracks number of items
        count--;
    }
    else
    {
        // A flag to determine if we have found the key
        bool found = false;
        // Go until we find the key or there is no further items
        while (!found && trail->next)
        {
            // Test is the NEXT node, because we need to stay one
            // element back for re-linking (draw out the algorithm!)
            Node *test = trail->next;
            // If the next node matches the key, we'll delete it
            if (test->data == key)
            {
                // First, set our flag
                found = true;
                // Then, re-link trail to the item after test
                // This effectively removes "test" from the list
                trail->next = test->next;
                // Update our tracker variable for the menu, if needed
                if (tracker == test)
                {
                    tracker = test->next;
                }
                // Delete the object that has been removed from the list
                delete test;
                // Decrease the counter which tracks number of items
                count--;
            }
            else
            {
                // If we haven't yet found the key, check the next item
                trail = trail->next;
            }
        }
    }
}

string List::getHead()
{
    // If head exists, return the data
    if (head)
        return head->data;
    // Otherwise return an empty string
    else
        return "";
}
string List::getTracker()
{
    // If tracker is not NULL, return the data
    if (tracker)
        return tracker->data;
    // Otherwise return an empty string
    else
        return "";
}

void List::trackForward()
{
    // Move our tracker (used by the menu) forward one item
    // Don't move it if it's already NULL
    if (tracker)
    {
        tracker = tracker->next;
    }
}

void List::trackReset()
{
    // Reset the tracker (used by the menu) to the head of the list
    tracker = head;
}
