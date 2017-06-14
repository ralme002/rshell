#ifndef CLEANUP
#define CLEANUP

#include "base.h"

////////////////////////////////////////////////////////////////////////////////////////////////
//Class: cleanup
//Derives from: public base
//Description: pulls a string from the base class and removes a semicolon at the end, checks for comments an
//				stops at the command operator, also counts to ensure even parentheses.
/////////////////////////////////////////////////////////////////////////////////////////////////
class cleanup : public base
{
public:
	cleanup() {}; // default constructor
	~cleanup() {}; // default destructor

	virtual void execute_cleanup();
	void pullstring(); //takes the string in the base class and stores it in the private data of this class
	void printcleanupstring(); //prints the current string in the cleanup class private data
	void clean(); /*executes the main cleaning portion of the string which accounts for a semicolon at the end,
					also counts the left and right parentheses to make sure they are even.
					*/
	void changebasestring(); //changes the base string to the new cleaned string.

protected:
    string cleanup_data; //holds the string that is going to be cleaned up
};



#endif //CLEANUP