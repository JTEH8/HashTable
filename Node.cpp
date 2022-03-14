#include "Node.h"
#include <cstring>
//Constructor
Node::Node(Student* newStudent){
student = newStudent;
next = NULL;
}

//Getters and Setters for Next Nodes and Student data
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