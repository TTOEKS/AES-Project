#include "../conf.h"

int main(int argc, char **argv)
{
	
	// Set Values
	struct sockaddr_in servAddr, clntAddr;
	int clntSock, servSock;
	pid_t childpid;
	socklen_t clilen;
	char buf[MAX_LINE];
	int nRcv;


	servSock = socket(PF_INET, SOCK_STREAM, 0);
	if(servSock < 0){
		perror("socket error");
		exit(1);
	}
	
	memset(&servAddr, 0, sizeof(servAddr));

	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(PORT);

	if(bind(servSock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0){
		perror("bind error");
		exit(1);
	}
	if(listen(servSock, 5) < 0){
		perror("listen error");
		exit(1);
	}	
	printf("Success setting Server socket...\n");

	clilen = sizeof(clntAddr);
	if((clntSock = accept(servSock, (struct sockaddr *)&clntAddr, &clilen)) < 0){
		perror("accept error");
		exit(1);
	} else{
		printf("%s Connection Complete!\n", inet_ntoa(clntAddr.sin_addr));
		printf("Start ...\n");
	}

	while(1){

		printf("Message Receives ...\n");
		nRcv = recv(clntSock, buf, sizeof(buf) - 1, 0);

		if(nRcv < 0){
			perror("receive error");
			exit(1);
		}
		buf[nRcv] = '\0';

		if(strcmp(buf, "exit") == 0){
			printf("Close client Connection..\n");
			break;
		}

		printf("Receive Message : %s", buf);
		printf("\nSend Message : ");

		gets(buf);
		if(strcmp(buf, "exit") == 0){
			send(clntSock, buf, (int)strlen(buf), 0);
			break;
		}

		send(clntSock, buf, (int)strlen(buf), 0);

	} // end of while
	close(clntSock);
	printf("Close Connection...\n");

	return 0;	
}

