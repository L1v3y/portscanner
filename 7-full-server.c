#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
int main(int argc,char *argv[])
{
    int clientSocketDescriptor,socketDescriptor;
    struct sockaddr_inserverAddress,clientAddress;
    socklen_tclientLength;
    char recvBuffer[8000],sendBuffer[8000];
    pid_tcpid;
    bzero(&serverAddress,sizeof(serverAddress));

    serverAddress.sin_family=AF_INET;
    serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
    serverAddress.sin_port=htons(9652);

    socketDescriptor=socket(AF_INET,SOCK_STREAM,0);

    bind(socketDescriptor,(struct sockaddr*)&serverAddress,sizeof(serverAddress));

    listen(socketDescriptor,5);
    printf("%s\n","Server is running ...");

    clientSocketDescriptor=accept(socketDescriptor,(struct
    sockaddr*)&clientAddress,&clientLength);

    cpid=fork();
    if(cpid==0)
    {
        while(1)
        {
            bzero(&recvBuffer,sizeof(recvBuffer));
            /*Receiving the request from client*/
            recv(clientSocketDescriptor,recvBuffer,sizeof(recvBuffer),0);
            printf("\nCLIENT : %s\n",recvBuffer);
        }
        }
    else
    {
        while(1)
        {
        bzero(&sendBuffer,sizeof(sendBuffer));
        printf("\nType a message here ... ");
        /*Read the message from client*/
        fgets(sendBuffer,80000,stdin);
        /*Sends the message to client*/
        send(clientSocketDescriptor,sendBuffer,strlen(sendBuffer)+1,0);
        printf("\nMessage sent !\n");
        }
    }
    return 0;
}