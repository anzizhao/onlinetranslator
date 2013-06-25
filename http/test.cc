#include "httpclient.hpp"
#include <iostream>
#include <string>
using namespace std;





int main ( int argc, char *argv[] )
{
     string body;
     string url = "http://fanyi.baidu.com/transcontent";
     string work(argv[1]);
     
     string e1 = "ie=utf-8&source=txt&query=" + work + "&from=auto&to=auto";
     string e2  = "ie=utf-8&source=txt&query=我没有女朋友，你能不能做我女朋友&from=auto&to=auto";
     string e3  = "ie=utf-8&source=txt&query=I am a good boy&from=auto&to=auto";

     string cmd;
     
 

     cmd ="POST /transcontent HTTP/1.1\r\n" ;
     cmd += "Host: fanyi.baidu.com\r\n";
     //cmd += "User-Agent: Mozilla/5.0 (X11; Linux i686; rv:16.0) Gecko/20100101 Firefox/16.0\r\n";
     cmd += "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
     cmd += "Accept-Language: zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3\r\n";
     cmd +="Connection: close\r\n";
     cmd +="Content-Type: application/x-www-form-urlencoded; charset=UTF-8\r\n";


     //how to use class httpclient 
     // httpclient client;
     // client.setUrl(url);
     // client.setBody(e1);
     // client.setMethod(httpclient::POSTMETHOD);
     // client.setHead(cmd);
     
     // client.sendRequest();
     // client.handleResponse();
     // cout << client.getResult() << endl;
     

     httpclient client;
     client.setUrl(url);
     client.setBody(e1);
     client.setMethod(httpclient::POSTMETHOD);
     client.addHead("Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
     client.addHead("Accept-Language: zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3");
     client.addHead("Connection: close");
     client.addHead("Content-Type: application/x-www-form-urlencoded; charset=UTF-8");
     
     
     client.sendRequest();
     client.handleResponse();
     cout << client.getResult() << endl;
     client.list();
     

     //  cout << body << endl;
     return 0;
     

}
