#include "baiduEngine.hpp"
#include "jsonparser.hpp"
#include "baiduparser.hpp"
#include "googleparser.hpp"
#include <fstream>
#include <iostream>
using namespace std;



int main ( int argc , char *argv[] )
{

     string filename(argv[1]);
     string line, html;
     
     ifstream infile(filename.c_str());
     while ( getline(infile, line))
          html += line;
     
     
  

     // string html1;
     // html1 = html;
     // // cout << "Using the jsonparser and the html" << endl;
     
     // jsonparser jparser;
     // jparser.parserJson(html);
     // html = jparser.getValue(string("\"result\""));
     // delete_slash(html);

     // cout << "after json parser\n" << html << endl;
     
     //  // basictranslateEngine *transEngine = new baiduengine;
     // // transEngine->parse(html);

     // baiduengine  trans ;
     // trans.parse(html);
     // cout << "\nafter the html parser\n\n" << endl;
     
     // cout<< trans.getResult() << endl;



     // //  cout << "Using the baiduparser class" << endl;
     
     // baiduparser bparser;
     // bparser.parser(html1);
     // cout << bparser.getResult() << endl;


     googleparser gparser;

     gparser.parser(html);
     cout << gparser.getResult() << endl;
     
     
     return 0;
     
}


