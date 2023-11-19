#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>

int main(int agrc,char *argv[]){
    int bd,sd,ad;
    char buff1[1024],buff2[1024];
    struct sockaddr_in servaddr,cliaddr;
    socklen_t clilen;
    clilen=sizeof(cliaddr);
    bzero(&servaddr,sizeof(servaddr));

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(1999);

    sd=socket(AF_INET,SOCK_STREAM,0);

    bd=bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    listen(sd,5);
    printf("Server is running...\n");

    ad=accept(sd,(struct sockaddr*)&cliaddr,&clilen);
    while(1){
        bzero(&buff2,sizeof(buff2));
        recv(ad,buff2,sizeof(buff2),0);
        printf("Client Message...%s",buff2);
        printf("Enter the text is send...");
        fgets(buff1,100,stdin);
        send(ad,buff1,sizeof(buff1),0);
    }
}