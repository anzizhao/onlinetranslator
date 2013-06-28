#ifndef BAIDUENGINEHPP
#define BAIDUENGINEHPP

#include "basictranslateEngine.hpp"
#include <Node.h>



class baiduengine : public basictranslateEngine
{
private:
     bool tostartflag;
     int countstartflag;
public :
     baiduengine()
          {
          }
     ~baiduengine()
          {
          }
     
protected:

     virtual void beginParsing();
     

     virtual void foundTag(Node node, bool isEnd);
     
     virtual void foundText(Node node) ;
     
     
     //   virtual void foundComment(Node node) {}

     virtual void endParsing();
     
};

     




#endif 
