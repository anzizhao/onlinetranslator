#ifndef GOOGLEPARSERCPP
#define GOOGLEPARSERCPP

#include "googleparser.hpp"


void googleparser::_doparser (bool gmflag)
{
     vector<string> resultlist;
     
    
     // remove the incorrelated part
     string::size_type startpos;
     
     startpos = to_parser_page_.find("[");
     if ( startpos == string::npos )
     {
          to_parser_page_.clear();
          return ;
          
     }
     else 
          to_parser_page_.erase(0, startpos);



     
     jparser_.parserJson(to_parser_page_);
     resultlist = jparser_.getValue(string("[["));
     if ( resultlist.empty() )
          assert(false && "parser the result page error");
     
     if ( gmflag )
     {
          result_ = resultlist.front();
          return;
          
     }
     
     
     vector<string>::iterator vsit = resultlist.begin();
     vector<string>::iterator vsend = resultlist.end();
     while ( vsit != vsend )
     {
          result_ += (*vsit).substr(1, (*vsit).find("\",\"")-1);
               
          vsit++;
     }
          
   
     
}

void googleparser::parser ()
{
     if ( to_parser_page_.empty() )
          return ;
     
     string::size_type rpos;
     rpos = to_parser_page_.rfind("ISGETMETHOD");
     if ( rpos != string::npos )
          _doparser(true);
     else
          _doparser(false);
     
     


     


}


// string googleparser::getResult()
// {
//      string::size_type pos;

//      pos = result_.find("\\");
//      while ( pos != string::npos )
//      {
         
//           result_.erase(pos,1);
//           pos = result_.find("\\");

//      }
     

// }


#endif 
