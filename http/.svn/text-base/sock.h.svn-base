#ifndef UNIXSOCKH
#define UNIXSOCKH


#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>



#define MAXDATASIZE 512
using namespace std;


class Sock
{
private:
     struct sockaddr_in  host_;
     int port_;
     int sockfd;
     struct hostent *ip;
public:
   
     bool  Connect(const string &host,unsigned short port );
     int  Recv(char *buf, int size );
     int Send (char *buf, int size );
     void Close();
};



#endif
