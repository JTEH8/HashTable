#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include "Student.h"

using namespace std;

struct Node{
 Student* student;
 Node* next;   
};

Student* generateStudent();

int main(){

}

Student* generateStudent(){
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
    char* studentFirst = arr[rand() %100 + 1];
    char* studentFirst = arr[rand() %100 + 1];

}
