#ifndef BAIDUPARSERCPP
#define BAIDUPARSERCPP

#include "baiduparser.hpp"




void delete_slash(string &html)
{
     string::size_type  pos = html.find("\\");
     while ( pos != string::npos )
     {
          html[pos] = '/';
          pos = html.find("\\", pos+1);
     }

}

// string baiduparser::getResult()
// {
//      string::size_type pos;

//      pos = result_.find("\\");
//      while ( pos != string::npos )
//      {
         
//           result_.erase(pos,1);
//           pos = result_.find("\\");

//      }
     

// }



void  baiduparser::parser ()
{
     if ( to_parser_page_.empty() )
          return;
     // remove the uncorrleated part
     string::size_type startpos;
     string::size_type endpos;
     
     startpos = to_parser_page_.find("{");
     to_parser_page_.erase(0, startpos);
     endpos = to_parser_page_.find("\"relation\":");
     if ( endpos != string::npos ) {
          
          endpos = to_parser_page_.rfind(",", endpos );
          to_parser_page_.replace(endpos, to_parser_page_.length(), "}]}");
     }
     
     // for debug 
     // cout << to_parser_page_ << endl;
     
     
     vector<string>  vec_result;
     

     jparser_.parserJson(to_parser_page_);
     vec_result = jparser_.getValue(string("\"data\"{\"dst\""));

     //判断是否嵌入html
     if ( vec_result.empty()  )
     {

          
          vec_result = jparser_.getValue(string("\"result\""));
          result_ = vec_result.front();
          delete_slash(result_);
          
          hparser_.parse(result_);

          result_.clear();
          result_ = hparser_.getResult();
          
     }
     else
          result_ = vec_result.front();
     
     


}



#endif
