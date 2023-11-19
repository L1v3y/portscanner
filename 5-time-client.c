#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>

int main(int asgrc, char *argv[]){
    int cd,sd;
    char buff[1024];
    struct sockaddr_in servaddr,cliaddr;
    struct hostent *h;
    h=gethostbyname(argv[1]);
    bzero(&servaddr,sizeof(servaddr));

    servaddr.sin_family=AF_INET;
    memcpy((char *)&servaddr.sin_addr.s_addr,h->h_addr_list[0],h->h_length);
    servaddr.sin_port=htons(1999);

    sd=socket(AF_INET,SOCK_STREAM,0);

    cd=connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    bzero(&buff,sizeof(buff));
    read(sd,buff,sizeof(buff));
    printf("\nData Received.....%s\n",buff);
    
}