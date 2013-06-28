#ifndef BAIDUPARSERHPP
#define BAIDUPARSERHPP

//#include "jsonparser.hpp"
#include "baiduEngine.hpp"
#include "pageparser.hpp"
#include <libjson.h>




class baiduparser : public pageparser
{

protected:
     baiduengine  hparser_;
     enum jsonFileType {
          WORD=1, SENTENCE=2 
     };
     jsonFileType  jtype_;
      
     
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
     // deal with the word json file. 
     void _parserJsonW ( const JSONNode & );
     // deal with sentence json file .
     void _parserJsonS ( const JSONNode & );
      
     void delete_slash(string &html);
     
};

     




#endif 
