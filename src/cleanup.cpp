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
    if(temp1.at(temp1.length()-1) == ';')
    {
        temp1.at(temp1.length()-1) = '\0';
    }
 
    for(unsigned int i=0; i < temp1.length(); i++)
    {
       if(temp1.at(i) == '#')
       {
           i = temp1.length();
       }
       else
       {
           temp2 += temp1.at(i);
       }
    }
    
    this->cleanup_data = temp2;
}

void cleanup::changebasestring()
{
    base::setinput(this->cleanup_data);
}