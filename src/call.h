#ifndef CALL
#define CALL

#include "base.h"
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
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <cstdlib>
#include "builder.h"


using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////
//Class: call
//Derives from: public base
//Description: 
/*
    Class Call holds all the functions for sorting and deciding what commands need to be executed. 
*/
/////////////////////////////////////////////////////////////////////////////////////////////////
class call : public base
{
    public:
        call(){this->TestD = true;}; //default constructor
        ~call(){}; //default deconstructor
        
        
        int greatestAlgorithmInTheWorld();
        void execute_call(vector <base*> tmp);
        
        void setArray();
        void getVector(vector <base*> tmp);
        void execute_cmd(string tmp); //syscall execvp to execute commands  >>   virtual void execute_cmd(base* current);     
        void execute_exit(); //function to exit the program if exit_check is 1
        void execute_test(string tmp); // new function does something
        void call_pass(string current);
        void call_pass_bracket(string current);
        void take_parent(string current);
        
    protected:
    int ex;
    vector <base*> holdv;
    char* argv;
    bool TestPF;
    bool TestD;
    int hardexit;
    int NOTSURE;
    
};
#endif