#ifndef JSONBASENODEHPP
#define JSONBASENODEHPP

#include <string>
#include <vector>
#include <list>
using namespace std;


class basenode
{

private:
    
   
public:
     enum value_type { VALUESTRING,VALUEARRAY, VALUEJSON };
     //   enum search_type { SEARCHVALUE,SEARCHARRAY, SEARCHJSON };
   
          
protected:
     value_type valuetype_;


public:
     basenode ()
          {
           
          }
     virtual ~basenode()
          {
          }
     
   
     value_type valueType()
          {
               return valuetype_;
          }
     static  value_type valueType (const string &str)
          {
               if ( str == string(1,'{') )
                    return VALUEJSON;
               else if ( str == string(1,'['))
                    return VALUEARRAY;
               else
                    return VALUESTRING;
               
          }
     
     void setValueType(value_type t )
          {
               valuetype_ = t;
          }
    
     virtual string getKey ()
          {
               return string();
               
          }
     
     // virtual list<basenode *> getValue ( const vector<string> & key )
     //      {
     //           return list<basenode *>();
               
               
     //      }
     virtual string getStr ()
          {
               return string();
               
          }
     
     
     virtual list<basenode *> getValue ( const string &key )
          {
               return list<basenode*>();
               
          }
     
     
     //jsonnode and arraynode  operation
     virtual void add (basenode *node)
          {
               return ;
               
          }
     
     virtual void del (const vector<string> &keys)
          {
               return ;
               
          }
     
     virtual string showJson (int spacenum)
          {
               return string();
               
          }
     
     
};

     


#endif 
