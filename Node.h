//Header Guard
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;
//Node Class
class Node{
public:
//Variables
Student* student;
Node* next;
//Constructor
Node(Student* newStudent);
//Destructor
~Node();
//Getters and Setters for Nodes
Node* getNext();
void setNext(Node* newNext);
//Getters and setters for Student data
Student* getStudent();
void setStudent(Student* newStudent);
};

#endif