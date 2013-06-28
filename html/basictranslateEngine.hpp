#ifndef BASIC_TRANSLATEENGINE
#define BASIC_TRANSLATEENGINE

#include <ParserSax.h>
#include <Node.h>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;
using namespace htmlcxx::HTML ;


class basictranslateEngine : public ParserSax
{
     
private:
   
     

public :
     string getResult()
          {
               return str_result.empty()?string("Sorry,no translation result"):str_result;
             
          }
   
     virtual ~basictranslateEngine()
          {
          }

     
     
     
protected:
     string str_result;
     basictranslateEngine()
          {
          }
     
     bool affect_text_tag( Node node , bool isEnd )
          {
               string &result = str_result;
               const string &tagname = node.tagName();
            
               
               if ( tagname == "p" )  
               {
                    result += "\n  ";
                 
                    
               }
               else if ( tagname == "br")
               {
                    result += "\n";
                    
                 
               }
               else if ( tagname == "strong")
               {
                    result += " ";
                 
               }
               else if ( tagname[0] == 'h' )
               {
                    if ( isEnd )
                         result += "\n";
                    else
                    {
                         int spacenum = atoi(&tagname[1]);
                         while (--spacenum )
                              result += ' ';
                    }
                 
                    
               }
               
               else {
                    return false;
               }
               return true;
               
          }
     
     
};







#endif
