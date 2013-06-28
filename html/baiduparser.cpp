#ifndef BAIDUPARSERCPP
#define BAIDUPARSERCPP

#include "baiduparser.hpp"

// pre deal with the json file
void delete_slash(string & jsonfile )
{
     string::size_type  pos;
      
     pos =  jsonfile.find("{");
     jsonfile.erase ( 0, pos );
     pos = jsonfile.rfind ("\r\n0\r\n\r\n");
     jsonfile.erase( pos );
      
     pos = jsonfile.find("\\");
     while ( pos != string::npos )
     {
          jsonfile.erase( pos, 1 );
          pos = jsonfile.find("\\");
     }
     // libjson doesn't support string json node?
     // delete the double quotation marks of result value .
     // make it became json node , not string. 
     pos = jsonfile.find( "result\"");
     if ( pos != string::npos )
     {
          
          pos = jsonfile.find("\"", pos +  string("result\"").size() );
          jsonfile.erase(pos, 1);
          pos = jsonfile.rfind( "\"" );
          jsonfile.erase(pos, 1);
     }
     
}

void  baiduparser::parser ()
{
     if ( to_parser_page_.empty() )
          return ;
     delete_slash ( to_parser_page_ );
      
     JSONNode node_tree = libjson::parse ( to_parser_page_ );
     _parserJson( node_tree  );
      
}

void  baiduparser:: _parserJson ( const JSONNode & node_tree )
{
     JSONNode::const_iterator node_iter = node_tree.begin(); 
     while ( node_iter != node_tree.end() )
     {
         
          string  node_name = node_iter->name ();
           
          if  ( node_iter->name () == "result" )
          {
               result_.clear();
          }
         
          else if ( node_name == "pre")
          {
               result_ += node_iter->as_string() + "\n";
                
          }
          else if ( node_name == "cont" )
          {
               JSONNode::const_iterator result_iter = node_iter->begin();
               while ( result_iter != node_iter->end() )
               {
                    result_ += result_iter->name() + " |";
                    result_iter ++;
                     
               }
               result_ += "\n";
                
               node_iter ++  ;
               continue;
                
          }


          if ( node_iter->type() == JSON_ARRAY || node_iter->type() == JSON_NODE )
          {
               _parserJson( *node_iter );
               
          }
          
          node_iter ++;
           
     }

}



// void  baiduparser::parser ()
// {
//      if ( to_parser_page_.empty() )
//           return;
//      // remove the uncorrleated part
//      string::size_type startpos;
//      string::size_type endpos;
     
//      startpos = to_parser_page_.find("{");
//      to_parser_page_.erase(0, startpos);
//      endpos = to_parser_page_.find("\"relation\":");
//      if ( endpos != string::npos ) {
          
//           endpos = to_parser_page_.rfind(",", endpos );
//           to_parser_page_.replace(endpos, to_parser_page_.length(), "}]}");
//      }
     
//      // for debug 
//      // cout << to_parser_page_ << endl;
     
     
//      vector<string>  vec_result;
     

//      jparser_.parserJson(to_parser_page_);
// #     vec_result = jparser_.getValue(string("\"data\"{\"dst\""));
//      vec_result = jparser_.getValue(string("\"result\"{\\\"content\\\""));

//      //判断是否嵌入html
//      if ( vec_result.empty()  )
//      {

          
//           vec_result = jparser_.getValue(string("\"result\""));
//           result_ = vec_result.front();
//           delete_slash(result_);
          
//           hparser_.parse(result_);

//           result_.clear();
//           result_ = hparser_.getResult();
          
//      }
//      else
//           result_ = vec_result.front();
     
     


// }



#endif
