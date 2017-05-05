#include <string>
#include <vector>
#include <string>
#include <iostream>
#ifndef BASE
#define BASE

using namespace std;
/*
Base class holds a string that will be executed or not depending on algorithm and will call on other classes to get the strings ready
*/
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
	virtual vector <base*> execute_builder(string p){};
	virtual void execute_call(vector <base*> tmp){};
	
protected:
    string inputstring;
	string data;
};

#endif //base