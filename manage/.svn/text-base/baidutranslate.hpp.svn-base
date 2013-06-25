#ifndef BAIDUTRANSLATEHPP
#define BAIDUTRANSLATEHPP




#include "abstractmanage.hpp"
#include "../html/baiduparser.hpp"

#include <string>
#include <fstream>

using namespace std;



namespace baiduconf {
     typedef enum baidulancode {
          Auto,
          English,
          Chinese,
          Japanese,
          BAIDULANGUAGENUM
     } baidulancode;
     

};



class postbody : public headinfo 
{

private:
     const static char *language[baiduconf::BAIDULANGUAGENUM];
     const static string pattern_;
     
public:
     postbody()
          {
               scode_ = "utf-8";
               
          }
   
     friend istream & operator >> ( istream &in, postbody &body );
          
     string  getBody( );

     
     operator string ();
  
     
};

     


class baidutranslate : public manager 
{
public:
  
     
private:
     // baiduurl url_;
     // const static  string url_;
   
   

     postbody to_translate_;
     
     void init();
     string  buildHead();
   
     
public:
     baidutranslate()
          {
               init();
          }
     ~baidutranslate()
          {

          }
     
     
     
     void setLanguage(unsigned  src, unsigned dst)
          {
               
               to_translate_.setLanguage(src, dst);
          }
     
   
     
     void setQuery (const string & query )
          {
               to_translate_.setQuery( query );
               
          }
     
     void translate ();
     void translate ( const string &query);
     
     string getResult ();
     
private:
     
     

};

     





#endif 
