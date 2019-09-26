#include "Assignment2.h"
#include <iostream>

using namespace std;
// this class is used for grid implementation
Assignment2::Assignment2() // no-arg constructor
{
    row = 5; // initialize empty 2d array
    column = 4;
    neighbors = 0;
    genNum = 0;
    myGrid = new char*[row];
    for(int i = 0; i < row; i++)
    {
        myGrid[i] = new char[column];
        for(int j = 0; j < column; j++)
        {
            myGrid[i][j] = '-';
        }
    }
}
Assignment2::~Assignment2() // destructor
{
    cout << "Object deleted." << endl;
}

Assignment2::Assignment2(int row, int column)
{
    neighbors = 0;
    genNum = 0;
    myGrid = new char*[row];
    for(int i = 0; i < row; i++)
    {
        myGrid[i] = new char[column];
        for(int j = 0; j < column; j++)
        {
            myGrid[i][j] = '-';
        }
    }
}



void Assignment2::Grid()
{
    myGrid = new char*[row];
    for(int i = 0; i < row; i++)
    {
        myGrid[i] = new char[column];
        for(int j = 0; j < column; j++)
        {
            cout << myGrid[i][j] << " ";
        }
        cout << "\n" << endl;
    }
}
