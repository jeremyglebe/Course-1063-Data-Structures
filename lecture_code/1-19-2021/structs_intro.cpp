#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Syntax to create a struct, remember our struct ("BookRecord") is a TYPE. It is used as a TYPE.
// It is "aggregate", meaning it is a type made of other variables
struct BookRecord {
    string author;
    string title;
    int id;
    int pageCount;
};

// These prototypes show how to create functions that use structs
// It's just like any other type! (We aren't actually implementing these functions)
BookRecord createBook();
void printBook(BookRecord b);

int main() {
    // Example of creating a struct object from scratch
    // We declare a variable of type BookRecord
    BookRecord frankenstein;
    // We can specify the values of internal (member) variables with the "dot" operator
    frankenstein.author = "Mary Shelley";
    frankenstein.title = "Frankenstein; or The Modern Prometheus";
    frankenstein.id = 84336;
    frankenstein.pageCount = 300;

    // We can create arrays of our new type
    BookRecord library[10];
    // We can copy values from other objects of BookRecord type, like below comment
    // library[0] = frankenstein;

    // Here is an example of reading multiple records from a file
    // We open the file
    ifstream ifile("books.txt");
    int numBooks;
    // The first line of my input file tells me how many book records are available
    ifile >> numBooks;
    // I am going to read in some number of records
    for(int i = 0; i < numBooks; i++){
        // Read in a value for each member variable of our struct
        // (Make sure your input file's data is consistent with the order you read in)
        ifile >> library[i].title;
        ifile >> library[i].author;
        ifile >> library[i].id;
        ifile >> library[i].pageCount;
        // Or, if you want this to look prettier, we can do it in one line like the
        // below comment
        // ifile >> library[i].title >> library[i].author >> library[i].id >> library[i].pageCount;
    }
    // This loop will run twice, getting all 4 data items from both lines of input
    // Try modifying the input file to include more lines. What happens? (Make sure to change the
    // number at the top as well)

    // Now we will print the title and author of each book we read in
    for(int i = 0; i < numBooks; i++){
        cout << library[i].id << ": " << library[i].title << " by " << library[i].author << '\n';
    }
}