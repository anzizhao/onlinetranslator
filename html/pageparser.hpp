#ifndef PAGEPARSERHPP
#define PAGEPARSERHPP


#include <string>
#include <cassert>
using namespace std;
 

class pageparser
{
protected:
     string result_;
     string to_parser_page_;
 



     
public:

     virtual ~pageparser()
          {
          }
     
     virtual string getResult ()
          {
               std::string::size_type pos;
               
               pos = result_.find("\\");
               while ( pos != string::npos )
               {
         
                    result_.erase(pos,1);
                    pos = result_.find("\\");

               }
     
               return result_;
               
          }
     
     
      
     string setPage (const string &page )
          {
                to_parser_page_ = page;
          }


     virtual void parser () = 0;
     
     void parser ( const string &page )
          {
               to_parser_page_ = page;
               parser ();
               
          }
     

};

     



#endif 
