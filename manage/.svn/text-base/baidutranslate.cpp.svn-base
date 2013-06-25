#ifndef BAIDUTRANSLATECPP
#define BAIDUTRANSLATECPP

#include "baidutranslate.hpp"
#include "../html/baiduparser.hpp"

#include <iostream>

using namespace std;

const string postbody::pattern_ = "ie=_edoc&source=txt&query=_yreuq&from=_morf&to=_ot";
const char * postbody::language[] = {
     "auto","en","zh","jp"
};
//const string baidutranslate::url_ = "http://fanyi.baidu.com/" ;

namespace debug {
     


}





istream & operator >> (istream &in, postbody &body )
{
     string line;
     body.query_.clear();
     
     while ( getline(in,line ) )
          body.query_ += line;
     
     return in;
}



postbody::operator string ()
{
     return getBody();
     
}


string postbody::getBody ()
{
     string pattern = pattern_;
     
     string::size_type pos ;
     pos = pattern.find("_edoc");
     pattern.replace(pos, 5, scode_ );

     pos = pattern.find("_yreuq");
     pattern.replace(pos, 6, query_);

     pos = pattern.find("_morf");
     pattern.replace(pos, 5, string(language[from_]));

     pos = pattern.find("_ot");
     pattern.replace(pos, 3, string(language[to_]));

     return pattern;
     
}



string  baidutranslate::buildHead()
{
     string cmd;
     cmd ="POST /transcontent HTTP/1.1\r\n" ;
     cmd += "Host: fanyi.baidu.com\r\n";
     cmd += "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
     cmd += "Accept-Language: zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3\r\n";
     cmd +="Connection: close\r\n";
     cmd +="Content-Type: application/x-www-form-urlencoded; charset=UTF-8\r\n";
     return cmd ;
     
}

void baidutranslate::init ()
{

     //  downloader_.setUrl(url_);
     // downloader_.setMethod(httpclient::POSTMETHOD);
     downloader_.setHead( buildHead() );

     to_translate_.setLanguage(baiduconf::Auto, baiduconf::Chinese);
     parser_ = new baiduparser;
     
     
}



void baidutranslate::translate()
{
     cin >> to_translate_;
     //   cout << "get the result page:" << to_translate_.getBody()  << endl;
     downloader_.setBody( (string) to_translate_ );
     downloader_.sendRequest();
     downloader_.handleResponse();
     string temp;
     temp =  downloader_.getResult();
     
     parser_->parser( temp );
     
}

void baidutranslate::translate(const string &content )
{
     string tmp;
     
     to_translate_.setQuery( content );
     downloader_.setBody( (string) to_translate_ );
     downloader_.sendRequest();
     downloader_.handleResponse();
     tmp = downloader_.getResult();
     
     parser_->parser( tmp );
}


string baidutranslate::getResult ()
{
     return parser_->getResult();
     
}



#endif
