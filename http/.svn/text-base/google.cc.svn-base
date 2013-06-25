#include "httpclient.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
#include <cassert>
using namespace std;

string byte_to_hex(unsigned char c)
{
     char buf[4];
     sprintf(buf,"%%%x%x", c / 0x10, c % 0x10 );
     return string(buf);
}



string common_encode_url ( const string &text )
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



int main ( int argc, char *argv[] )
{

     string url = "http://translate.google.com.hk/?hl=zh-CN#en/zh-CN/happy";

     // string url_base = "http://translate.google.com.hk/translate_a/t?client=t&text";
     // string body = "=happy";
     // string urlcode = "&hl=zh_CN&sl=en&tl=zh_CN&ie=UTF-8&oe=UTF-8&multires=1&otf=1&";
     // string url2 = "http://translate.google.com.hk/translate_a/t?client=t&text=happy%20birthday%20you%20are&hl=zh-CN&sl=en&tl=zh-CN&ie=UTF-8&oe=UTF-8&multires=1&otf=1&ssel=0&tsel=0&sc=1";

     // string url2 = "http://translate.google.cn/translate_a/t?client=t&text=I%20hope%20someday%20%2C%20i%20will%20be%20rich%20.%0Atomrrow%20i%20will%20have%20a%20Engilsh%20test%2C%20good%20luck.&hl=zh-CN&sl=auto&tl=zh-CN&ie=UTF-8&oe=UTF-8&multires=1&prev=enter&ssel=0&tsel=4&&sc=1";
     string query("I am curiosity why you still here.!!!!!!!!! 开心吧");
     string q;
     q = common_encode_url(query);
     
     string url2;
     url2 = "http://translate.google.cn/translate_a/t?client=t&text=" ;
     url2 += q + "%20&sl=auto&tl=zh-CN&ie=UTF-8&oe=UTF-8";
     
        // url2 = "http://translate.google.cn/translate_a/t?client=t&text=I%20am%20curiosity%20&sl=en&tl=zh-CN&ie=UTF-8&oe=UTF-8";
     
     
     
     string head;
     // head = "GET /translate_a/t?client=t&text=happy&hl=zh-CN&sl=en&tl=zh-CN&ie=UTF-8&oe=UTF-8&multires=1&otf=1&ssel=0&tsel=0&sc=1 HTTP/1.1\r\n";
     head = "GET " + url2 + " HTTP/1.1\r\n";
     
     
     head += "Host: translate.google.com.hk\r\n";
     head += "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
     head += "Accept-Language: zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3\r\n";
     head +="Connection: close\r\n";
     head +="Content-Type: text/javascript; charset=UTF-8\r\n";

     string real_head  = "GET " + url + " \r\n" + head ;
     
     // httpclient client;
     // client.setUrl(url);
     // client.setHead(real_head);
     
     // if ( client.sendRequest() )
     //      client.handleResponse();
     // cout <<"URL :" << url << "\n" <<  client.getResult() << endl;
     // client.list();
     

     // real_head.clear();
     // real_head  = "GET " + url2 + " HTTP/1.1\r\n" + head ;
     // httpclient client2;
     // client2.setUrl(url2);
     // client2.setHead(real_head);
     // if ( client2.sendRequest() )
     //      client2.handleResponse();
     
     // cout <<"URL :" << url2 << "\n" <<  client2.getResult() << endl;
     // client2.list();

     // httpclient client3;
     // client3.setUrl (url2);
     // client3.setMethod (httpclient::GETMETHOD);
     // client3.addHead("Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
     // client3.addHead("Accept-Language: zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3");
     // client3.addHead("Connection: close");
     // client3.addHead("Content-Type: text/javascript; charset=UTF-8");
     
     // if ( client3.sendRequest() )
     //      client3.handleResponse();
     
     // cout <<"URL :" << url2 << "\n" <<  client3.getResult() << endl;
     // client3.list();
     


      httpclient client4;
      if  ( ! client4.setHead(head) )
           cout << "not right to set head" << endl;

      if ( client4.sendRequest() )
           client4.handleResponse();
     
     cout <<"URL :" << url2 << "\n" <<  client4.getResult() << endl;
     client4.list();
     
      

     

     
     return 0;
     
      


}
