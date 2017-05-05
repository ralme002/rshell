#ifndef CLEANUP
#define CLEANUP

#include "base.h"
/*
cleans up the string passed in by user and will also tokenize string into a vector of strings
*/
class cleanup : public base
{
public:
	cleanup() {}; // default constructor
	~cleanup() {}; // default destructor

	virtual void execute_cleanup();
	
	void pullstring();
	void printcleanupstring();
	void clean();
	void changebasestring();

protected:
    string cleanup_data;
};



#endif //CLEANUP