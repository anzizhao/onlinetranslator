#ifndef BAIDUPARSERHPP
#define BAIDUPARSERHPP

//#include "jsonparser.hpp"
#include "baiduEngine.hpp"
#include "pageparser.hpp"
#include <libjson.h>

void delete_slash(string &html);


class baiduparser : public pageparser
{

protected:
     baiduengine  hparser_;
     
public:
     baiduparser() { }
     baiduparser(const string &page )
          {
               to_parser_page_ = page;
               
          }
     void   parser ();
     void parser ( const string &page )
          {
               to_parser_page_ = page;
               parser ();
               
          }
     
private:
     void _parserJson ( const JSONNode & );
      

     
};

     




#endif 
