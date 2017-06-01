#include "cleanup.h"
#include "base.h"
#include <string>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////
//Function: execute_cleanup()
//Parameters: none
//Description: executes all the functions needed within cleanup
/////////////////////////////////////////////////////////////////////////////////////////////////
void cleanup::execute_cleanup()
{
    pullstring();
    clean();
    changebasestring();
}

////////////////////////////////////////////////////////////////////////////////////////////////
//Function: pullstring
//Parameters: none
//Description: takes the string in the base class and stores it in the private data of this class
/////////////////////////////////////////////////////////////////////////////////////////////////
void cleanup::pullstring()
{
    this->cleanup_data = base::retinputstring();
}

////////////////////////////////////////////////////////////////////////////////////////////////
//Function: printcleanupstring
//Parameters: none
//Description: prints the current string in the cleanup class private data
/////////////////////////////////////////////////////////////////////////////////////////////////
void cleanup::printcleanupstring()
{
    cout << this->cleanup_data << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//Function: clean
//Parameters: none
/*Description: executes the main cleaning portion of the string which accounts for a semicolon at the end,
		       also counts the left and right parentheses to make sure they are even. */
/////////////////////////////////////////////////////////////////////////////////////////////////
void cleanup::clean()
{
    string temp2;
    string temp1 = this->cleanup_data;
    int LPar = 0;
    int RPar = 0;
    
    //test the last element in the string against a semicolon
    if(temp1.at(temp1.length()-1) == ';') //if it, its replaced by the null character
    {
        temp1.at(temp1.length()-1) = '\0';
    }
    
    //goes character by character, counts left and right parentheses, looks for the comment operator
    for(unsigned int i=0; i < temp1.length(); i++)
    {
         if(temp1.at(i)=='(')
        {
            LPar++;
        }
        else if(temp1.at(i)==')')
        {
            RPar++;
        }
        
       if(temp1.at(i) == '#')
       {
           i = temp1.length();
       }
       else
       {
           temp2 += temp1.at(i);
       }
    }
    if(LPar != RPar) //if parentheses are not even then it couts the error and forces the program to leave
    {
        cout << "Invalid Parentheses entry: not even" << endl;
        this->ParPass = -1;
    }
    else
    {
        this->ParPass = 0;
    }

    //cout << "AFTER CLEANUP:" << temp2 << endl;
    
    this->cleanup_data = temp2;
}


////////////////////////////////////////////////////////////////////////////////////////////////
//Function: changebasestring
//Parameters: none
//Description: moves the string from the cleanup class to base class
/////////////////////////////////////////////////////////////////////////////////////////////////
void cleanup::changebasestring()
{
    base::setinput(this->cleanup_data);
}