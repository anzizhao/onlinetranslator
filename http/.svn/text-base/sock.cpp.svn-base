#ifndef UNIXSOCKCPP
#define UNIXSOCKCPP

#include "sock.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <cstdlib>






bool Sock::Connect ( string const & host, unsigned short port )
{
//得到ip地址
     if ( ( ip = gethostbyname(host.c_str()))  == NULL )
          return false;
     
     if ( (sockfd = socket(AF_INET,SOCK_STREAM, 0)) == -1 )
          return false;

     bzero(& host_, sizeof(host_) );
     host_.sin_family = AF_INET;
     host_.sin_port = htons(port);
     host_.sin_addr = *(struct in_addr *)ip->h_addr;

     if ( connect(sockfd, (struct sockaddr *)& host_, sizeof(struct sockaddr )) == -1 )
          return false;

     return true;
     
     

}


int Sock::Recv ( char *buf, int size )
{
     int nbytes = 0;
     if ( (nbytes = read(sockfd, buf, MAXDATASIZE)) == -1 )
     {
          return -1;
          
     }
     buf[nbytes] = '\0';

     return nbytes;

}

int Sock::Send (char *buf, int size )
{
     
     return write(sockfd, buf, size);
     

}

void Sock::Close()
{
     close(sockfd);
     
     

}


#endif
