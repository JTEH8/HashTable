#include "Node.h"
#include <cstring>
//Constructor
Node::Node(Student* newStudent){
student = newStudent;
next = NULL;
}

//Getters for GPA, ID, first name, and lat name.
Node* Node:: getNext(){
    return next;
}

void Node::setNext(Node* newNext){
    next = newNext;
}

Student* Node:: getStudent(){
    return student;
}

void Node::setStudent(Student* newStudent){
    student = newStudent;
}
//Destructor
Node::~Node(){

}