#include <string>
#include <vector>
#include <string>
#include <iostream>
#ifndef BASE
#define BASE

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////
//Class: base
//Derives from: none
//Description: 
/*
Base class holds a string that will be executed or not depending on algorithm and will call on other classes to get the strings ready
*/
/////////////////////////////////////////////////////////////////////////////////////////////////
class base
{
public:
	base() {}; // default constructor
	~base() {}; // default destructor

	void setinput(string temp1); //accessor to change the inputstring in private data
	string retinputstring();  //accessor to return the inputstring in private data
	string show_data();
	void setprivate(string x);
	virtual void execute_cleanup(){};
	virtual vector <base*> execute_builder(string p){vector<base*> v; return v;};
	virtual void execute_call(vector <base*> tmp){};
	virtual int TestPar(){return this->ParPass;};
	virtual int TestCur(){return this->CURRENT;}
	
protected:
    string inputstring;
	string data;
	int ParPass;
	int CURRENT;
};

#endif //base