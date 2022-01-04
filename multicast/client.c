#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<net/if.h>
#include<time.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
int s,k,mlen,on=1,opt;
char buff1[100], msg[200],id[34];
struct sockaddr_in servaddr, cliaddr;
struct ip_mreq mreq;
printf("Enter the option for your department\n1.CSE\n2.ECE\n3.IT\n");
scanf("%d",&opt); 
s = socket(PF_INET, SOCK_DGRAM,0);
perror("Socket status\n");
setsockopt(s,SOL_SOCKET, SO_REUSEADDR,&on, sizeof(on));

bzero((void *)&servaddr, sizeof(servaddr));
servaddr.sin_port=htons(5000);
servaddr.sin_family=AF_INET;
//cliaddr.sin_addr.s_addr=INADDR_ANY;
inet_pton(AF_INET, "10.0.2.15",&servaddr.sin_addr.s_addr);

mlen=sizeof(struct sockaddr_in);
if(opt==1){
bzero((void *)&cliaddr, sizeof(cliaddr));
cliaddr.sin_port=htons(5000);
cliaddr.sin_family=AF_INET;
inet_pton(AF_INET, "227.0.0.2",&cliaddr.sin_addr.s_addr);
bind(s,(struct sockaddr* )&cliaddr, sizeof(struct sockaddr));
perror("Bind status\n");
inet_pton(AF_INET, "227.0.0.2",(struct inaddr*)&mreq.imr_multiaddr);
inet_pton(AF_INET,  "10.0.2.15",(struct inaddr*)&mreq.imr_interface);
setsockopt(s,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq));
setsockopt(s,IPPROTO_IP,IP_MULTICAST_LOOP,&mlen,sizeof(mlen));
}
if (opt==2){
bzero((void *)&cliaddr, sizeof(cliaddr));
cliaddr.sin_port=htons(5000);
cliaddr.sin_family=AF_INET;
inet_pton(AF_INET, "225.0.0.16",&cliaddr.sin_addr.s_addr);
bind(s,(struct sockaddr* )&cliaddr, sizeof(struct sockaddr));
perror("Bind status\n");
inet_pton(AF_INET, "225.0.0.16",(struct inaddr*)&mreq.imr_multiaddr);
inet_pton(AF_INET,  "10.0.2.15",(struct inaddr*)&mreq.imr_interface);
setsockopt(s,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq));
setsockopt(s,IPPROTO_IP,IP_MULTICAST_LOOP,&mlen,sizeof(mlen));
}
if (opt==3){
bzero((void *)&cliaddr, sizeof(cliaddr));
cliaddr.sin_port=htons(5000);
cliaddr.sin_family=AF_INET;
inet_pton(AF_INET, "226.0.0.4",&cliaddr.sin_addr.s_addr);
bind(s,(struct sockaddr* )&cliaddr, sizeof(struct sockaddr));
perror("Bind status\n");
inet_pton(AF_INET, "226.0.0.4",(struct inaddr*)&mreq.imr_multiaddr);
inet_pton(AF_INET,  "10.0.2.15",(struct inaddr*)&mreq.imr_interface);
setsockopt(s,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq));
setsockopt(s,IPPROTO_IP,IP_MULTICAST_LOOP,&mlen,sizeof(mlen));
}
recvfrom(s,buff1,sizeof(buff1),0,(struct sockaddr *) & servaddr, &mlen);
printf("msg from server is: %s\n",buff1);
close(s);
}
