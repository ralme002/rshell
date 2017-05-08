#include "call.h"
void call::execute_call(vector <base*> tmp)
{
    getVector(tmp);
    //setArray();
   greatestAlgorithmInTheWorld();
}

void call::setArray()
{
    string tmp;
    unsigned int j = this->holdv.size();
    cout << j << endl;
    
    unsigned int i = 0; 
    while(i != this->holdv.size())
    {
        tmp = this->holdv.at(i)->show_data();
        
        if( i < this->holdv.size())
        {
            i++;
            execute_cmd(tmp);
        }
        else
        {
            break;
        }
    }
}

void call::getVector(vector <base*> tmp)
{
   this->holdv = tmp;
}


//syscall execvp to execute commands
void call::execute_cmd(string tmp)    
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
          perror( errmsg );
          this->TestPF = false;
        }
        
        this->TestPF = true;
     }
     else
     {
         waitpid(pid, &status, 0);
     }
     //kill(pid, SIGKILL);
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
    
    bool lastrun = false;
    string current;
    string last_conn;
    int counter =0;
    
    cout << holdv.size();
    
    for(unsigned int i=0; i< holdv.size();i++)
    {
        current = this->holdv.at(i)->show_data();
        
        if((counter != 0))
        {
            last_conn = this->holdv.at(i-1)->show_data();
        }
        
        cout << endl << "==current==" << current << "==last_conn==" << last_conn << "==" << lastrun << endl;

        if(current == "exit")
        {
           execute_exit();
        }
        
        if(counter == 0)
        {
            
                execute_cmd(current);
                if(this->TestPF != false)
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
            
                execute_cmd(current);
                if(this->TestPF != false)
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
        if((last_conn == "&&") && (lastrun ==false))
        { //just move to next command since last one failed
            lastrun = false;
            i++;
            counter++;
        }
        
        if((last_conn == "||") && (lastrun == false))
        {
            
                execute_cmd(current);
                if(this->TestPF != false)
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
        if((last_conn == "||") && (lastrun == true))
        { //just move to next command since last one failed
            lastrun = false;
            i++; 
            counter++;
        }
        
        if(last_conn == ";")
        {
            
                execute_cmd(current);
                if(this->TestPF != false)
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