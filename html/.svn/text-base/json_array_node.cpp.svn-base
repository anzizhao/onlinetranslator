#ifndef JSONARRAYNODECPP
#define JSONARRAYNODECPP

#include "json_array_node.hpp"
#include <iostream>


list<basenode *> arraynode::getValue ( const string &key)
{
     basenode::value_type vt;
     vt = basenode::valueType(key);

     
     list<basenode*>::iterator it = values_.begin();
     list<basenode*>::iterator end = values_.end();
     basenode *node;
     list<basenode *> result;
     
     while ( it != end )
     {
          node = *it;
          if ( node->valueType() == vt )
          {
               //如果是strnode 要值配对
               if ( vt == basenode::VALUESTRING )
               {
                    strnode *snode = dynamic_cast<strnode *>(node);
                    if (  snode->getStr() == key )
                          result.push_back(node);
               }
               else
                    result.push_back(node);
          }
          
          it ++;
          

     }
     
     return result;
     
}



void arraynode::add(basenode *node)
{
     values_.push_back(node);
     
}

void arraynode::del(const string &key )
{
     list<basenode*> result;

     
     result = getValue(key);
     if ( result.empty() )
          return ;

     list<basenode*>::iterator it = result.begin();
     list<basenode*>::iterator end = result.end();
     basenode * node;
     while ( it != end )
     {

          
          delete *it;
          *it = NULL;
          it ++;
          
     }

     result.remove(NULL);
}


arraynode::~arraynode ()
{
     list<basenode*>::iterator it = values_.begin();
     list<basenode*>::iterator end = values_.end();
     basenode * node;
     
     while ( it != end )
     {
          node = *it;
          *it = NULL;
          
          it ++;
          delete node;
          
     }
          
}

string arraynode::showJson (int spacenum)
{
     list<basenode*>::iterator it = values_.begin();
     list<basenode*>::iterator end = values_.end();
     basenode * node;

     string result ;
     
     while ( it != end )
     {
          node = *it;
          result += node->showJson(0);
          it ++;
     }

     if ( ! key_.empty() )
          result += key_ + ':';
     return result += text_ + '\n';
     

}


/////////////////////////////////////////////
jsonnode::~jsonnode ()
{
     list<basenode*>::iterator it = nodes_.begin();
     list<basenode*>::iterator end = nodes_.end();
     
     basenode * node;
     while ( it != end )
     {
          node = *it;
          *it = NULL;
          it ++;
          delete node;
          
     }

}

void jsonnode::add(basenode *node)
 {
      nodes_.push_back(node);
      
 }

     
void jsonnode::del(const string & keys)
{
     list<basenode*> result;
     
     result = getValue(keys);

     if ( result.empty() )
          return ;

     list<basenode *>::iterator  it = result.begin();
     list<basenode *>::iterator  end = result.end();
     
    

     while ( it != end )
     {
     
          delete *it;
          *it = NULL;
          it ++;
     }
     nodes_.remove(NULL);
}


list<basenode *> jsonnode::getValue ( const string &key  )
{
     list<basenode *> result;
     
     list<basenode*>::iterator it = nodes_.begin();
     list<basenode*>::iterator end = nodes_.end();

     basenode * node ;
     
     while ( it != end )
     {
          node = *it;
          if ( node->getKey() == key )
               result.push_back(node);
          
          it ++;
          
     }

     return result;
}



vector<string> jsonnode::listkeys ()
{
     list<basenode*>::iterator it = nodes_.begin();
     list<basenode*>::iterator end = nodes_.end();
     basenode *node ;
     vector<string> tmp;
     
     while ( it != end )
     {
          
          node = *it;
          tmp.push_back(node->getKey());
          it ++;
          
     }
     return tmp;
     
}

string jsonnode::showJson (int spacenum)
{
     list<basenode*>::iterator it = nodes_.begin();
     list<basenode*>::iterator end = nodes_.end();
     basenode *node ;
     string result;

     while ( it != end )
     {
          node = *it;
          result += node->showJson(0);
          it ++;
     }

     if ( ! key_.empty() )
          result += key_ + ':';
     
     return result += text_ + '\n';
     
}

#endif
