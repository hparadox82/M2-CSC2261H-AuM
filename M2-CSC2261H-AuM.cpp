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

    int studentCnt, testsCnt;
    student* students = getData(inputFile, studentCnt, testsCnt);
    inputFile.close();


    calcAverage(students, studentCnt, testsCnt);
    printReport(students, studentCnt);

    // Clean up dynamically allocated memory
    for (int i = 0; i < studentCnt; i++)
    {
        delete[] students[i].testScores; //Delete loops for each iteration of student data to ensure proper deallocation
    }
    delete[] students;
    return 0;
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

//calculates average test scores for students, sends it off to be "converted" into a letter grade to the calculateLetterGrade function below.
void calcAverage(student students[], int studentCnt, int testsCnt)
{
    for (int i = 0; i < studentCnt; i++)
    {
        double sum = 0;
        for (int j = 0; j < testsCnt; j++)
        {
            sum += students[i].testScores[j];
        }
        students[i].average = sum / testsCnt;
        students[i].grade = calculateLetterGrade(students[i].average);
    }
}

//assigns a corresponding letter to the average test score received, returns to main function
char calculateLetterGrade(double average)
{
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

//Prints the report consisting of student name, ID, test score and assigned letter grade.
void printReport(const student students[], int studentCnt) {
    cout << left << setw(15) << "Student" << setw(10) << "ID" << setw(10) << "Score" << "Grade" << endl;
    for (int i = 0; i < studentCnt; i++)
    {
        cout << left << setw(15) << students[i].name << setw(10) << students[i].id << setw(10) << fixed << setprecision(1) << students[i].average << students[i].grade << endl;
    }
}