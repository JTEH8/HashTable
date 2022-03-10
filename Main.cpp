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
    char* temp = arr[rand() %100 + 1];
    /*
    for()
    char* studentLast = arr2[rand() %100 + 1];
    int studentID = rand() %8999 + 1000;
    //Help from here: https://stackoverflow.com/questions/45201838/c-generating-a-double-between-2-doubles in generating a random GPA
    //Range== 0,4.0 with 3 decimal places    
    double studentGPA = (double)(rand()%4100)/1000;
    Student* temp(temp,, studentID, studentGPA);
    return S;
    */
}
