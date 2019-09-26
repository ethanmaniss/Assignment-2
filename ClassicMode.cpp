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
            if((i == 0 && j == 0) || (i == 0 && j == column-1)
             || (i == row-1 && j == 0) || (i == row-1 && j == column-1))
            { // condition if cell is any of the four corners
                if(myGrid[i][j] == '-') // if this corner cell is dead
                {
                    if(myGrid[i][j+1] == 'X' && myGrid[i+1][j+1] == 'X'
                        && myGrid[i+1][j] == 'X') // if all 3 neighbors are alive
                    {
                        myGrid2[i][j] = 'X'; // new cell is born
                    }
                    else // corner cell will stay dead in any other condition
                    {
                        myGrid2[i][j] = '-';
                    }
                }
                if(myGrid[i][j] == 'X') // if this corner cell is alive
                {
                    if(myGrid[i][j+1] == '-' && myGrid[i+1][j+1] == '-'
                        && myGrid[i+1][j] == '-')
                    {
                        myGrid2[i][j] = '-'; // will die of loneliness
                    }

                }
            }
            else if() // condition if cell is part of the side of the grid
            {
                
            }
        }
    }
}
