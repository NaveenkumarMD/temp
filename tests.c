#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>

#define MAX 1024
#define PORT 6000
#define SA struct sockaddr

int main(){
	int sockfd,on=1;
	struct sockaddr_in servaddr,baddr;

	sockfd=socket(PF_INET,SOCK_DGRAM,0);
	perror("Socket");

	setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&on,sizeof(on));

	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(5000);
	servaddr.sin_addr.s_addr=INADDR_ANY;

	bind(sockfd,(SA*)&servaddr,sizeof(servaddr));
	perror("Bind");

	baddr.sin_family=AF_INET;
	baddr.sin_port=htons(PORT);
	inet_pton(AF_INET,"255.255.255.255",(void *)&baddr.sin_addr);
	perror("BROADCAST set");

	char buff[1024];
	scanf("%s",buff);
	sendto(sockfd,buff,sizeof(buff),0,(SA*)&baddr,sizeof(baddr));
	perror("Send");
	return 0;
}