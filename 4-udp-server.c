#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
    int sd;
    char buff[1024];
    struct sockaddr_in cliaddr,servaddr;
    socklen_t clilen;
    clilen=sizeof(cliaddr);
    sd=socket(AF_INET,SOCK_DGRAM,0);
    bzero(&servaddr,sizeof(servaddr));

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(5669);

    bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    printf("%s","Server is Running…\n");
    
    while(1)
    {
    bzero(&buff,sizeof(buff));
    recvfrom(sd,buff,sizeof(buff),0,(struct sockaddr*)&cliaddr,&clilen);
    printf("Message is received \n",buff);
    sendto(sd,buff,sizeof(buff),0,(struct sockadddr*)&cliaddr,clilen);
    printf("Send data to UDP Client: %s",buff);

    }
}