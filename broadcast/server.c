#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>

int main(){
int sockfd,on=1;
int len ;
char buff[20];
struct sockaddr_in servaddr,cliaddr,baddr;

sockfd = socket(PF_INET,SOCK_DGRAM,0);
perror("Sock Status\n");
setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&on,sizeof(on));

servaddr.sin_family=PF_INET;
servaddr.sin_addr.s_addr= INADDR_ANY;
servaddr.sin_port=htons(5000);

bind(sockfd,(struct sockaddr*)&servaddr,sizeof(struct sockaddr));
perror("Bind status\n");

baddr.sin_family=AF_INET;
baddr.sin_port=htons(6000);
inet_pton(AF_INET,"255.255.255.255",(void*)&baddr.sin_addr);
printf("Enter a msg\n");
scanf("%[^\n]s",buff);

	sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&baddr,sizeof(baddr));
	fflush(NULL);


printf("BROADCAST SENT");
}