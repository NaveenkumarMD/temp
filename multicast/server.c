#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<net/if.h>
#include<time.h>
#include<unistd.h>
void main()
{
int s,k,len;
const  int on=1;

char file_buffer1[1024]="CSE question paper", file_buffer2[1024]="ECE quesion paper", file_buffer3[1024]="IT question paper";

struct sockaddr_in servaddr, cliaddr1, cliaddr2, cliaddr3;

s = socket(AF_INET, SOCK_DGRAM,0);
perror("Socket status\n");

bzero(&servaddr, sizeof(servaddr));
servaddr.sin_port=htons(5000);
servaddr.sin_family=AF_INET;
inet_pton(AF_INET,  "10.0.2.15",&servaddr.sin_addr.s_addr);

bzero(&cliaddr1, sizeof(cliaddr1));
cliaddr1.sin_port=htons(5000);
cliaddr1.sin_family=AF_INET;
inet_pton(AF_INET, "227.0.0.2",&cliaddr1.sin_addr.s_addr);
len=sizeof(struct sockaddr);
sendto(s,file_buffer1,sizeof(file_buffer1),0,(struct sockaddr*)&cliaddr1,len);

bzero(&cliaddr2, sizeof(cliaddr2));
cliaddr2.sin_port=htons(5000);
cliaddr2.sin_family=AF_INET;
inet_pton(AF_INET, "225.0.0.16",&cliaddr2.sin_addr.s_addr);
sendto(s,file_buffer2,sizeof(file_buffer2),0,(struct sockaddr*)&cliaddr2,len);

bzero(&cliaddr3, sizeof(cliaddr3));
cliaddr3.sin_port=htons(5000);
cliaddr3.sin_family=AF_INET;
inet_pton(AF_INET, "226.0.0.4",&cliaddr3.sin_addr.s_addr);
sendto(s,file_buffer3,sizeof(file_buffer3),0,(struct sockaddr*)&cliaddr3,len);

perror("status");
}
