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
    //Reads students.txt and assigns to struct, so forth. If can't open file, displays error. File should be stored in project folder.
    ifstream inputFile("students.txt");
    if (!inputFile)
    {
        cout << "Error opening file! Filename should be 'students.txt' and be placed in the program folder.\n\n";
        cout << "Please ensure the student data is structured like this:\n";
        cout << "Number of Students Number of tests\nStudentName IDnumber TestScores(Each score is separated by a space)\n\n";
        return 1;
    }
    
}

//reads filename "students.txt" that contains all info

student* getData(ifstream& file, int& studentCnt, int& testsCnt)
{
    file >> studentCnt >> testsCnt;

    student* students = new student[studentCnt];

    for (int i = 0; i < studentCnt; i++)
    {
        file >> students[i].name >> students[i].id;
        students[i].testScores = new double[testsCnt];
        for (int j = 0; j < testsCnt; j++)
        {
            file >> students[i].testScores[j];
        }
    }

    return students;
}