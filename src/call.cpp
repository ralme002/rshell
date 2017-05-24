#include "call.h"
void call::execute_call(vector <base*> tmp)
{
    int currentrun=0;
    hardexit = 0;
    
    getVector(tmp);
    //setArray();
   currentrun = greatestAlgorithmInTheWorld();
   this->CURRENT = currentrun;
   cout << "current Run +" << currentrun << "+" << endl;
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
    int StCheck = 0;
    
     pid=fork();
     
     // int testpid = pid;
    //  cout << endl;
    //  cout << "PID VALUE TEST" << endl;
    //  cout << testpid << endl;
    //  cout << endl;
     
     
     if(pid<0)
     {
         printf("*** ERROR: forking child process failed\n");
         this->TestD = false;
     }
     
     if(pid==0)
     {
        int failure = 1;
        //cout << endl <<"test case1" << endl;
        if(execvp(array[0], array)==-1)
        {
            failure = -1;
            char errmsg[64];
            snprintf( errmsg, sizeof(errmsg), "exec '%s' failed", array[0] );
            perror( errmsg );
            exit(failure);
        }
        else
        {
            exit(failure);
        }
    
       
     }
     else
     {
         //cout << "StCheck before waitpid call " << StCheck << endl;
         //wait(&StCheck);
         waitpid(pid, &StCheck, 0);
         wait(&StCheck);
         
         if(StCheck >= 1 )
         {
             this->TestD = false;
         }
         else
         {
             this->TestD = true;
         }
        
        //cout << "StCheck after wait call " << StCheck << endl;
        this->TestPF = true;

         kill(pid, SIGKILL);
     }
    
    kill(pid, SIGKILL);

}

//function to exit the program if exit_check is 1
void call::execute_exit()
{
    cout << "Exit Program..." << endl;
    exit(0);
}

int call::greatestAlgorithmInTheWorld()
{
    this->NOTSURE=0;
    
    bool lastrun;
    string current;
    string last_conn;
    string lastlast;
    int counter =0;
    int hardpipe=0;
    
    for(unsigned int i=0; i< holdv.size();i+=2)
    {
        if((counter != 0))
        {
                lastlast = last_conn;
                last_conn = this->holdv.at(i-1)->show_data();
        }
        
        current = this->holdv.at(i)->show_data();
        cout << endl << "==current==" << current << " ==last_conn== " << last_conn << " =" << lastrun << endl;
        
        if(counter == 0)
        {
            if(current == "exit")
            {
            execute_exit();
            }
            else if((current.at(0) == 't') && (current.at(1) == 'e') && (current.at(2) == 's') && (current.at(3) == 't'))
            {
                cout << "hit the TEST case" << endl << current << endl;
                call_pass(current);
            }
            else if(current.at(0) == '[')
            {
              call_pass_bracket(current);
            }
            else if(current.at(0) == '(')
            {
                take_parent(current);
            }
            else
            {
            execute_cmd(current);
            }
            if(this->TestD == false)
            {
               lastrun=this->TestD;
               this->TestD=true;
            }
            else
            {
              lastrun = this->TestPF; 
              this->NOTSURE++;
            }
            //lastrun = this->TestPF;
            counter++;
        }
        
        if((last_conn == "&&") && (lastrun ==true))
        {
           if(current == "exit")
            {
            execute_exit();
            }
            else if((current.at(0) == 't') && (current.at(1) == 'e') && (current.at(2) == 's') && (current.at(3) == 't'))
            {
             call_pass(current);
            }
            else if(current.at(0) == '[')
            {
              call_pass_bracket(current);
            }
             else if(current.at(0) == '(')
            {
                take_parent(current);
            }
            else
            {
            execute_cmd(current);
            }
            
            if(this->TestD == false)
            {
               lastrun=this->TestD;
               this->TestD=true;
            }
            else
            {
             lastrun = this->TestPF; 
             this->NOTSURE++;
            }
            //lastrun = this->TestPF;
            counter++;
        }
        if((last_conn == "&&") && (lastrun == false))
        { //just move to next command since last one failed
            lastrun = false;
           // hardpipe =1;
            counter++;
        }
        
        if((last_conn == "||") && (lastrun == false))
        {
            if(hardpipe != 1)
            {
                //if(lastlast != "||")
                //{
                    if(current == "exit")
                    {
                    execute_exit();
                    }
                    else if((current.at(0) == 't') && (current.at(1) == 'e') && (current.at(2) == 's') && (current.at(3) == 't'))
                    {
                        call_pass(current);
                    }
                    else if(current.at(0) == '[')
                    {
                        call_pass_bracket(current);
                    }
                     else if(current.at(0) == '(')
                    {
                    take_parent(current);
                    }
                    else
                    {
                     execute_cmd(current);
                    }
                  
                if(this->TestD == false)
                {
                   lastrun=this->TestD;
                   this->TestD=true;
                }
                else
                {
                 lastrun = this->TestPF; 
                 this->NOTSURE++;
                }
                //lastrun = this->TestPF;
                }
            //}
            counter++;
        }
        if((last_conn == "||") && (lastrun == true))
        { //just move to next command since last one succeded
    
            hardpipe=1;
            lastrun = true;
            counter++;
        }
        
        if(last_conn == ";")
        {
            hardpipe =0;
            
            if(current == "exit")
            {
            execute_exit();
            }
            else if((current.at(0) == 't') && (current.at(1) == 'e') && (current.at(2) == 's') && (current.at(3) == 't'))
            {
                 call_pass(current);
            }
            else if(current.at(0) == '[')
            {
                call_pass_bracket(current);
            }
             else if(current.at(0) == '(')
            {
                take_parent(current);
            }
            else
            {
             execute_cmd(current);
            }
            
            if(this->TestD == false)
            {
               lastrun=this->TestD;
               this->TestD=true;
            }
            else
            {
               lastrun = this->TestPF; 
               this->NOTSURE++;
            }
            
           //cout << "BRO+" << lastrun << "+BRO" << endl;
            counter++;
        }
    }
    
    return this->NOTSURE;
}

