#ifndef GOOGLEPARSERCPP
#define GOOGLEPARSERCPP

#include "googletranslate.hpp"
#include <cassert>

using namespace std;

namespace googleconf {
     
     const char* google_lan[] = {
          "auto",                     //Auto
          "af",                      //("Afrikaans"), "af"},       
          "sq",                      //("Albanian"), "sq"},        
          "ar",                      //("Arabic"), "ar"},          
          "be",                      //("Belarusian"), "be"},      
          "bg",                      //("Bulgarian"), "bg"},       
          "ca",                      //("Catalan"), "ca"},         
          "zh-CN",                   //("Chinese"), "zh-CN"},      
          "hr",                      //("Croatian"), "hr"},        
          "cs",                      //("Czech"), "cs"},           
          "da",                      //("Danish"), "da"},          
          "nl",                      //("Dutch"), "nl"},           
          "en",                      //("English"), "en"},         
          "et",                      //("Estonian"), "et"},        
          "tl",                      //("Filipino"), "tl"},        
          "fi",                      //("Finnish"), "fi"},         
          "fr",                      //("French"), "fr"},          
          "gl",                      //("Galician"), "gl"},        
          "de",                      //("German"), "de"},          
          "el",                      //("Greek"), "el"},           
          "ht",                      //("Haitian Creole"), "ht"},  
          "iw",                      //("Hebrew"), "iw"},          
          "hi",                      //("Hindi"), "hi"},           
          "hu",                      //("Hungarian"), "hu"},       
          "is",                      //("Icelandic"), "is"},       
          "id",                      //("Indonesian"), "id"},      
          "ga",                      //("Irish"), "ga"},           
          "it",                      //("Italian"), "it"},         
          "ja",                      //("Japanese"), "ja"},        
          "ko",                      //("Korean"), "ko"},          
          "lv",                      //("Latvian"), "lv"},         
          "lt",                      //("Lithuanian"), "lt"},      
          "mk",                      //("Macedonian"), "mk"},      
          "ms",                      //("Malay"), "ms"},           
          "mt",                      //("Maltese"), "mt"},         
          "no",                      //("Norwegian"), "no"},       
          "fa",                      //("Persian"), "fa"},         
          "pl",                      //("Polish"), "pl"},          
          "pt",                      //("Portuguese"), "pt"},      
          "ro",                      //("Romanian"), "ro"},        
          "ru",                      //("Russian"), "ru"},         
          "sr",                      //("Serbian"), "sr"},         
          "sk",                      //("Slovak"), "sk"},          
          "sl",                      //("Slovenian"), "sl"},       
          "es",                      //("Spanish"), "es"},         
          "sw",                      //("Swahili"), "sw"},         
          "sv",                      //("Swedish"), "sv"},         
          "th",                      //("Thai"), "th"},            
          "tr",                      //("Turkish"), "tr"},         
          "uk",                      //("Ukrainian"), "uk"},       
          "vi",                      //("Vietnamese"), "vi"},      
          "cy",                      //("Welsh"), "cy"},           
          "yi"                       //("Yiddish"), "yi"},         
     };

     const unsigned getmethod_maxsize = 240;
     const string urlpattern = "http://translate.google.com.hk/translate_a/t?client=t&sl=_ls&tl=_lt&ie=_ei&oe=_eo&text=_yrueq";
     const string postpattern = "client=t&sl=_ls&tl=_lt&ie=_ei&oe=_eo&text=_yrueq";
     
}




string googleurl::getBody ()
{
     string url(googleconf::urlpattern);
     string::size_type pos = 0;
     if ( query_.empty() )
          return string("http://translate.google.com.hk/translate_a/t");

     
     pos = url.find("_ls", pos);
     if ( pos == string::npos )
          assert(false);
     url.replace(pos, 3, string(googleconf::google_lan[from_]) );

     pos = url.find("_lt", pos);
     if ( pos == string::npos )
          assert (false);
     url.replace(pos, 3, string(googleconf::google_lan[to_]) );

     pos =  url.find("_ei", pos);
     if ( pos == string::npos )
          assert (false);
     url.replace(pos, 3, scode_ );

     pos =  url.find("_eo", pos);
     if ( pos == string::npos )
          assert (false);
     url.replace(pos, 3, dcode_ );

     
     pos = url.find("_yrueq", pos);
     if ( pos == string::npos )
          assert (false);
     url.replace(pos, string("_yrueq").length(), common_encode_url(query_) );
     
     return url;
}

string googlepost::getBody ()
{
     if ( query_.empty() )
          return string();

     string post (googleconf::postpattern);
     string::size_type pos = 0;
     
     pos = post.find("_ls", pos);
     if ( pos == string::npos )
          assert(false);
     post.replace(pos, 3, string(googleconf::google_lan[from_]) );

     pos = post.find("_lt", pos);
     if ( pos == string::npos )
          assert (false);
     post.replace(pos, 3, string(googleconf::google_lan[to_]) );

     pos =  post.find("_ei", pos);
     if ( pos == string::npos )
          assert (false);
     post.replace(pos, 3, scode_ );

     pos =  post.find("_eo", pos);
     if ( pos == string::npos )
          assert (false);
     post.replace(pos, 3, dcode_ );

     
     pos = post.find("_yrueq", pos);
     if ( pos == string::npos )
          assert (false);
     post.replace(pos, string("_yrueq").length(),query_);
     
     return post;
     

}


string googletranslate::buildHead()
{
     string head;
     if ( IsPostMethod() ) // build the post method head;
     {
          head ="POST http://translate.google.cn/translate_a/t HTTP/1.1\r\n" ;
          head +="Content-Type: application/x-www-form-urlencoded; charset=UTF-8\r\n";
          head += "Host: translate.google.cn\r\n";
     }
     
    
     head += "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
     head += "Accept-Language: zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3\r\n";
     head +="Connection: close\r\n";
     return head ;
     
          


}

     



// void googletranslate::translate ()
// {
//      string str_tmp ;
//      str_tmp = (string) url_;
     
//      downloader_.setUrl(str_tmp);
//      string head;
//      downloader_.addHead("Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
//      downloader_.addHead("Accept-Language: zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3");
//      downloader_.addHead("Connection: close");
//      downloader_.addHead("Content-Type: text/javascript; charset=UTF-8");
     
//      if ( downloader_.sendRequest() )
//      {
//           downloader_.handleResponse();
//           str_tmp = downloader_.getResult()  ;
//           parser_->parser( str_tmp );
     
//      }
     
    
     
// }


void googletranslate::translate ()
{
     string tmp;
     tmp = (string) url_;
     
     downloader_.setUrl(tmp);
     tmp.clear();
     tmp = buildHead();
     downloader_.setHead(tmp);
     downloader_.setBody(body_);

     if ( downloader_.sendRequest() )
     {
          downloader_.handleResponse();
          tmp = downloader_.getResult()  ;
          if ( ! IsPostMethod() )
               tmp += "ISGETMETHOD";
          
               
          parser_->parser( tmp );    
     
     }
     
          

}


     



#endif 
