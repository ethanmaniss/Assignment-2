#include "Assignment2.h"
#include <iostream>

using namespace std;

int main()
{
    int x = 5;
    int y = 4;

    char grid[x][y] = {{'X','-','-','X'}, {'-','-','X','-'}, {'X','X','X','X'}, {'-','-','X','-'}, {'-','-','X','-'}};
    for(int i = 0; i < x; i++) // traverse through rows
    {
        for(int j = 0; j < y; j++) // traverse through columns
        {
            //cout << "char at x[" << i << "] [" << j << "] : " << endl;

            cout << grid[i][j] << " ";

        }
        cout << "\n" << endl; // new line for next row iterated through
    }
    //Assignment2 a2;
    //a2.Grid();
    //delete a2;




    return 0;
}
