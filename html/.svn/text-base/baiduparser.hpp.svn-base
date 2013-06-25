#ifndef BAIDUPARSERHPP
#define BAIDUPARSERHPP

//#include "jsonparser.hpp"
#include "baiduEngine.hpp"
#include "pageparser.hpp"
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

     
 
     //string getResult ();
     
     //      {
     //           return result_;
     //      }
     // void setPage ( const string &page )
     //      {
     //           to_parser_page_ = page;
     //      }

     void   parser ();
     
     // void  parser ( const string &page )
     //      {
     //           to_parser_page_ = page;
     //           parser();
     //      }

     
};

     




#endif 
