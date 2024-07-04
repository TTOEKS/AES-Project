#include "conf.h"
#include "func.h"

int main(int argc, char **argv)
{
	
	// Set Values
	struct sockaddr_in servAddr, clntAddr;
	int clntSock, servSock;
	pid_t childpid;
	socklen_t clilen;
	char buf[MAX_LINE];
	int nRecv;

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
		nRecv = recv(clntSock, buf, sizeof(buf) - 1, 0);

		if(nRecv < 0){
			perror("receive error");
			exit(1);
		}
		buf[nRecv] = '\0';

		if(strcmp(buf, "exit") == 0){
			printf("Close client Connection..\n");
			break;
		}

    printf("----- Recv message info\n");
    printf("### origianl binary: ");
    display_uint8_double_array(buf, 4, 4);
    printf("\n");
    printf("orignal data: %s\n\n", buf);
    
		printf("\nSend Message (context size must under 16): ");

		gets(buf);
		if(strcmp(buf, "exit") == 0){
			send(clntSock, buf, (int)strlen(buf), 0);
			break;
		}

    printf("----- Send message info\n");
    printf("### Origianl binary: ");
    display_uint8_double_array(buf, 4, 4);
    printf("\n");
    printf("Original data: %s\n\n", buf);

		send(clntSock, buf, 16, 0);

	} // end of while
	close(clntSock);
	printf("Close Connection...\n");

	return 0;	
}

