#ifndef ABSTRACTMANAGECPP
#define ABSTRACTMANAGECPP

#include "abstractmanage.hpp"
#include <string>
#include <cstdio>
#include <cassert>


string headinfo::byte_to_hex(unsigned char c)
{
     char buf[4];
     sprintf(buf,"%%%x%x", c / 0x10, c % 0x10 );
     return string(buf);


}


string headinfo::common_encode_url( const string &text )
{
     int size = text.length();
     string result;
     // result.resize(text.length()+100);
     result.reserve(text.length()+100);
     
     string no_need_change_char("-_.!~*'()");
     
     for( int i=0; i<size; i++ )
     {
          if ( isalnum(text[i]) || no_need_change_char.find_first_of(text[i]) != string::npos )
          {
               result.append(1,text[i]);
               
          }
          else if ( text[i] == ' ' )
          {
               result.append("%20");
               
          }
          else if ( (unsigned char)text[i] <= 127 )   //一般acsii 特殊字符
          {
               result += byte_to_hex(text[i]);
               

          }
          else
          {
               int bytes = 0;
               
               if(((unsigned char)text[i] >= 192) && ((unsigned char)text[i] <= 223))
                    bytes = 2;
               else if(((unsigned char)text[i] > 223) && ((unsigned char)text[i] <= 239))
                    bytes = 3;
               else if(((unsigned char)text[i] > 239) && ((unsigned char)text[i] <= 247))
                    bytes = 4;
               else if(((unsigned char)text[i] > 247) && ((unsigned char)text[i] <= 251))
                    bytes = 5;
               else if(((unsigned char)text[i] > 247) && ((unsigned char)text[i] <= 251))
                    bytes = 6;

               if ( bytes == 0 || ((bytes-1)+i) > size )
                    assert(false);
               int j ;
               
               for ( j=0; j < bytes; j++ )
               {
                    result += byte_to_hex(text[i+j]);
                    
               }
               i += j -1 ;
               
          }
          

     }
     return result;

}




#endif 
