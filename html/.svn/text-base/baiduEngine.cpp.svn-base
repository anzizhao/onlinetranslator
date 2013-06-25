#ifndef BAIDUENGINECPP
#define BAIDUENGINECPP

#include "baiduEngine.hpp"



void baiduengine::beginParsing()
{
     
     tostartflag  = true;
     countstartflag = 0;
     

}


void baiduengine::foundTag( Node node, bool isEnd )
{
     // const string &tagname = node.tagName();
     // cout << "tag : " ;
     // cout << node.text() << endl;
     // cout << tagname << endl;
     // node.parseAttributes();
     
     //   cout <<  node.attribute("id").second << " " <<  node.attribute("lang").second << endl;
     
     
     // if ( tagname == string("div")
     //      && node.attribute("id").second == string("dict-wraper") )
     //      tostartflag = true;

     // if ( ! tostartflag )
     //      return ;
     //cout << node.text() << endl;
     
    //记录开始标签
     // if (  tagname == string("div") )
     //      isEnd?--countstartflag:++countstartflag;
     
     // //判断选中的一段是否结束
     // if ( countstartflag == 0 )
     // {
     //      tostartflag = false;
     //      return ;
          
     // }
     
     // 是否会影响文本的标签<br> <p>
     if ( affect_text_tag(node, isEnd) )
          return ;

    
     
}

void baiduengine::foundText(Node node)
{
     // cout << "text: " ;
     // cout << node.text() << endl;
     
     if ( tostartflag )
     {
          
          str_result += node.text();
     }
     

}

void baiduengine::endParsing()
{
     
     //可以做一些检测
     string str;
     // &nbsp;
     string::size_type pos = 0;
     string special("&nbsp;");
     
     while ( pos < str_result.length() )
     {
         
          pos = str_result.find(special, pos);
          if ( pos == string::npos )
               break;
          
          str_result.replace(pos, special.length(), " ");
          pos ++;
          
     }
     //可以使用include函数的
     pos = 0;
     
     special = "&gt;";
     while ( pos < str_result.length() )
     {
         
          pos = str_result.find(special, pos);
          if ( pos == string::npos )
               break;
          
          str_result.replace(pos, special.length(), ">");
          pos ++;
          
     }

    pos =  str_result.find("[英]");
    string::size_type end;
    end = str_result.rfind("]");
    str_result.replace(pos, end-pos+1, " " );
    
     
     
}

#endif 
