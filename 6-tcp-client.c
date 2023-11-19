#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>

int main(int agrc,char *argv[]){
    int bd,sd,cd;
    char buff1[1024],buff2[1024];
    struct sockaddr_in servaddr,cliaddr;
    socklen_t clilen;
    clilen=sizeof(cliaddr);
    bzero(&servaddr,sizeof(servaddr));

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(1999);

    sd=socket(AF_INET,SOCK_STREAM,0);


    cd=connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    while(1){
        bzero(&buff2,sizeof(buff2));
        printf("Enter the text is send...");
        fgets(buff2,100,stdin);
        send(sd,buff2,sizeof(buff2),0);
        bzero(&buff1,sizeof(buff1));
        recv(sd,buff1,sizeof(buff1),0);
        printf("Client Message...%s",buff1);  
    }
}