#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Enums are one example of a "custom type". They are essentially ints with limited range
// and special names for each value.
// enum StudentClass {FRESHMAN, SOPHOMORE, JUNIOR, SENIOR};

// Structs are also a custom type, they're "aggregates" meaning that they have
// multiple internal ("member") variables.
struct student_record {
    string name;
    float gpa;
    // It might actually be BETTER to use an enum here...
    // StudentClass classification;
    int classification;
};

// A function which accepts a student record
void printStudent(student_record student);

int main() {
    // Simple example of creating a single record from our struct
    // student_record bob;
    // bob.name = "Robert";
    // bob.gpa = 2.8;
    // bob.classification = 1;
    // cout << "My name is " << bob.name << '\n';
    // printStudent(bob);

    // Opening a data file
    ifstream nfile("input.txt");
    int numStudents;
    nfile >> numStudents; // First thing in this file is number of entries
    // Records can be stored into an array
    // Number of students shouldn't exceed this number, we're assuming
    student_record msutexas[100000];
    // Read in each entry from the file
    for(int i = 0; i < numStudents; i++){
        // Each line/entry contains name, gpa, class
        nfile >> msutexas[i].name;
        nfile >> msutexas[i].gpa;
        nfile >> msutexas[i].classification;
        // Let's go ahead and use our print function
        printStudent(msutexas[i]);
    }
}

void printStudent(student_record student){
    // Print the first two internal variables (members) easily
    cout << "Student Name: " << student.name << '\n';
    cout << "Student GPA: " << student.gpa << '\n';
    // Classification is a bit more complicated, we would like to print
    // a word based on the value of the classification
    cout << "Student Classification: ";
    if(student.classification == 0){
        cout << "Freshman" << '\n';
    } 
    else if(student.classification == 1){
        cout << "Sophomore" << '\n';
    }
    else if(student.classification == 2){
        cout << "Junior" << '\n';
    }
    else if(student.classification == 3){
        cout << "Senior" << '\n';
    }
    // Just in case value is incorrect...
    else{
        cout << "ERROR" << '\n';
    } 
}