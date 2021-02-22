#include <iostream>
using namespace std;

class DynArray
{
public:
    // Construct a dynamic array of size sz
    DynArray(int sz)
    {
        // !!!IMPLEMENT THE CONSTRUCTOR, COMMENTS BELOW SERVE AS HINTS.!!!
        // Set the size

        // Create the internal "ordinary" array that holds our values

        // Initialize all values to 0 (0 is arbitrary, I just picked it)
    }

    // Function run when class is destroyed! (NO MEMORY LEAKS)
    ~DynArray(){
        // !!!IMPLEMENT THE DESTRUCTOR, AVOID MEMORY LEAKS.!!!
    }

    // Function to resize the array!
    void resize(int newsize)
    {
        // !!!IMPLEMENT THE RESIZE FUNCTION, COMMENTS BELOW SERVE AS HINTS.!!!

        // If the new size is the same, the array doesn't actually
        // need to be resized

        // If new size is bigger, we grow the array (by creating a new one
        // and copying values)
        // Keep a (temporary) pointer to the old array, we'll delete it later...

        // Create a new array for _realArray to point to

        // Copy all the values using a loop

        // Since the array is becoming larger, there are new ints which
        // have not been initialized. They are at indices size to newsize-1
        // Initialize these new integers using a loop.

        // Now that we've copied the values, delete the old array

        // If new size is smaller, shrink the array (truncate extra ints)
        // Start off the same as growing, create a temporary pointer

        // and a new array

        // Loop through ONLY the values you are copying (remember, i=size is
        // out of bounds since the new array is smaller)

        // Make sure not to leave any memory leaks

        // Update the "size" data member of the class
    }

    // Get a reference to integer at position i
    // Reference means they can update the value and it will update inside our
    // class's array as well!
    int &geti(int i)
    {
        // !!!THIS FUNCTION IS ALREADY IMPLEMENTED. DO NOT CHANGE.!!!
        return _realArray[i];
    }

    // Get the current size (number of elements) the array has
    int length()
    {
        // !!!THIS FUNCTION IS ALREADY IMPLEMENTED. DO NOT CHANGE.!!!
        return size;
    }

    // Prints the array is a nice manner, with brackets and commas
    void print()
    {
        // !!!THIS FUNCTION IS ALREADY IMPLEMENTED. DO NOT CHANGE.!!!
        if (size > 0)
        {
            cout << "[ " << _realArray[0];
            for (int i = 1; i < size; i++)
            {
                cout << ", " << _realArray[i];
            }
            cout << " ]\n";
        }
    }

private:
    // The following data members MUST exist in the class. You must not remove
    // them. If you feel you need to, you may add additional variables.
    int *_realArray;
    int size;
};

int main()
{
    // !!!DO NOT MODIFY MAIN. YOUR OBJECTIVE IS TO IMPLEMENT THE ABOVE CLASS.
    // CHANGES TO MAIN DO NOT SATISFY THIS REQUIREMENT.!!!
    const int TEST_SIZE = 15;
    DynArray cool(TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        cool.geti(i) = 2 * TEST_SIZE - 2 * i;
    }
    cool.print();
    cool.resize(cool.length() / 2);
    cool.print();
    cool.resize(cool.length() + 3);
    cool.print();
    cool.resize(cool.length());
    return 0;
}