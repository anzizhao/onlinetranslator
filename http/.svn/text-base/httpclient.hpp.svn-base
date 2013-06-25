#ifndef HTTPCLIENTHPP
#define HTTPCLIENTHPP

#include "sock.h"
#include <string>
using namespace std;


class httpclient
{
protected:
     void paserUrl(const string &url);
     void  buildHead();
public:
     enum httpMethod { POSTMETHOD, GETMETHOD };

     httpclient():method_(GETMETHOD), port_(80), path_("/") {}
     httpclient(const string &url)
          {
               url_ = url;
               paserUrl(url_);
          }
     virtual ~httpclient (){};
     
     void setMethod ( httpMethod method )
          {
               method_ = method;
          }
     void setBody ( const string &body)
          {
               body_ = body;
          }
     void setUrl  (const string &url )
          {
               url_ = url;
               paserUrl(url_);
          }

     bool setHead ( const string &head );
     
        

     void addHead ( const string &line )
          {
               if ( head_.empty() )
                    buildHead ();
               head_ += line + "\r\n";

          }
     
     
     
     string getResult ()
          {
               return result_;
          }

     void list () ;
     
          
     
     
     virtual bool sendRequest ();
     virtual bool handleResponse ();
     
protected:
     Sock sock_;
     string url_;
     httpMethod method_;
     string body_;
     string host_;
     string path_;
     string head_;
     
     unsigned short port_;

     string result_;

   
};

     




#endif 
