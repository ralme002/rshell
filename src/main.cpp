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
	int totalcount=0;
	while(1)
	{
		cout << "Running.." << endl;
		
		totalcount++;
	string temp1;
		getline(cin, temp1);
		
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