#ifndef JSONPARSERCPP
#define JSONPARSERCPP

#include "jsonparser.hpp"
#include "json_array_node.hpp"

#include <fstream>
#include <cassert>

#ifdef _debug

#include <time.h>
namespace debug
{


     const string  DEBUGFILE = "debug.log";
     
     void recordUnknownSituation (const string & text , string::size_type pos )
     {
          ofstream outfile;
          time_t now;
          string::size_type size = text.length();
          
          time(&now);
          
          outfile.open( DEBUGFILE.c_str(), ofstream::out | ofstream::app );
          outfile <<  ctime(&now) << endl;
          
          outfile << "pos : " << pos << " around the character: " << text.substr(pos, ( (size-pos) > 10) ? 10: (size-pos)) << endl;
     
          outfile << text << endl;
          outfile.close();         
     }


}

#endif 




vector<string> jsonparser::_explainKey (const string &key )
{
     string nostr("[{");
     vector<string> result;
     
     if ( key.empty() )
          return result;
     

     string::size_type pos = 0;
     string::size_type end ;
     
     unsigned int size = key.size();
     
     while ( pos < size )
     {
          switch (key[pos]) {
          case '[':
          case '{':
               result.push_back( string(1, key[pos]) );
               ++ pos;
               break;

          default:
               end = key.find_first_of(nostr, pos);
               if ( end == string::npos )
                    end = size;
               result.push_back(key.substr(pos, end-pos) );
               pos = end;
          }
          

     }
     
     return result;
     

}

list<basenode *> jsonparser::tryToMatch ( vector<string>::iterator beg, vector<string>::iterator end , list<basenode*> &nodes )
{
     list<basenode *> nodelist;
     list<basenode *> result;
     
     list<basenode *>::iterator nit = nodes.begin();
     list<basenode *>::iterator nend = nodes.end();
     
     while ( nit != nend  )
     {
          nodelist.clear();
          nodelist = (*nit)->getValue(*beg);
          if ( nodelist.empty() )
          {
               ++ nit;
               continue;
          }
          
          if ( (beg + 1)  == end  )     //最后匹配
               result.splice(result.end(),nodelist);
          
          else
          {
               list<basenode *> part_result = tryToMatch(beg+1, end, nodelist) ;  
               result.splice(result.end(),part_result );
               
          }
          nit ++;
          
     }
     return result ;
}

vector<string>  jsonparser::getValue ( const string &key)
{
     vector<string> result;
     result = _explainKey(key);

     
     vector<string>::iterator it = result.begin();
     vector<string>::iterator end = result.end();

     //   basenode * node = root_;
     list<basenode *> nodes;
     nodes.push_back(root_);
     
     // list<basenode *> startlist;
     
     nodes = tryToMatch(it, end, nodes);

     result.clear();
     if ( ! nodes.empty()  )
     {
     
          
          list<basenode*>::iterator lit = nodes.begin();
          list<basenode*>::iterator lend = nodes.end();

          while ( lit !=  lend )
          {
               result.push_back((*lit)->getStr() );
               lit ++;
          }
     }
     
     return result;
     
}


string::size_type  jsonparser::_parserJson ( const string &text ,jsonnode * jnode )
{
     string::size_type pos = 0;
     string::size_type end ;
    
     
     pos = text.find('{');
     if ( pos == string::npos )
          return 0;
     string::size_type size = text.length();
     while ( pos != string::npos && pos < size &&  text[pos] != '}' )
     {
          // deal with key 
          string key;
         
          
          pos = text.find('\"', pos);
          end = text.find('\"', pos+1);
          ++end;
          key = text.substr(pos,end-pos);

          // deal with value 
          string excludechar(": ");
          pos = text.find_first_not_of(excludechar, ++end );
          basenode *node;
          if ( text[pos] == '\"' )
          {
               string value ;
               int tmp = 1;
               do {
                    end = text.find('\"', pos+tmp);
                    tmp = end - pos + 1;
               }while ( text[end-1] == '\\');
               



               ++end;
               value = text.substr(pos, end-pos);
               node = new strnode(key,value);
               jnode->add(node);
               pos = end;
          }
          else if ( isalnum(text[pos]) )
          {
               string value ;
               int tmp = 0;
               do{
                    end = text.find_first_of(",}", pos+tmp);
                    tmp = end - pos + 1;
                    
               }while ( text[end-1] == '\\' );
               
               value = text.substr(pos, end-pos);
               node = new strnode(key,value);
               jnode->add(node);
               if ( text[end] == '}' )
                    pos = end;
               else 
                    pos = end + 1;
          }
          else if ( text[pos] == '[' )
          {
               arraynode *arr;
               string::size_type add;
               arr = new arraynode(key);
               add = _parserArray(text.substr(pos, text.length()),  arr );
               arr->setText( text.substr(pos+1, add-2));

               pos += add;
               
               jnode->add(arr);
          }
          else if ( text[pos] == '{' )
          {
               jsonnode *j;
               string::size_type add;
               j = new jsonnode(key);
               add = _parserJson(text.substr(pos, text.length()), j);
               j->setText(text.substr(pos+1, add-2));
               pos += add;
               
               jnode->add (j);
          }
          else
          {
#ifdef _debug
               debug::recordUnknownSituation(text, pos);
               
#endif
               ++ pos;
               
          }
     }
     
     return ++pos;

}


string::size_type jsonparser::_parserArray ( const string &text , arraynode  *anode )
 {
      string::size_type pos = text.find('[');
      string::size_type end;
      //   vector<string> arr;
      
      basenode *node;
      string::size_type size = text.length();
      while ( pos != string::npos && pos < size && text[pos] != ']' )
      {
           string excludechar(", ");
           pos = text.find_first_not_of(excludechar,++pos);
           //   cout <<size << " " <<  pos << endl;
           if ( text[pos] == '\"'  )
           {
                string value;
                int tmp = 1;
                do {
                     
                     end = text.find('\"', pos+tmp);
                     tmp = end - pos + 1;
                }while ( text[end-1] == '\\' );
                
                ++end; 
                value = text.substr(pos, end-pos);
                node = new strnode(value);
                anode->add(node);
                pos = end;
           }
           else if (  isalnum(text[pos]) )
           {
                string value;
                int tmp = 1;
                //如果以数字结尾 没哟，
                do {
                     end = text.find_first_of(",]", pos+tmp);
                     tmp = end - pos + 1;
                }while ( text[end-1] == '\\' );

               
               
                value = text.substr(pos, end-pos);
                node = new strnode(value);
                anode->add(node);
                if ( text[end] == ']' )
                     pos = end;
                else 
                     pos = end + 1;
           }
           else if ( text[pos] == '[' )
           {
                arraynode * arr;
                string::size_type add;
                
                arr = new arraynode;
                add = _parserArray(text.substr(pos, text.length()), arr );
                arr->setText(text.substr(pos+1, add-2));
                pos += add;
                
                anode->add(arr);
           }
           else if ( text[pos] == '{' )
           {
                jsonnode *j;
                string::size_type add;
                
                j  = new jsonnode;
                add =  _parserJson( text.substr(pos, text.length()) , j);
                j->setText(text.substr(pos+1, add-2));
                pos += add;
                
                anode->add(j);
                     
           }
           else if ( text[pos] == ']' )
           {
                //[]空数组
           }
           
           else
           {
#ifdef _debug
                debug::recordUnknownSituation(text, pos);
               
#endif
                ++ pos;
                
           }
           
      }

      if ( pos == string::npos || pos >= size  )
           return size;
      return ++pos;

 }






#endif
