#ifndef ABSTRACTMANAGEHPP
#define ABSTRACTMANAGEHPP

#include "../http/httpclient.hpp"
#include "../html/pageparser.hpp"


class headinfo
{
protected:
     string query_;
     string scode_;
     string dcode_;
     unsigned from_;
     unsigned to_;

public:
     // common tool  
     void setLanguage(unsigned  src, unsigned  dst )
          {
               from_ = src;
               to_ = dst ;
          }

     int size ()
          {
               return query_.length();
               
          }
     static string byte_to_hex(unsigned char c);
     
     static string common_encode_url ( const string &query );
     
     virtual void setQuery (const string & query )
          {
               query_.clear();
               query_ = query;
          }

     virtual string getBody ()
          {
               return query_;
               
          }
     
    
};

     



class manager
{
protected:
     httpclient downloader_;
     pageparser *parser_;

public:

     virtual void setLanguage ( unsigned src, unsigned dst ) = 0;
     virtual void setQuery (const string &query ) = 0;
     virtual void translate () = 0;
     virtual void translate ( const string &query ) = 0;
     virtual string getResult () = 0;

     
     manager():parser_(NULL)
          {
          }
     
     virtual ~manager ()
          {
              
               delete parser_;
                
          }
     
     
     

};

     




#endif 