void call::execute_test(string tmp)
{
   
    struct stat sb;
    char* arg = new char[tmp.length()+1];
    strcpy(arg, tmp.c_str());
    
    char* tokenized_arg = strtok(arg, " ");
    char* array[100];
    
    int i = 0;
    
    while (tokenized_arg != 0)
    {
    	array[i++] = tokenized_arg;
    	tokenized_arg = std::strtok(NULL, " ");
    }
    array[i] = NULL;
    
    
     int teststat = stat(array[1] , &sb);
     /*
     cout << "teststat" << endl;
     cout << teststat << endl;
     cout << endl;
     cout << "S_ISREG Test case" << endl;
     cout << S_ISREG(sb.st_mode) << endl;
     cout << "S_IDIR Test case" << endl;
     cout << S_ISDIR(sb.st_mode) << endl;
     */


    if(teststat != -1)
    {
    
        if(array[0][0] == '-' && array[0][1] == 'e')
        {
           
          if((S_ISDIR(sb.st_mode)!=0) || (S_ISREG(sb.st_mode)!=0))
          {
              cout << "(TRUE)" << endl;
              this->TestPF = true;
              this->TestD = true;
          }
          else 
          {
              cout << "(FALSE)" << endl;
              
             this->TestD = false;
          }
        }
        //-d checks if the file/directory exists and is a directory
        else if(array[0][0] == '-' && array[0][1] == 'd')
        {
          if(S_ISDIR(sb.st_mode)!=0)
          {
              cout << "(TRUE)" << endl;
    
              this->TestPF  = true;
              this->TestD = true;
          }
          else 
          {
              cout << "(FALSE)" << endl;
    
              this->TestD = false;
          }
         
        }
        
        //-f checks if the file/directory exists and is a regular file
        else if(array[0][0] == '-' && array[0][1] == 'f')
        {
          if(S_ISREG(sb.st_mode)!=0)
          {
              cout << "(TRUE)" << endl;
              this->TestPF  = true;
              this->TestD = true;
          }
          else 
          {
              cout << "(FALSE)" << endl;
              this->TestD = false;
          }
        }
        
        else
        {
          cout << "Unknown flag" <<endl;
          this->TestD = false;
          
         
        }
    }
    else
    {
        cout << "Invalid file path, please enter file path in correct format" << endl;
        cout << "(FALSE)" << endl;
        this->TestD = false;
        
    }
    //cout << "Error with test" << endl; 
    //this->TestPF = false;

}

void call::call_pass(string current)
{
            string testtemp;
            for(unsigned int k=5; k< current.length(); k++)
            {
                testtemp += current.at(k);
            }
            //testtemp += '\0';
            
            string defualt_test = "-e ";
            if(testtemp[0]!='-')
            {
                testtemp=defualt_test.append(testtemp);
            }
            //cout << "+" << testtemp << "+" << endl;
            // << endl << "middle func +" << testtemp << "+" << endl;
            execute_test(testtemp);
}

void call::call_pass_bracket(string current)
{
   string temp8;
   string insert = "-e ";
     
   for(unsigned int j=1; j < current.length()-1; j++)
      {
        if((current.at(1) != '-') && (j == 1))
        {
            temp8 = insert;
        }
       temp8 += current.at(j);
      }
        
    temp8 += '\0';
    //cout << "+++" << temp8 << "+++" << endl;
    execute_test(temp8);
    temp8.clear();
}

void call::take_parent(string current)
{
    string temp11;
    int retint=0;
    //clean process
    for(unsigned int i=1;i < current.length()-2; i++)
    {
        temp11 += current.at(i);
    }
    temp11 += '\0';
    cout << temp11 << endl;
    
    string TEST1 = temp11;
	base *second = new builder;
	vector <base*> TEST2 = second->execute_builder(TEST1);
	base *third = new call;
	third->execute_call(TEST2);
    retint = third->TestCur();
    if(retint != 0) //SUCCEEDED
    {
        cout << "one passed" << endl;
       // this->TestPF = true;
        this->TestD = true;
    }
    else //FAILED
    {
        cout << "one DIDNOT pass" << endl;
        this->TestPF = false;
        this->TestD = false;
    }
    
    //end clean
}