#include <iostream>
#include <string>
using namespace std;

// Enums are another custom type
enum Classification{FRESHMAN, SOPHOMORE, JUNIOR, SENIOR};

struct Student{
    string name{"N/A"};
    float gpa{0.0};
    int id{0};
    Classification c;
};

struct Course{
    string title;
    string subject;
    int code;
    Student students[30];
};

void printStudent(Student student);
void printCourse(Course course);
Student promptForStudent();

int main() {
    // Enums are just ints with limited range, try printing them
    cout << FRESHMAN << ' ' << SOPHOMORE << ' ' << JUNIOR << ' '  << SENIOR << '\n';
    // This is an initializer list, you've seen them with arrays
    int arr[] = {5, 94, -3, 6, 7845};
    // We can initialize a struct the same way
    Student bob = {"Robert", 2.8, 99998876, SENIOR};
    printStudent(bob);
    // Use those default values
    Student jeremy;
    printStudent(jeremy);
    // Create a course, which has a nested struct
    // We can use initializer lists inside of other initializer lists
    // and break them apart over multiple lines
    // Isn't it cool?
    Course dataStructures = {
        "Data Structures & ADT",
        "Computer Science",
        1063,
        {
            // {"William", 0.8, 12121212},
            // {"Angel", 3.7, 91235478},
            // {"Rachel", 4.5, 8888888}
        }
    };
    // For loop to add students
    for(int i = 0; i < 5; i++){
        dataStructures.students[i] = promptForStudent();
    }
    // Let's use our print function
    printCourse(dataStructures);
}

void printStudent(Student student){
    cout << student.id << "    " << student.name << "    " << student.gpa << ' ';
    switch(student.c){
        case FRESHMAN: cout << "Freshman";
        break;
        case SOPHOMORE: cout << "Sophomore";
        break;
        case JUNIOR: cout << "Junior";
        break;
        case SENIOR: cout << "Senior";
        break;
    }
    cout << '\n'; 
}

void printCourse(Course course){
    cout << string(120, '*') << '\n';
    cout << course.title << '\n';
    cout << course.subject << ' ' << course.code << '\n';
    for(int i = 0; i < 30; i++){
        // Nested function calls, useful!
        printStudent(course.students[i]);
    }
    cout << string(120, '*') << '\n';
}

Student promptForStudent(){
    Student newStudent;
    cout << "Enter student name, gpa, id: ";
    cin >> newStudent.name >> newStudent.gpa >> newStudent.id;
    return newStudent;
}