/*
Author: Jeffrey Teh
Date: 3/13/22
This is an implementation of a student list, but using a hash table
Done with help from Ruby Amyeen and Nathan Zou
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

//Function Prototypes

Student* generateStudent();
void ADD(Node* &head, Student* newStudent);
void PRINT(Node* head);
void DELETE(Node*&head, Node* current, Node* previous, int studentID);
int checkCollision(Node* head);
int hashFunction(Student* newStudent, int size);
void rehash(Node** &HashTable, Node* head, int size);

//Main Method
int main(){
//initiating variables
bool running = true;
char input[100];
int size = 11;
int randID = 0;
Node** HashTable = new Node*[size];
//setting HashTable to NULL    
    for(int i = 0; i < size; i++){
        HashTable[i] = NULL;
    }
    //While program is running
    while(running == true){
        //Prompt text
        cout << "Enter one of the following commands: ADD, DELETE, PRINT, GENERATE, or QUIT." << endl;
        cin >> input;
        //If the user adds a student
        if(strcmp(input, "ADD") == 0){
            cout << "You're adding a new student!" << endl;
            cout << "Enter their name." << endl;
            char* tempFirst = new char[100];
            cin >> tempFirst;
            cout << "Enter their lastname." << endl;
            char* tempLast = new char[100];
            cin >> tempLast;
            cout << "Enter their student ID." << endl;
            int tempID = 0;
            cin >> tempID;
            cout << "Enter their GPA." << endl;
            float tempGPA = 0;
            cin >> tempGPA;
            //Create a temp student and add it to the Hash Table
            Student* student = new Student(tempFirst,tempLast, tempID, tempGPA);
            ADD(HashTable[hashFunction(student, size)], student);
            //Check to see if there's a collision
            for(int i = 0; i < size; i++){
                if(HashTable[i] != NULL){
                if(checkCollision(HashTable[i])> 3){
                    size *= 2;
                    //Create a temporary empty table
                    Node** temp = new Node*[size];
                    for(int i = 0; i < size; i++){
                     temp[i] = NULL;
                    }
                    //Rehash the table
                    for(int i = 0; i < size/2; i++){
                        rehash(temp, HashTable[i], size);
                    }   
                    cout << "The table has been rehashed!" << endl;
                    for (int i = 0; i < size/2; i++) {
                        HashTable[i]->~Node();
                    }
                //Delete the old table
	            HashTable = new Node*[size];
	            HashTable = temp;
	            delete[] temp;
	            break;
                }
            }
        }   
            cout << "Succesfully added a student!" << endl;
        }
        //When the user deletes a student
        else if(strcmp(input, "DELETE") == 0){
            int deleteID = 0;
            cout << "Enter the ID of the Student you're deleting" << endl;
            cin >> deleteID;
            for(int i = 0; i < size; i++){
                DELETE(HashTable[i],HashTable[i],HashTable[i],deleteID);
            }
            cout << "Student succesfully deleted" << endl;
        }
        //When the user prints the student list
        else if(strcmp(input, "PRINT") == 0){
            for(int i = 0; i < size; i++){
                PRINT(HashTable[i]);
            }
            cout << "Successfully printed the student list!" << endl;
        }
        //Generating random students
        else if(strcmp(input, "GENERATE") == 0){
            int num = 0;
            cout << "How many students do you want to add?" << endl;
            cin >> num;
            for(int i = 0; i < num; i++){
            Student* temp = generateStudent();
            ADD(HashTable[hashFunction(temp, size)], temp);            
            }
        }
        //Quitting the program
        else if(strcmp(input, "QUIT") == 0){
            cout << "Exiting Student List - Hash Table Edition." << endl;
            running = false;
        }
    }
    return 0;
}
//Add me thod
void ADD(Node* &head, Student* newStudent){
    Node* current = head;
    //If the current node is NULL
    if(current == NULL){
        //Add as tudent to the head node
        head = new Node(newStudent);
    }
    else{
        while(current->getNext() != NULL){
            current = current->getNext();
        }
        current->setNext(new Node(newStudent));
    }
}
//Print the students in the linked list
void PRINT(Node* head){
if(head != NULL){
    cout << (head->getStudent()->firstName) << " "
    << (head->getStudent()->lastName) << " "
    << "#" << (head->getStudent()->ID) << " "
    << fixed << setprecision(2) << (head->getStudent()->GPA) << endl;
    PRINT(head->getNext()); 
    }
}
//Delete a student
void DELETE(Node*&head, Node* current, Node* previous, int studentID){
    if(head == NULL){
    return;
    }
    else if(current == NULL){
        return;
    }
    //If the entered id matches
    else if(studentID == current->getStudent()->getID()){
        //If the head node has the student who should be deleted
        if(studentID == head->getStudent()->getID()){
           Node* temp = head;
           head = head->getNext();
           //Deete t
           temp->~Node(); 
        }
        //If it's another node
        else{
            previous->setNext(current->getNext());
            current->~Node();    
        }
        }
        else{
            DELETE(head, current->getNext(), current, studentID);
    }
}
//Generating a random student
Student* generateStudent(){
    char* arr[100];
    char* arr2[100];
    //Filling two arrays with the names from text files
    fstream firstNames;
    firstNames.open("FirstNames.txt");
    for(int i = 0; i<100; i++){
    char* firstName = new char[50];
    firstNames >> firstName;
    arr[i] = firstName;
    }
    fstream lastNames;
    lastNames.open("LastNames.txt");
    for(int j = 0; j<100; j++){
    char* lastName = new char[50];
    lastNames >> lastName;
    arr2[j] = lastName;
    }
    //Pulling random names from the text files
    char* studentFirst = arr[rand() %100 + 1];
    char* studentLast = arr2[rand() %100 + 1];
    int studentID = rand() %8999 + 1000;
    //To generate a random float, help from https://www.tutorialspoint.com/how-do-i-generate-random-floats-in-cplusplus
    //Range== [0,4.0]    
    float max = 4.0;
    float studentGPA = (float(rand())/float((RAND_MAX)) * max);
    //Rounding that number to 2 decimal places
    studentGPA = roundf(studentGPA * 100) / 100;
    //Returning that student
    Student* temp2 = new Student(studentFirst,studentLast, studentID, studentGPA);
    return temp2;
}
//Rehashing the table
void rehash(Node** &HashTable, Node* head, int size){
    if(head != NULL){
        ADD(HashTable[hashFunction(head->getStudent(), size)], head->getStudent());
        rehash(HashTable, head->getNext(), size);
    }
}
//Hashing it by getting the modulus of the student id by the size
int hashFunction(Student* newStudent, int size){
    return newStudent->getID() % size;
}
//Checking for collisions and counting 
int checkCollision(Node* head){
    int collisionCount = 0;
    Node* current = head;
    while(current->getNext() != NULL){
        collisionCount++;
        current = current->getNext();
    }
    return collisionCount;
}