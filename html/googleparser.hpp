#ifndef GOOGLEPARSERHPP
#define GOOGLEPARSERHPP

#include "pageparser.hpp"

class googleparser : public pageparser
{
private:
     void _doparser(bool gmflag=true);
     

public:
     googleparser() 
          {
          }
     googleparser(const string &page)
          {
               to_parser_page_ = page;
               
          }
     //  string getResult ();
     
     //      {
     //           return result_;
     //      }

     // void setPage ( const string &page)
     //      {
     //           to_parser_page_ = page;
     //      }

     void parser ();

     // void parser ( const string &page )
     //      {
     //           to_parser_page_ = page;
     //           parser ();
               
     //      }
     


};

     




#endif 
