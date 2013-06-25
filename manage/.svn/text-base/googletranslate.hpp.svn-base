#ifndef GOOGLETRANSLATEHPP
#define GOOGLETRANSLATEHPP


#include "abstractmanage.hpp"
#include "../html/googleparser.hpp"
#include <cassert>
namespace googleconf {
     
     

     typedef enum googlelancode {
          Auto = 0,
          Afrikaans,
          Albanian,
          Arabic,
          Belarusian,
          Bulgarian,
          Catalan,
          Chinese,
          Croatian,
          Czech,
          Danish,
          Dutch,
          English,
          Estonian,
          Filipino,
          Finnish,
          French,
          Galician,
          German,
          Greek,
          HaitianCreole,
          Hebrew,
          Hindi,
          Hungarian,
          Icelandic,
          Indonesian,
          Irish,
          Italian,
          Japanese,
          Korean,
          Latvian,
          Lithuanian,
          Macedonian,
          Malay,
          Maltese,
          Norwegian,
          Persian,
          Polish,
          Portuguese,
          Romanian,
          Russian,
          Serbian,
          Slovak,
          Slovenian,
          Spanish,
          Swahili,
          Swedish,
          Thai,
          Turkish,
          Ukrainian,
          Vietnamese,
          Welsh,
          Yiddish,
          
          GOOGLELANGUAGENUM 
     } googlelancode ;

     extern const unsigned getmethod_maxsize;
     
}

//extern const unsigned googleconf::getmethod_maxsize;


using googleconf::googlelancode;


class googleurl : public headinfo 
{
public:
     googleurl()
          {
               from_ = googleconf::Auto;
               to_ = googleconf::Auto;
               scode_ = "UTF-8";
               dcode_ = "UTF-8";
               
          }
     
     string getBody ();
     
     operator string ()
          {
               return getBody();
          }
};

class googlepost : public headinfo
{
public:
     googlepost()
          {
               from_ = googleconf::Auto;
               to_ = googleconf::Auto;
               scode_ = "UTF-8";
               dcode_ = "UTF-8"; 
          }
     string getBody ();
     operator string ()
          {
               return getBody();
          }
     
     
};

     


class googletranslate : public manager
{
public:
     
    
private:
    
     // const static string urlpattern;
     bool postmethod_flag;
     
     googleurl url_;
     googlepost body_;
     
     void init()
          {
               parser_ = new googleparser;
               
               
          }
     unsigned srclanguage_;
     unsigned dstlanguage_;
     
     string buildHead();
   
     
public:
     googletranslate():postmethod_flag(false),srclanguage_(googleconf::Auto), dstlanguage_(googleconf::Chinese)
          {
               init();
               
          }
     
     ~googletranslate()
          {

          }
     
     bool IsPostMethod()
          {
               return postmethod_flag;
               
          }
     
     void setLanguage ( unsigned src, unsigned dst )
          {
               srclanguage_ = src;
               dstlanguage_ = dst;
          }
     
     void setQuery ( const string &query )
          {
               if ( query.length() >= googleconf::getmethod_maxsize){
                    body_.setQuery(query);
                    body_.setLanguage(srclanguage_, dstlanguage_);
                    
                    postmethod_flag = true;
               }
               else
               {
                    url_.setLanguage(srclanguage_, dstlanguage_);
                    url_.setQuery(query);
               }
               
          }
     
     void translate ();
     void translate ( const string &query )
          {
               setQuery(query);
               translate();
          }
     

     string getResult ()
          {
               return parser_->getResult();
               
          }
     
     

};

     



#endif 
