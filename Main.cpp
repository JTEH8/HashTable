#include <iostream>
#include <fstream>
#include <cstring>
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
    fstream firstNames;
    firstNames.open("FirstNames.txt");
    for(int i = 0; i<100; i++){
    char* firstName = new char[50];
    firstNames >> firstName;
    arr[i] = firstName;
    }

    fstream lastNames;
    lastNames.open("LastNames.txt");
}
