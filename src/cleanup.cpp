#include "cleanup.h"
#include "base.h"
#include <string>
#include <iostream>

using namespace std;
void cleanup::execute_cleanup()
{
    pullstring();
    clean();
    changebasestring();
}

void cleanup::pullstring()
{
    this->cleanup_data = base::retinputstring();
}

void cleanup::printcleanupstring()
{
    cout << this->cleanup_data << endl;
}




void cleanup::clean()
{
    string temp2;
    string temp1 = this->cleanup_data;
    int LPar = 0;
    int RPar = 0;
    
    if(temp1.at(temp1.length()-1) == ';')
    {
        temp1.at(temp1.length()-1) = '\0';
    }
 
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
    if(LPar != RPar)
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

void cleanup::changebasestring()
{
    base::setinput(this->cleanup_data);
}