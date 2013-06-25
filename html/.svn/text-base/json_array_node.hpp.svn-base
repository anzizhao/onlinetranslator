#ifndef JSONARRAYNODEHPP
#define JSONARRAYNODEHPP

#include "json_base_node.hpp"
#include <string>
#include <vector>
#include <list>

using namespace std;

class strnode : public basenode
{
private:
     string key_;
     string value_;
     
public:
     // basenode & getvalue ();
     strnode(const string & key, const string &value):key_(key),value_(value)
          {
               setValueType(basenode::VALUESTRING);
               
          }
     strnode(const string &value ):value_(value)
          {
               setValueType(basenode::VALUESTRING);
          }
     
      virtual ~strnode()
          {
          }

     virtual string getKey ()
          {
               return key_;
               
          }
     
     virtual list<basenode *> getValue ( const string &key )
          {
               list<basenode *> result;
               result.push_back (this);
               
               return  result;
               
          }
     
     
     string getStr()
          {
               return value_;
               
          }
     
     string showJson (int spacenum)
          {
               string result;
               if ( ! key_.empty() )
                    result = key_ + ':';

               return result += value_ + '\n';
               
               
          }
     

};

class arraynode : public basenode
{
private:
     list<basenode*> values_;
     string key_;
     string text_;
     
public:

     arraynode(const string &key):key_(key)
          {
               setValueType(basenode::VALUEARRAY);
          }
     arraynode()
          {
               setValueType(basenode::VALUEARRAY);
          }
     virtual ~arraynode ();

     
     virtual string getKey ()
          {
               return key_;
               
          }
     
     //  list<basenode *> getValue ( const vector<string> &key );

     list<basenode *> getValue ( const string &key );

     string getStr ()
          {
               return text_;
               
          }
     
          
   
     
     void add(basenode *node);
     void del(const string& values);

     void setText ( const string &text )
          {
               text_ = text;
               
          }
     
     string showJson (int spacenum);
     
        
     
};




class jsonnode : public basenode
{
private:
     list<basenode*> nodes_;
     string key_;
     string text_;
     
     // just for listJson member function
     // string printspace;
     

     // basenode * _find(vector<string>::const_iterator b, vector<string>::const_iterator e );
     // string _listJson ( jsonnode *node , int spacenum );
     
     
public:
     // void addnode(const basenode& node );
     void add(basenode *node);
     
     void del(const string& key);
     vector<string> listkeys();

     string getKey ()
          {
               return key_;
               
          }
     
     
   
     //  list<basenode *> getValue (const vector<string> &key)
          

     list<basenode *> getValue (const string &key);

     string getStr ()
          {
               return text_;
               
          }
     
     
     
     jsonnode ()
          {
                setValueType(basenode::VALUEJSON);
          }

     jsonnode (const string& key ):key_(key)
          {
                setValueType(basenode::VALUEJSON);
          }
     
     virtual ~jsonnode();
     

     // string listJson(int spacenum )
     //      {
     //           _listJson(this, spacenum);
               
     //      }
     
     void setText ( const string &text )
          {
               text_ = text;
               
          }
     
     string showJson (int spacenum);
     
      
     
     

};

     


#endif 
