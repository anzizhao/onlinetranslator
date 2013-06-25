#ifndef HTTPCLIENTCPP
#define HTTPCLIENTCPP

#include "httpclient.hpp"
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cassert>

#define RECVBUFFERSIZE  65535

const char * c_httpMethod[2] = { "POST", "GET" };

     



string myitoa(int num)
{
     char a[11];
  
     sprintf ( a, "%d", num);
     
     return string(a);
     

}

char mytoupper ( char c )
{
     return toupper(c);
     
}


bool httpclient::sendRequest ()
{
     if ( !sock_.Connect(host_, port_) )
     {
          cerr << "failed to connect" << endl;
          return false;
          
     }
     string packet;
     if ( method_ == POSTMETHOD )
          head_ += "Content-Length:"+myitoa(body_.length())+"\r\n";

     packet = head_  + "\r\n" + body_ ;
     sock_.Send((char *)packet.c_str() ,packet.length() );
     return true;
     
     
} 


//不做任何处理 
bool httpclient::handleResponse ()
{
     char buf[RECVBUFFERSIZE];
   
     int len ;
     
     do
     {
          len = 0;
          len = sock_.Recv(buf, RECVBUFFERSIZE);
          buf[len] = '\0';
          result_ += buf;
          
     }while(len>0);

     return true;
     

}


void httpclient::paserUrl (const string &url)
{
     string::size_type pos;
     pos = url.find('/',string("http://?").length());

     assert(pos != string::npos );

     host_ = url.substr(7,pos-7);
     path_ = url.substr(pos, url.length() );
     port_ = 80;
     pos = host_.find(':');
     if ( pos != string::npos )
     {
          port_ = atoi ( host_.substr(pos+1, host_.length()).c_str() );
          if ( port_ == 0 )
               port_ = 80;
          host_ = host_.substr(0, pos);
          
     }
     
     
     
     
     
}

bool  httpclient::setHead(const string &head )
{
     string::size_type start = 0;
     string::size_type end ;
     if ( head.empty() )
          return false;

     //  path_.clear();
     // host_.clear();
     // 一个head需要有method 和 HOST 行， 否则就是使用默认
     bool hitmethodline = false;
     bool hithostline = false;
     
     head_.clear();
     
     while ( head.find("\r\n", start) != string::npos )
     {
          
          // the first part 
          start  = head.find_first_not_of(" :", start);
          end  = head.find_first_of(" :", start );
          string firstpart;
          firstpart = head.substr(start, end-start);

          // the second part
          string notpattern2(" \r\n");
          
          start = head.find_first_not_of(" :", end );
          end   = head.find_first_of(" \r\n", start);
          string secondpart;
          secondpart = head.substr(start, end-start);

          transform(firstpart.begin(),firstpart.end(), firstpart.begin(), ::toupper) ;
          ///   cout << "firstpart :" << firstpart << endl;
          
          if (  firstpart == "POST" )
          {
               method_ = POSTMETHOD;
               path_ = secondpart;
               hitmethodline = true;
               
               
          }
          else if ( firstpart == "GET" )
          {
               method_ = GETMETHOD;
               path_ = secondpart;
               hitmethodline = true;

          }
          
          else if ( "HOST" == firstpart )
          {
               host_ = secondpart;
               hithostline = true;
               break;
               
          }
          // to the end of this line 
          start = head.find("\r\n", start) + 2;

     }
     
     if ( hitmethodline  &&  hithostline )
     {
          url_ = host_ + path_;
          head_ = head;
     }
     else     // 生成头部核心
     {
          buildHead();
          head_ += head;
     }
     
     
     return true;
     
}


void   httpclient::buildHead ()
{

     head_.clear();
     
     head_ = c_httpMethod[method_] + string(" ") + path_ + " HTTP/1.1\r\n" ;
     head_ += "HOST: " + host_ + "\r\n";
     
   



}

// void  httpclient::addHead ( const string & line )
// {
//      if ( head_.empty() )
//           buildHead ();
//      head_ += line + "\r\n";

     

// }

void  httpclient::list ()
{

     cout << "Port: " << port_ << endl;
     
     cout << "Host: " << host_ << endl;
     cout << "Path: " << path_ << endl;
     cout << "Method_:" << method_ << endl;
     cout << "Body: " << body_ << endl;
     cout << "url: " << url_ << endl;
     cout << "Head: " << head_ << endl;

     

}


#endif
