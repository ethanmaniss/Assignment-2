#include "Assignment2.h"
#include <iostream>

using namespace std;

void ClassicMode::Rules()
{
    myGrid = new char*[row];
    for(int i = 0; i < row; i++)
    {
        myGrid[i] = new char[column];
        for(int j = 0; j < column; j++)
        {
            if((i == 0 && j == 0) || (i == 0 && j == column-1)
             || (i == row-1 && j == 0) || (i == row-1 && j == column-1))
            { // condition if cell is any of the four corners
                if(i == 0 && j == 0) // if cell is upper left corner
                {
                    if(myGrid[i][j] == '-') // if this upper left corner cell is dead
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
                    else if(myGrid[i][j] == 'X') // if this upper left corner cell is alive
                    {
                        if(myGrid[i][j+1] == 'X' && myGrid[i+1][j+1] == 'X' ||
                            myGrid[i+1][j+1] == 'X' && myGrid[i+1][j] == 'X' ||
                            myGrid[i][j+1] == 'X' && myGrid[i+1][j] == 'X')
                        {
                            myGrid2[i][j] = 'X'; // remains stable with 2 or 3 neighbors
                        }
                    }
                }
                else if(i == 0 && j == column-1) // if cell is upper right corner
                {
                    if(myGrid[i][j] == '-') // if this upper right corner cell is dead
                    {
                        if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X'
                            && myGrid[i+1][j] == 'X') // if all 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else // corner cell will stay dead in any other condition
                        {
                            myGrid2[i][j] = '-';
                        }
                    else if(myGrid[i][j] == 'X') // if this upper right corner cell is alive
                    {
                        if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' ||
                            myGrid[i+1][j-1] == 'X' && myGrid[i+1][j] == 'X' ||
                            myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X')
                        {
                            myGrid2[i][j] = 'X'; // remains stable with 2 or 3 neighbors
                        }
                    }
                }
                else if(i == row-1 && j == 0) // if cell is lower left corner
                {
                    if(myGrid[i][j] == '-') // if this lower left corner cell is dead
                    {
                        if(myGrid[i-1][j] == 'X' && myGrid[i-1][j+1] == 'X'
                            && myGrid[i][j+1] == 'X') // if all 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else // corner cell will stay dead in any other condition
                        {
                            myGrid2[i][j] = '-';
                        }
                    else if(myGrid[i][j] == 'X') // if this lower left corner cell is alive
                    {
                        if(myGrid[i-1][j] == 'X' && myGrid[i-1][j+1] == 'X' ||
                            myGrid[i-1][j+1] == 'X' && myGrid[i][j+1] == 'X' ||
                            myGrid[i][j+1] == 'X' && myGrid[i-1][j] == 'X')
                        {
                            myGrid2[i][j] = 'X'; // remains stable with 2 or 3 neighbors
                        }
                    }
                }
                else if(i == row-1 && j == column-1) // if cell is lower right corner
                {
                    if(myGrid[i][j] == '-') // if this lower right corner cell is dead
                    {
                        if(myGrid[i][j-1] == 'X' && myGrid[i-1][j-1] == 'X' &&
                            myGrid[i-1][j] == 'X') // if all 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else // corner cell will stay dead in any other condition
                        {
                            myGrid2[i][j] = '-';
                        }
                    else if(myGrid[i][j] == 'X') // if this lower right corner cell is alive
                    {
                        if(myGrid[i][j-1] == 'X' && myGrid[i-1][j-1] == 'X' ||
                            myGrid[i-1][j-1] == 'X' && myGrid[i-1][j] == 'X' ||
                            myGrid[i-1][j] == 'X' && myGrid[i][j-1] == 'X')
                        {
                            myGrid2[i][j] = 'X'; // remains stable with 2 or 3 neighbors
                        }
                    }
                }
            }
            else if((i == 0) || (j == 0) || (j == column-1) || (i == row-1))
            // condition if cell is part of the side of the grid with 5 neighbors
            {
                if(i == 0) // if cell is part of the top side
                {
                    if(myGrid[i][j] == '-') // if top cell is dead
                    {
                        if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                            myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X')
                        // if top cell has 4 alive neighbors
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i+1][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X') || (myGrid[i][j-1] == 'X' &&
                                myGrid[i+1][j-1] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i][j-1] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i+1][j-1] == 'X' && myGrid[i+1][j+1] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else
                        {
                            myGrid2[i][j] = '-'; // cell will die under any other condition
                        }
                    }
                    else if(myGrid[i][j] == 'X') // if the top cell is alive
                    {
                        if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                            myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X')
                        // if top cell has 4 alive neighbors
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i+1][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X') ||
                                (myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j+1] == 'X') ||
                                (myGrid[i][j-1] == 'X' && myGrid[i][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i+1][j-1] == 'X' && myGrid[i+1][j] == 'X') ||
                                (myGrid[i+1][j-1] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i+1][j-1] == 'X' && myGrid[i][j+1] == 'X') ||
                                (myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X') ||
                                (myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else
                        {
                            myGrid2[i][j] = '-'; // cell will die in any other condition
                        }
                    }
                }
                else if(j == 0) // if cell is part of the left side
                {
                    if(myGrid[i][j] == '-') // if left cell is dead
                    {
                        if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                            myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X')
                        // if left cell has 4 alive neighbors
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i+1][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X') || (myGrid[i][j-1] == 'X' &&
                                myGrid[i+1][j-1] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i][j-1] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i+1][j-1] == 'X' && myGrid[i+1][j+1] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else
                        {
                            myGrid2[i][j] = '-'; // cell will die under any other condition
                        }
                    }
                    else if(myGrid[i][j] == 'X') // if the left cell is alive
                    {
                        if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                            myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X')
                        // if left cell has 4 alive neighbors
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i+1][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X') ||
                                (myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j+1] == 'X') ||
                                (myGrid[i][j-1] == 'X' && myGrid[i][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i+1][j-1] == 'X' && myGrid[i+1][j] == 'X') ||
                                (myGrid[i+1][j-1] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i+1][j-1] == 'X' && myGrid[i][j+1] == 'X') ||
                                (myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X') ||
                                (myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else
                        {
                            myGrid2[i][j] = '-'; // cell will die in any other condition
                        }
                    }
                }
                else if(j == column-1) // if cell is part of the right side
                {
                    if(myGrid[i][j] == '-') // if right cell is dead
                    {
                        if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                            myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X')
                        // if right cell has 4 alive neighbors
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i+1][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X') || (myGrid[i][j-1] == 'X' &&
                                myGrid[i+1][j-1] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i][j-1] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i+1][j-1] == 'X' && myGrid[i+1][j+1] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else
                        {
                            myGrid2[i][j] = '-'; // cell will die under any other condition
                        }
                    }
                    else if(myGrid[i][j] == 'X') // if the right cell is alive
                    {
                        if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                            myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X')
                        // if right cell has 4 alive neighbors
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i+1][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X') ||
                                (myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j+1] == 'X') ||
                                (myGrid[i][j-1] == 'X' && myGrid[i][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i+1][j-1] == 'X' && myGrid[i+1][j] == 'X') ||
                                (myGrid[i+1][j-1] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i+1][j-1] == 'X' && myGrid[i][j+1] == 'X') ||
                                (myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X') ||
                                (myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else
                        {
                            myGrid2[i][j] = '-'; // cell will die in any other condition
                        }
                    }
                }
                else if(i == row-1) // if cell is part of the bottom side
                {
                    if(myGrid[i][j] == '-') // if bottom cell is dead
                    {
                        if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                            myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X')
                        // if bottom cell has 4 alive neighbors
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i+1][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell stays dead (overcrowding)
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X') || (myGrid[i][j-1] == 'X' &&
                                myGrid[i+1][j-1] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i][j-1] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else if((myGrid[i+1][j-1] == 'X' && myGrid[i+1][j+1] == 'X' &&
                                myGrid[i][j+1] == 'X') || (myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // only 3 neighbors are alive
                        {
                            myGrid2[i][j] = 'X'; // new cell is born
                        }
                        else
                        {
                            myGrid2[i][j] = '-'; // cell will die under any other condition
                        }
                    }
                    else if(myGrid[i][j] == 'X') // if the bottom cell is alive
                    {
                        if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                            myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X')
                        // if bottom cell has 4 alive neighbors
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i+1][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if(myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X' &&
                                myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X')
                        // 4 or more neighbors are alive
                        {
                            myGrid2[i][j] = '-'; // cell dies due to overcrowding
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j-1] == 'X') ||
                                (myGrid[i][j-1] == 'X' && myGrid[i+1][j] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i][j-1] == 'X' && myGrid[i+1][j+1] == 'X') ||
                                (myGrid[i][j-1] == 'X' && myGrid[i][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i+1][j-1] == 'X' && myGrid[i+1][j] == 'X') ||
                                (myGrid[i+1][j-1] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i+1][j-1] == 'X' && myGrid[i][j+1] == 'X') ||
                                (myGrid[i+1][j] == 'X' && myGrid[i+1][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else if((myGrid[i+1][j] == 'X' && myGrid[i][j+1] == 'X') ||
                                (myGrid[i+1][j+1] == 'X' && myGrid[i][j+1] == 'X'))
                        // cell has 2 or 3 neighbors
                        {
                            myGrid2[i][j] = 'X'; // cell is either born or stabilizes
                        }
                        else
                        {
                            myGrid2[i][j] = '-'; // cell will die in any other condition
                        }
                    }
                }
            }
            else // cell is determined to be a middle cell with 8 neighbors
            {

            }
        }
    }
}
