#ifndef BAIDUPARSERCPP
#define BAIDUPARSERCPP

#include "baiduparser.hpp"

// pre deal with the json file
void baiduparser::delete_slash(string & jsonfile )
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
     

     // there are two type of the  json file . so use the name "data" to identify
     // them.
     if ( jsonfile.find( "\"data\"") == string::npos )
     {
          // libjson doesn't support string json node ?
          // delete the double quotation marks of result value .
          // make it became json node , not string.
          jtype_ = WORD;
          pos = jsonfile.find( "result\"");
          if ( pos != string::npos )
          {
          
               pos = jsonfile.find("\"", pos +  string("result\"").size() );
               jsonfile.erase(pos, 1);
               pos = jsonfile.rfind( "\"" );
               jsonfile.erase(pos, 1);
          }
     }
     else
          jtype_ = SENTENCE;
      
}

void  baiduparser::parser ()
{
     if ( to_parser_page_.empty() )
          return ;
     delete_slash ( to_parser_page_ );
      
     JSONNode node_tree = libjson::parse ( to_parser_page_ );
     if ( jtype_ == WORD )
          _parserJsonW( node_tree  );
     else 
          _parserJsonS( node_tree );
      
}

void  baiduparser:: _parserJsonW ( const JSONNode & node_tree )
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
               _parserJsonW( *node_iter );
               
          }
          
          node_iter ++;
           
     }

}


void  baiduparser:: _parserJsonS ( const JSONNode & node_tree )
{
     JSONNode::const_iterator node_iter = node_tree.begin(); 
     while ( node_iter != node_tree.end() )
     {
         
          string  node_name = node_iter->name ();
          if ( node_name == "data" )
          {
               JSONNode::const_iterator arr_first_elem = node_iter->begin();
               JSONNode::const_iterator node_first_elem = arr_first_elem->begin();
               while ( node_first_elem != arr_first_elem->end() )
               {
                    
                    if ( node_first_elem->name() == "dst" )
                    {
                         result_ = node_first_elem->as_string();
                         break;
                    }
                    ++ node_first_elem ;
                     
               }
               break;
                
                              
          }
          
          node_iter ++;
           
     }

}





#endif
