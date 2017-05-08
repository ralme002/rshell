#ifndef BUILDER
#define BUILDER

#include "base.h"
#include <vector>
#include <string>
using namespace std;


/*The builder class is a intended to build the command string into a vector of strings. In order
to do this the class has the functionality to take in a cleaned string from the clean up class passed to the execute_builder
function. The pullbuilder and vector_builder */
class builder : public base
{
    public:
    builder(){};
    ~builder(){};
    //functions and shit
    
    vector <base*> execute_builder(string p);
    void vector_builder();
    void container_builder();
    
    protected:
        vector <base*> container;
        vector <string> str;
        string pull_data;
        

};


#endif //BUILDEr