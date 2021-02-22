#include <iostream>
#include <string>
using namespace std;

// Struct student is a simple struct
struct Student{
    int id;
    string name;
    float gpa;
};

// Struct course contains an array of struct students
struct Course{
    string title;
    string topic;
    int code;
    Student students[30];
};

// Prototypes to print students and courses
void printStudent(Student s);
void printCourse(Course c);

int main() {
    Student jeremy = {1000000, "Jeremy Glebe", 3.87};
    printStudent(jeremy);
    // i list for Course struct
    Course ds = {
        "Data Structures & ADT",
        "Computer Science",
        1063,
        // i list for array of students
        {
            // i lists for single student structs
            {45454545, "Yoseph", 0.2},
            {19999996, "Wes", 4.0},
            {32323215, "Dylan", 2.8}
        }
    };
    // Reading this from a file would be really ugly
    // fin >> ds.students[i].id;
    printCourse(ds);

    // c string are HORRIBLE
    // char myString[100];
}

// Simple function to print students
void printStudent(Student theStudent){
    cout << theStudent.id << ", " << theStudent.name << ": " << theStudent.gpa << '\n';
}

// Function to print an entire course
void printCourse(Course c){
    // Print the course info
    cout << c.topic << ' ' << c.code << ": " << c.title << '\n';
    // Loop through all the students and print them
    for(int i = 0; i < 30; i++){
        printStudent(c.students[i]);
    }
}