#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


int main(){
	char *ip_addr = "192.168.1.100";
	int port_server = 8888;

	int sockfd_server, sockfd_client;
	struct sockaddr_in addr_server, addr_client;
	addr_server.sin_family = AF_INET;
	addr_server.sin_port = htons(port_server);
	addr_server.sin_addr.s_addr = inet_addr(ip_addr);

	sockfd_server = socket(AF_INET, SOCK_STREAM, 0);

	ssize_t ret = bind(sockfd_server, (struct sockaddr*)&addr_server, sizeof(addr_server));
	
	if(ret == -1){
		printf(" Bind Failure \n");
		perror("Error:");
		exit(0);
	}

	listen(sockfd_server, 1);

	socklen_t len = sizeof(addr_client);
	sockfd_client = accept(sockfd_server, (struct sockaddr*)&addr_client, &len);

	char buff[5] = {(char)0xff, 0 , 0 , 0 , 0};

	while(buff[0] == (char)0xff && buff[1] == (char)0x00){
		memset(buff, 0x00, sizeof(buff));
		ret = recv(sockfd_client, (void*)buff, sizeof(buff), 0);
		if(ret == -1){
			printf("Recv Failure\n");
			perror("Error");
			sleep(1);
			continue;
		}

		printf("Get a command: ");
		for(int i = 0; i < 5; i++){
			printf("%d ", buff[i]);
		}

		if(buff[2] == 0){
			printf("function: stop\n");
		}

		if(buff[2] == 1){
			printf("function: up\n");
		}

		if(buff[2] == 2){
			printf("function: down\n");
		}

		if(buff[2] == 3){
			printf("function: left\n");
		}

		if(buff[2] == 4){
			printf("function: right \n");
		}
	}

	close(sockfd_client);
	close(sockfd_server);
	
	return 0;
}
