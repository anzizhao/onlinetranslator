#ifndef GOOGLEPARSERHPP
#define GOOGLEPARSERHPP

#include "pageparser.hpp"
#include <libjson.h>

class googleparser : public pageparser
{
private:
   
     

public:
     googleparser() 
          {
          }
     googleparser(const string &page)
          {
               to_parser_page_ = page;
               
          }
   

     void parser ();

    
private:
     void  _parserJson( const JSONNode &  );


};

     


#endif 

