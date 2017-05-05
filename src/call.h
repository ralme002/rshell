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


using namespace std;

/*
    Class Call is holds the functionality to call execvp to call commands that are passed. Also
    has functionality for the exit command using an int value

*/
class call : public base
{
    public:
        call(){}; //default constructor
        ~call(){}; //default deconstructor
        
        
        void greatestAlgorithmInTheWorld();
        void execute_call(vector <base*> tmp);
        
        void setArray();
        void getVector(vector <base*> tmp);
        int execute_cmd(string tmp); //syscall execvp to execute commands  >>   virtual void execute_cmd(base* current);     
        int exit_check(int ex); //function to check string/array to for exit command
        void execute_exit(); //function to exit the program if exit_check is 1
        
    
    
    protected:
    int ex;
    vector <base*> holdv;
    char* argv;
   
    
    
};
#endif