#include "base.h"
#include <string>
#include <iostream>

using namespace std;

void base::setinput(string temp1)  //for testing purposes the string is hardcoded but will be switched out for user input
{
	this->inputstring = temp1;
}

string base::retinputstring()
{
	return this->inputstring;
}

void base::setprivate(string x)
{
	this->data = x;
}


string base::show_data()
{
	
	return this->data;
	
}