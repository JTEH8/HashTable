#include "Student.h"
#include <cstring>
//Constructor
Student::Student(char* firstname, char* lastname, int id, float gpa){
strcpy(firstName, firstname);
strcpy(lastName, lastname);
ID = id;
GPA = gpa;
}

Student::~Student(){

}
//Getters for GPA, ID, first name, and lat name.
float Student::getGPA(){
    return GPA;
}

int Student::getID(){
    return ID;
}

char* Student::getFirstName(){
    return firstName;
}

char* Student::getLastName(){
    return lastName;
}
