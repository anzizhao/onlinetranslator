#ifndef GOOGLEPARSERCPP
#define GOOGLEPARSERCPP

#include "googleparser.hpp"





void googleparser::parser ()
{
     if ( to_parser_page_.empty() )
          return ;
     
     string::size_type pos;
     
     pos = to_parser_page_.find("[");
     if ( pos == string::npos )
     {
          to_parser_page_.clear();
          return ;
          
     }
     else 
          to_parser_page_.erase(0, pos);
     pos = to_parser_page_.rfind("ISGETMETHOD");
     to_parser_page_.erase(pos);

     
     JSONNode node_tree = libjson::parse ( to_parser_page_ );
     _parserJson( node_tree );
}

void googleparser::_parserJson ( const JSONNode & node_tree )
{
     // in the google json, the useful information is in the first element
     // in the array .   [[[]], "zh-CN/en" ... 
     JSONNode::const_iterator first_elem_iter = node_tree.begin();
     JSONNode::const_iterator second_iter = first_elem_iter->begin();
     JSONNode::const_iterator info_iter = second_iter->begin();
     
     result_.clear();
      
     while ( info_iter  != second_iter->end() )
     {
          result_ += info_iter->as_string() + " | ";
          ++ info_iter ;
     }
     result_ += '\n';
      
}



#endif 
