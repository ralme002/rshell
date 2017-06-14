#include "base.h"
#include <string>
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////
//Function: setinput
//Parameters: string tmp1
//Description: sets the protected value of inputstring to passed string value tmp1
/////////////////////////////////////////////////////////////////////////////////////////////////
void base::setinput(string temp1)  //for testing purposes the string is hardcoded but will be switched out for user input
{
	this->inputstring = temp1;
}
////////////////////////////////////////////////////////////////////////////////////////////////
//Function: retinputstring
//Parameters: none
//Description: returns the value of the protected value inputstring
/////////////////////////////////////////////////////////////////////////////////////////////////
string base::retinputstring()
{
	return this->inputstring;
}
////////////////////////////////////////////////////////////////////////////////////////////////
//Function: setprivate
//Parameters: none
//Description: sets the protected string value data to the passed value of x
/////////////////////////////////////////////////////////////////////////////////////////////////
void base::setprivate(string x)
{
	this->data = x;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//Function: show_data
//Parameters: none
//Description:  returns the value of the protected value data
/////////////////////////////////////////////////////////////////////////////////////////////////
string base::show_data()
{
	
	return this->data;
	
}