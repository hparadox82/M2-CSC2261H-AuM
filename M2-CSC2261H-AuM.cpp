// M2-CSC2261H-AuM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Project 1: Reverse array: Write a function that accepts an int array and the array�s size as arguments. 
// The function should create a copy of the array, except that the element values should be reversed in the copy. 
// The function should return a pointer to the new array. Demonstrate the function in a complete program

#include <iostream>
using namespace std;

//Function prototypes
int* revArray(const int arr[], int size);
void print(const int arr[], int size);


int main()
{
    //Declares array/size/values.
    const int size = 10;
    int origArray[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    //Displays the array in normal order:
    print(origArray, size);

    //(reverses array)
    int* nuArray = revArray(origArray, size);

    //Prints reversed array:
    print(nuArray, size);

    //Deallocates memory held.
    delete[] nuArray;

    return 0;
}

int* revArray(const int arr[], int size) //reverse array function, copies generated array and reverses order as pointer for main funct to access
{
    int* nuArray = new int[size];
    for (int i = 0; i < size; ++i)
    {
        nuArray[i] = arr[size - i - 1];
    }
    return nuArray;
}
void print(const int arr[], int size) //display function, takes specified array and displays it
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << "";
    }
    cout << endl;
}