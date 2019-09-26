


#include <iostream>

using namespace std;

class Assignment2
{
    public:
        Assignment2(); // constructor
        ~Assignment2(); // destructor
        Assignment2(int row, int column);


        void Grid();

    private: // instance variables

        int neighbors;
        int genNum;
        int row;
        int column;

        char** myGrid;

        //char** myGrid2;




};

// multidimensional arrays: https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/
