#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "base.h"
#include "cleanup.h"
#include "builder.h"
#include "call.h"
using namespace std;

/*Josh's notes 
---------------

*/


/*Robert's notes 
-------------------
"the setarray function was bad and you should feel bad" -zoidberg
*/

int main()
{
	string temp1;
		//cout << "Input String" << endl;
		//getline(cin, temp1);
	temp1 = "ls -a; echo hello && pwd; echo #world# && mkdir nope && CANT || mkdir dont";

	base *first = new cleanup;
		first->setinput(temp1); //calls user input and stores in private string
		first->execute_cleanup();
		string temp2= first->retinputstring();
	
	base *second = new builder;
		vector <base*> temp3 = second->execute_builder(temp2);
	
	base *third = new call;
		third->execute_call(temp3);
	
	return 0;
}