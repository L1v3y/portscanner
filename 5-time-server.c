#include<sys/types.h> // defines the data types of socket address structure
#include<sys/socket.h> // taking pointer to the generic socket address structure
#include<netinet/in.h> // IPv4 socket address structure
#include<arpa/inet.h> // convert internet addresses between ascii strings and network byte ordered binaryvalues.
#include<string.h> // strings as it say.
#include<stdio.h> // standard input and output.
#include<time.h>

int main(int asgrc, char *argv[]){
    int bd,sd,ad; //bd = bind sd=socket ad=accept
    char buff[1024]; // random buffer size
    struct sockaddr_in cliaddr,servaddr; //sock address, client add,serv add
    socklen_t clilen;
    time_t tick;
    clilen=sizeof(cliaddr);
    bzero(&servaddr,sizeof(servaddr));

    //socket address structure
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(1999);

    //TCP socket is created, an internet socket address strucutre is filled with wildcard address & server's wee know port
    sd=socket(AF_INET,SOCK_STREAM,0);

    //bind function assigns a local protocol address to the socket
    bd-bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    //Listen function specifies the maximum number of connections that kernel should queue for this socket*./
    listen(sd,5);
    printf("Server is running...\n");
    
    //The server to return thenext completed connection from the front of the completed coneection queue calls it

    ad=accept(sd,(struct sockaddr*)&cliaddr,&clilen);

    
    bzero(&buff,sizeof(buff));
    tick=time(NULL);

    snprintf(buff,sizeof(buff),"%s",ctime(&tick));
    printf("%s\n",buff);
    write(ad,buff,100);
    
}