#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include "base.h"
#include "cleanup.h"
#include "builder.h"
#include "call.h"
using namespace std;

int main()
{
	while(1)
	{
	string temp1;
		getline(cin, temp1);
		
	cout << endl <<"/////////////////SEPERATE INPUT ////////////////////////////" << endl;
	cout  << "INPUT:" << temp1 << endl;
	
	base *first = new cleanup;
		first->setinput(temp1); //calls user input and stores in private string
		first->execute_cleanup();
		string temp2= first->retinputstring();
	
	base *second = new builder;
		vector <base*> temp3 = second->execute_builder(temp2);
	
	base *third = new call;
		third->execute_call(temp3);
	}
	
	return 0;
}