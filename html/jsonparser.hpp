#ifndef JSONPARSERHPP
#define JSONPARSERHPP

#include "json_array_node.hpp"
#include <string>
#include <iostream>
#include <vector>

class jsonparser
{
private:
     basenode *root_;



     string::size_type  _parserJson ( const string &text , jsonnode * jnode );
     string::size_type  _parserArray ( const string &text, arraynode* node  );

     vector<string> _explainKey ( const string & key );
     list<basenode *> tryToMatch ( vector<string>::iterator beg, vector<string>::iterator end , list<basenode *> &nodes );
     
     
public:

     jsonparser():root_(NULL)
          {
          }

     ~jsonparser()
          {
               delete root_;
               
          }
     
     //   vector<string> getValue ( const vector<string> &keys );
     vector<string> getValue ( const string & key);
     
        
     
     void parserJson ( const string &text )
          {
             
               string obj_array("{[");
               string::size_type pos = text.find_first_of(obj_array);
               if ( pos == string::npos )
                    return ;
               
               switch ( text[pos]) {
               case '{':
                    root_ = new jsonnode;
                    
                    _parserJson(text.substr(pos,text.length()), dynamic_cast<jsonnode*>(root_) );
                    break;

               case '[':
                    root_ = new arraynode;
                    
                    _parserArray(text.substr(pos,text.length()), dynamic_cast<arraynode*>(root_)  );
                    break;

               default:
                    return ;
                    
               }
               

               
          }
     
     // test json
     void listJson ()
          {
               cout << root_->showJson(0) << endl;
               
               
          }
     

     

     

};

     



#endif 
