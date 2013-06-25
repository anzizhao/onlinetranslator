#include "jsonparser.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ( int argc, char *argv[] )
{
     ifstream infile;
     string str;
     string line;
     
     infile.open(argv[1]);
     
     while ( getline(infile, line))
          str += line;

     cout << str << endl;

     string  result;
    
     
     jsonparser jparser;
     jparser.parserJson(str);
     jparser.listJson();

     
     result = jparser.getValue(string("\"data\""));
     cout <<  "\"data\":" << result << endl;

     result.clear();
     
     if ( argc > 2 )
     {
          result = string(argv[2]);
          
     }

     result = jparser.getValue( result );
     cout <<  result << ":" << result << endl;
     
     
     
     return 0;
     

}
