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
char buff[20];
int len;
struct sockaddr_in cliaddr,servaddr;
bzero ((void *)&cliaddr,sizeof(cliaddr));
sockfd = socket(PF_INET,SOCK_DGRAM,0);
perror("Sock Status\n");
setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

cliaddr.sin_family=PF_INET;
cliaddr.sin_addr.s_addr= INADDR_ANY;
cliaddr.sin_port=htons(6000);

bind(sockfd,(struct sockaddr*)&cliaddr,sizeof(struct sockaddr));
perror("Bind status\n");

	len=sizeof(struct sockaddr_in);

	recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&servaddr,&len);
	printf("%s\n",buff);
	fflush(NULL);


}