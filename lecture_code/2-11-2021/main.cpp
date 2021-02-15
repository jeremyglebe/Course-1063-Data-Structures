#include <iostream>
#include <string>
using namespace std;

// Just a simple struct
struct Student{
    string name;
    string major;
    float gpa;
};

// Course contains an array of student pointers
// The students are pointers so multiple classes can contain the same students
class Course{
public:
    // Constructor function runs when we create a Course variable
    Course(string n, int c, int sz){
        // Assign members from parameters
        name = n;
        code = c;
        size = sz;
        // This counts how many Student variables are actually in the array
        counter = 0;
        // The array of student pointers forming the members of the course
        members = new Student*[size];
        // All the pointers should initially point to nothing
        for(int i = 0; i < size; i++){
            members[i] = nullptr;
        }
    }
    // Copyies an existing student pointer into the array of students
    // (Copies the POINTER, but the OBJECT is the same)
    void addStudent(Student* student){
        members[counter] = student;
        counter++;
    }
    // Creates a new student object and adds a pointer to it in the array
    // addStudent() is overloaded! This gives us multiple ways to use it.
    void addStudent(string name, string major, float gpa){
        members[counter] = new Student;
        members[counter]->name = name;
        members[counter]->major = major;
        members[counter]->gpa = gpa;
        counter++;
    }

    // Prints the course and all it's information
    void print(){
        cout << code << ' ' << name << ":\n";
        // We have both the current number of students and the max size of the class
        cout << "\tClass Size: " << counter << " (max " << size << ") " << '\n';
        // print each of the students in the course
        cout << "\tClass:\n";
        for(int i = 0; i < size; i++){
            if(members[i] != nullptr){
                // The following two statements are equivalent
                // cout << "\t\t" << (*members[i]).name;
                // cout << "\t\t" << members[i]->name;
                // Arrow operator is a shortcut for dereference + dot operator
                cout << "\t\t" << members[i]->name;
                cout << ", " << members[i]->major << '\n';
            }
        }
    }
private:
    // Here is where our data members are first declared, though not given values
    string name;
    int code;
    int size;
    int counter;
    Student** members;
};

int main() {
    // Creating a data structures course
    Course ds("Data Structures", 1063, 20);
    ds.print();
    // Two ways of adding students
    ds.addStudent("Jeremy", "Computer Science", 0.05);
    Student* sptr = new Student;
    sptr->name = "Kelly";
    sptr->major = "Mathematics";
    sptr->gpa = 4.0;
    ds.addStudent(sptr);
    // Print the course with students in it
    ds.print();

    // Calculus course shares one student with Data Structures
    Course calc("Calculus II", 666, 30);
    // The shared student
    calc.addStudent(sptr);
    // Some new students
    calc.addStudent("Jaden", "Mathematics", 1.3);
    calc.addStudent("Tina", "Mathematics", 3.6);
    // Let's print the class and see
    calc.print();
}