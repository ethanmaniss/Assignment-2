#include "Assignment2.h"
#include <iostream>

using namespace std;

int main()
{
    int userChoice;

    while(true)
    {
        cout << "Select 1) for random configuration" << endl;
        cout << "Or select 2) to choose configuration" << endl;
        try
        {
            cin >> userChoice;
        }
        catch(int userChoice)
        {
            cout << "Integer exception." << endl;
            cout << "Please select either 1) or 2)." << endl;
        }
        if(userChoice == 1 || userChoice == 2)
        {
            break;
        }
        else
        {
            cout << "Please select either 1) or 2)." << endl;
        }
    }



    return 0;
}
