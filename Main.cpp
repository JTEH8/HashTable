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
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

void generateStudent(Node** HashTable, int temp, int &id, int size);
void ADD(Node* &head, Student* newStudent);
void PRINT(Node* head);
void DELETE(Student** list, int ID, int size);
int checkCollision(Node* head);
int hashFunction(Student* newStudent, int size);


int main(){
bool running = true;
char input[100];
int size = 11;
int randID = 0;
Node** HashTable = new Node*[size];
    
    for(int i = 0; i < size; i++){
        HashTable[i] = NULL;
    }

    while(running == true){
        cout << "Enter one of the following commands: ADD, DELETE, PRINT, GENERATE, or QUIT." << endl;
        cin >> input;
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
            Student* student = new Student(tempFirst,tempLast, tempID, tempGPA);
            ADD(HashTable[hashFunction(student, size)], student);

            for(int i = 0; i < size; i++){
                if(checkCollision(HashTable[i])> 3){
                    //Rehash the table
                    cout << "Rehash!" << endl;
                    break;
                }
            }   
            cout << "Succesfully added a student!" << endl;

        }
        else if(strcmp(input, "DELETE") == 0){
        }
        else if(strcmp(input, "PRINT") == 0){
            for(int i = 0; i < size; i++){
                PRINT(HashTable[i]);
            }
            cout << "Successfully printed the student list!" << endl;
        }
        else if(strcmp(input, "GENERATE") == 0){
            int num = 0;
            cout << "How many students do you want to add?" << endl;
            cin >> num;
            generateStudent(HashTable, num, randID, size);
        }
        else if(strcmp(input, "QUIT") == 0){
            cout << "Exiting Student List - Hash Table Edition." << endl;
            running = false;
        }
    }
    return 0;
}
void ADD(Node* &head, Student* newStudent){
    Node* current = head;
    if(current == NULL){
        head = new Node(newStudent);
    }
    else{
        while(current->getNext() != NULL){
            current = current->getNext();
        }
        current->setNext(new Node(newStudent));
    }
}

void PRINT(Node* head){
if(head != NULL){
    cout << (head->getStudent()->firstName) << " "
    << (head->getStudent()->lastName) << " "
    << "#" << (head->getStudent()->ID) << " "
    << fixed << setprecision(2) << (head->getStudent()->GPA) << endl;
    PRINT(head->getNext()); 
    }
}

void generateStudent(Node** HashTable, int temp, int &id, int size){
    char* arr[100];
    char* arr2[100];
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
    for(int i = 0; i < temp; i++){
    char* studentFirst = arr[rand() %100 + 1];
    char* studentLast = arr2[rand() %100 + 1];
    int studentID = rand() %8999 + 1000;
    //To generate a random float, help from https://www.tutorialspoint.com/how-do-i-generate-random-floats-in-cplusplus
    //Range== [0,4.0]    
    float max = 4.0;
    float studentGPA = float(rand())/float((RAND_MAX)* max);
    Student* temp2 = new Student(studentFirst,studentLast, studentID, studentGPA);
    ADD(HashTable[temp2, size], temp2);
    }

}
int hashFunction(Student* newStudent, int size){
    return newStudent->getID() % size;
}