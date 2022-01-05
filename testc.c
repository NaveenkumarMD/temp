#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>

#define PORT 6000
#define SA struct sockaddr
#define MAX 1024

int main(){
	int sockfd,on=1;
	struct sockaddr_in cli,servaddr;
	sockfd=socket(PF_INET,SOCK_DGRAM,0);
	perror("Socket");

	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

	cli.sin_family=AF_INET;
	cli.sin_port=htons(PORT);
	cli.sin_addr.s_addr=INADDR_ANY;

	bind(sockfd,(SA*)&cli,sizeof(struct sockaddr));
	perror("Bind");

	char buff[1024];
	int len=sizeof(struct sockaddr_in);
	recvfrom(sockfd,buff,sizeof(buff),0,(SA*)&servaddr,&len);
	perror("Recieved");
	printf("From client %s",buff);
	return 0;
}