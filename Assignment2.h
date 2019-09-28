#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

#include <iostream>

using namespace std;

class Assignment2
{
    public:
        Assignment2(); // constructor
        ~Assignment2(); // destructor
        Assignment2(int row, int column);


        void printGrid();

    private: // instance variables

        int neighbors;
        int genNum;
        int row;
        int column;

        char** myGrid;

        char** myGrid2;




};

#endif

// multidimensional arrays: https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/
