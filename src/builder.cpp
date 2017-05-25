#include "builder.h"
#include "vector"

/* execute builder takes in will take in a string that has been cleaned passed from cleanup
this will then be set to the protected builder pull_data for later "building" for our call class functionality
execute_builder will call on the functionality of pullbuilder and vector_builder*/
vector <base*> builder::execute_builder(string p)
{
    this->pull_data = p;
    vector_builder();
    container_builder();
    
    return this->container;
}

/*vector builder is going to separte the pull_data into a vector of strings, this 
change allows us to have more flexability for our call class. The vector builder is going to check the string for
commmand delineators, upon encountering a delineator, the function is going to pull the parsed string and push it back onto a vector of strings
The functionality of the function will check the parsing string for the three main delineators ; && ||*/
void builder::vector_builder() //complete! assumptions are that there is a space in the beggining and a space in between the connectors (; && |)
{
    string temp1 = this->pull_data;
    string temp2;
    int spacecount = 0;
    spacecount++;
    
    int leftpar = 0;
    int rightpar = 0;


    for(unsigned int i=0; i< temp1.length(); i++)
    {
        if((temp1.at(i)== ' ')&&(spacecount ==0))
        {
            i++;
            spacecount++;
        }
        
        if(temp1.at(i) ==' ')
        {
            spacecount++;
            
            if(i+1 < temp1.length())
            {
                if((temp1.at(i+1) == '&')|| (temp1.at(i+1) == '|'))
                {
                    i++;
                }
            }
            
        }

        if(temp1.at(i)== ';')
        {
            if(temp2.length() > 1)
            {
                this->str.push_back(temp2); //cout << "1["<< this->str.size()<<"] +" << temp2 <<"+"<< endl;
            }
            temp2.clear();
            temp2 += ';';
            this->str.push_back(temp2); //cout << "2["<< this->str.size()<<"] +" << temp2 <<"+"<< endl;
            temp2.clear();
            i+=2;
        }
        
        if(temp1.at(i) =='&')
        {
            if(i+1 < temp1.length())
            {
                if(temp1.at(i+1) == '&');
                if(temp2.length() > 1)
                {
                this->str.push_back(temp2); //cout << "3["<< this->str.size()<<"] +" << temp2 <<"+"<< endl;
                }
                temp2.clear();
                temp2+= temp1.at(i+1);
                temp2+= temp1.at(i+1);
                this->str.push_back(temp2); //cout << "4["<< this->str.size()<<"] +" << temp2 <<"+"<< endl;
                temp2.clear();
                i+=3;
            }
        }
        
        if(temp1.at(i) =='|')
        {
            if(i+1 < temp1.length())
            {
                if((temp1.at(i+1) == '|') && (temp2.length() > 1))
                {
                    this->str.push_back(temp2); //cout << "5["<< this->str.size()<<"] +" << temp2 <<"+"<< endl;
                }
                
                temp2.clear();
                temp2+= temp1.at(i+1);
                temp2+= temp1.at(i+1);
                this->str.push_back(temp2); //cout << "6["<< this->str.size()<<"] +" << temp2 <<"+"<< endl;
                temp2.clear();
                i+=3;
            }
        }
        
        if(temp1.at(i) == '(')
        {
            leftpar++;
            i++;
          if(temp2.length() > 1)
            {
                this->str.push_back(temp2);// cout << "7["<< this->str.size()<<"] +" << temp2 <<"+"<< endl;
            }
            
          temp2.clear();
          temp2 += '(';
          while(leftpar != rightpar)
          {
              if(temp1.at(i) == '(')
              {
                  leftpar++;
              }
               if(temp1.at(i) == ')')
              {
                  rightpar++;
              }
              temp2 += temp1.at(i);
              i++;
          }
          //temp2 += ')';  //i dont think i need this anymore ....maybe
          temp2 += '\0';
          this->str.push_back(temp2); //cout << "8["<< this->str.size()<<"] +" << temp2 <<"+"<< endl;
          temp2.clear();
          //i++;  //i dont think i need this anymore ....maybe
        }
        else
        {
        temp2 += temp1.at(i);
        }
    }
        this->str.push_back(temp2); //cout << "9[L] +" << temp2 <<"+"<< endl;
        temp2.clear();
}

void builder::container_builder()
{
    base* p = new base;
    
    for(unsigned int i=0; i < this->str.size(); i++)
    {
        p->setprivate(str.at(i));
        this->container.push_back(p);
        //this should check to see if the next item is the size of the container, an if it is not
        //it will create a new instance of base for the next iteration of the loop
        if((i+1)==this->str.size())
        {
            
        }
        else
        {
           p=new base; 
        }
    }
}