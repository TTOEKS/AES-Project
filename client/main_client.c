#include "../conf.h"

int main()
{
	// Set Values
	struct sockaddr_in servAddr;
	int clntSock;

	char sAddr[15];
	int sPort, nRecv;
	unsigned int Addr;
	char buf[MAX_LINE];

	struct hostent *host;

	printf("Server Address : ");
	gets(sAddr);

	clntSock = socket(AF_INET, SOCK_STREAM, 0);
	if(clntSock < 0){
		perror("Socket Error");
		exit(1);
	}

	memset(&servAddr, 0, sizeof(servAddr));
	
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(sAddr);
	servAddr.sin_port = htons(PORT);

	if(connect(clntSock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0){
		perror("Connection Error...\n");
		exit(1);
	} else{
		printf("Connect Success!!\nStart...\n");
	}

	while(1){
		printf("\nSend Message : ");
		gets(buf);

		if(strcmp(buf, "exit") == 0){
			send(clntSock, buf, (int)strlen(buf), 0);
			break;
		}

		send(clntSock, buf, (int)strlen(buf), 0);
		printf("Message Receives ...\n");

		nRecv = recv(clntSock, buf, sizeof(buf) - 1, 0);
		if(nRecv < 0){
			perror("Receive Error...\n");
			break;
		}

		buf[nRecv] = '\0';

		if(strcmp(buf, "exit") == 0){
			printf("Close Server Connection...\n");
			break;
		}

		printf("Receive Message : %s", buf);

	}

	close(clntSock);
	printf("Close Connection...\n");

	return 0;


}
