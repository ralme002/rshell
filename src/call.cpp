#include "call.h"
void call::execute_call(vector <base*> tmp)
{
    getVector(tmp);
    //setArray();
   greatestAlgorithmInTheWorld();
}

void call::getVector(vector <base*> tmp)
{
   this->holdv = tmp;
}


//syscall execvp to execute commands
int call::execute_cmd(string tmp)    
{
    //int myTemp = 0;
    
    argv = new char[tmp.length() + 1];
    strcpy(argv,tmp.c_str());
   
    char* token_argv=strtok(argv, " ");
    char* array[1000];
    
    int j = 0;

    while(token_argv !=0)
    {
        array[j++]=token_argv;
        token_argv = strtok(NULL, " ");
    }
    array[j]=NULL;
    
    pid_t  pid;
    int status;
    
     pid=fork();
     
     if(pid<0)
     {
         printf("*** ERROR: forking child process failed\n");
     }
     
     if(pid==0)
     {
         
        if(-1 == execvp( array[0], array))
        {
          char errmsg[64];
          snprintf( errmsg, sizeof(errmsg), "exec '%s' failed", array[0] );
          cout << "Error running last command" << endl;
          perror( errmsg );
          this->TestPF = false;
        }
        
        this->TestPF = true;
     }
     else
     {
         waitpid(pid, &status, 0);
     }
     return 0;
    // kill(pid, SIGKILL);
}

//function to check string/array to for exit command        
int call::exit_check(int ex)
{
    return 0;
}

//function to exit the program if exit_check is 1
void call::execute_exit()
{
    cout << "Exit Program..." << endl;
    exit(0);
}

void call::greatestAlgorithmInTheWorld()
{
    int successint = 0;
    bool lastrun = false;
    string current;
    string last_conn;
    string lastlast;
    int counter =0;
    int hardpipe=0;
    
    
    for(unsigned int i=0; i< holdv.size();i++)
    {
        if((counter != 0))
        {
                lastlast = last_conn;
                last_conn = this->holdv.at(i-1)->show_data();
        }
         current = this->holdv.at(i)->show_data();
        
          if(current == "exit")
        {
            execute_exit();
        }
        
        
        if(counter == 0)
        {
            successint = execute_cmd(current);
            if(successint != -1)
            {
                lastrun = true;
            }
            else
            {
                lastrun = false;
            }
            i++; 
            counter++;
        }
        
        if((last_conn == "&&") && (lastrun ==true))
        {
            
            if(hardpipe!=1)
             {
                successint = execute_cmd(current);
                if(successint != -1)
                {
                    lastrun = true;
                }
                else
                {
                    lastrun = false;
                }
             }
             
            i++; 
            counter++;
        }
        if((last_conn == "&&") && (lastrun ==false))
        { //just move to next command since last one failed
            lastrun = false;
            i++;
            counter++;
        }
        
        if((last_conn == "||") && (lastrun == false))
        {
            if(lastlast != "||")
            {
                successint = execute_cmd(current);
                if(successint != -1)
                {
                    lastrun = true;
                }
                else
                {
                    lastrun = false;
                }
            }
            i++; 
            counter++;
        }
        if((last_conn == "||") && (lastrun == true))
        { //just move to next command since last one succeded
    
            hardpipe=1;
            lastrun = true;
            i++; 
            counter++;
        }
        
        if(last_conn == ";")
        {
            hardpipe =0;
            successint = execute_cmd(current);
            if(successint != -1)
            {
                lastrun = true;
            }
            else
            {
                lastrun = false;
            }
            i++;
            counter++;
        }
    }
}