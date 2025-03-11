// M2-CSC2261H-AuM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Project 2: Course Book Program

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Define the student struct
struct student {
    string name;
    int id;
    double* testScores;
    double average;
    char grade;
};

// Function prototypes
student* getData(ifstream& file, int& studentCnt, int& testsCnt);
void calcAverage(student students[], int studentCnt, int testsCnt);
void printReport(const student students[], int studentCnt);
char calculateLetterGrade(double average);

int main()
{
    std::cout << "Hello World!\n";
}

