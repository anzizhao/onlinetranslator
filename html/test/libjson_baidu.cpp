#include <libjson.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


 
void parserJson ( const JSONNode & );
 

int main ()
{
     ifstream ifile("baidu.json");
     string word, content ;
     while ( ifile >> word  )
          content += word + ' ';

     cout << "the content is :" << content << endl ;
      
     JSONNode n = libjson::parse( content );
     parserJson ( n  );
     return 0;
      
}

void parserJson ( const JSONNode & n )
{
     JSONNode::const_iterator i = n.begin();
     while (i != n.end()){
          // recursively call ourselves to dig deeper into the tree
          if (i -> type() == JSON_ARRAY || i -> type() == JSON_NODE){
               parserJson(*i);
          }
 
          // get the node name and value as a string
          cout << " " <<  i -> name()   ;
 
         
          //increment the iterator
          ++i;
     }

     cout << endl ;
     
}

