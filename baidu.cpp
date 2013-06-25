#include "manage/baidutranslate.hpp"
#include "manage/googletranslate.hpp"

#include <cstdlib>
#include <algorithm>
#include <getopt.h>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

struct languagemap {
     string language;
     unsigned  baidu_lan;
     unsigned google_lan;

};


static  char * const  short_option = "s:d:f:h";
static const  option long_option[] = {
     { "src-lanaguage", 0, NULL, 's'},
     { "dst-lanaguage", 0, NULL, 'd'},
     { "filename", 0, NULL, 'f'},
     {"help", 0, NULL, 'h'},
     { NULL, 0, NULL, 0}
} ;

static languagemap glan[] =
{
     { "Auto", baiduconf::Auto, googleconf::Auto },
     { "English", baiduconf::English, googleconf::English },
     { "Chinese", baiduconf::Chinese, googleconf::Chinese },
     { "Japanese",  baiduconf::Japanese, googleconf::Japanese }
};
     

int  whichLanguage ( const string lan )
{
     unsigned i = 0;
     unsigned size = sizeof(glan)/sizeof(languagemap);
     while ( i < size )
     {
          if ( glan[i].language == lan )
               return i;
          i ++;
                    
     }
     return -1;

}

void helpManual ()
{
     cout << " Usage: \n";
     cout << " baidu -s [language code] -d [language code] -f filename " << endl;
     cout << " language code can be the value of  Auto, English, Chinese,Japanese" << endl;

}



int main (int argc, char *argv[] )
{
     int c_opt;
     unsigned  baidusrc = baiduconf::English;
     unsigned baidudst = baiduconf::Chinese;
     unsigned googlesrc = googleconf::English;
     unsigned googledst = googleconf::Chinese;
     int i ;
     // string filename("spiece_mariah.txt");
     string filename ;
     string query ;
     // if ( argc < 2 )
     // {
     //      helpManual();
     //      exit (1);
     // }
     while ( (c_opt=getopt_long(argc, argv, short_option, long_option, NULL)) != -1 )
     {
          switch (c_opt){
          case 's':
               if ( (i = whichLanguage( optarg )) != -1 )
               {
                    baidusrc = glan[i].baidu_lan ;
                    googlesrc = glan[i].google_lan ;
               }
               break;
          case 'd':
               if ( (i = whichLanguage( optarg )) != -1 )
               {
                    baidudst = glan[i].baidu_lan ;
                    googledst = glan[i].google_lan ;
               }
               break;
          case 'f':
               filename = optarg;
               break;

               
          default :
               helpManual();
               
          };
     }

     
   
     // copy( (istream_iterator < string > (cin)), (istream_iterator<string> ()), query );
     // istream_iterator<string> cinstr(cin);
     // while ( cinstr != istream_iterator<string>() )
     //      query += *cinstr++;

     string line ;
    
     if ( ! filename.empty() )
     {
          ifstream input(filename.c_str() );
          while ( input >> line  )
               query += line + ' ' ;
     }
     else
     {
          while ( cin  >> line  )
               query += line + ' ' ;
     }
     // for debug 
     // cout << "query result\n" << query << endl;

    


     
     baidutranslate b;
     // b.setLanguage(baiduconf::Auto, baiduconf::Auto);
     b.setLanguage(baidusrc, baidudst);
     b.translate(query);
     cout << "baidu result:\n" << b.getResult() << endl << endl;
     
     
     googletranslate g;
     g.setLanguage(googlesrc,googledst);
     // g.setLanguage(googleconf::Chinese ,googleconf::English);
     g.translate(query);
     cout << "google result:\n" << g.getResult() << endl;



     
     return 0;
     

}
