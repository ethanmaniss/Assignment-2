#include "Assignment2.h"
#include <iostream>

using namespace std;

ClassicMode::Rules()
{
    myGrid = new char*[row];
    for(int i = 0; i < row; i++)
    {
        myGrid[i] = new char*[column];
        for(int j = 0; j < column; j++)
        {
            if(i == 0 && j == 0) // starts in upper left hand corner
            {
                if(myGrid[i][j] == '-')
                {
                    if(myGrid[i][j+1] == '-' && myGrid[i+1][j+1] == '-'
                        && myGrid[i+1][j] == '-')
                    {
                        myGrid2[i][j] = '-'; // will stay dead
                    }
                    if(myGrid[i][j+1] == '-' && myGrid[i+1][j+1] == '-'
                        && myGrid[i+1][j] == '-')
                    {
                        myGrid2[i][j] = '-'; // will stay dead
                    }
                    
                }
                if(myGrid[i][j] == 'X')
                {
                    if(myGrid[i][j+1] == '-' && myGrid[i+1][j+1] == '-'
                        && myGrid[i+1][j] == '-')
                    {
                        myGrid2[i][j] = '-'; // will die of loneliness
                    }

                }
            }
            if(i == 0 && j == column-1) // next goes to upper right hand corner
            {

            }
        }
    }
}
