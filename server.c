#include "conf.h"
#include "aes.h"
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

  char conv_buf[MAX_LINE];
  char *pad_buf;
	uint8_t *Round_key;
  uint8_t plain[4][4] = {0, };
  uint8_t cipher[4][4] = {0, };



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

    Round_key = malloc(ROUND_KEY_LENGTH);
    key_init(NUM_KEY_INIT);

    printf("Key INFO:\n");
    key_expansion(key, Round_key);
	}

	while(1){

		printf("Message Receives ...\n");
		nRecv = recv(clntSock, buf, sizeof(buf) - 1, 0);


		if(nRecv < 0){
			perror("receive error");
			exit(1);
		}
		buf[nRecv] = '\0';

    aes_dec(buf, plain, Round_key);	
    inv_convertor(plain, conv_buf);

		if(strcmp(buf, "exit") == 0){
			printf("Close client Connection..\n");
			break;
		}

    printf("----- Recv message info\n");
    printf("### origianl binary: ");
    display_uint8_double_array(buf, 4, 4);
    printf("\n");
    printf("### decrypted binary: ");
    display_uint8_double_array(plain, 4, 4);
    printf("\n");
    printf("Decrypted data: %s\n\n", conv_buf);
    
		printf("\nSend Message (context size must under 16): ");

		gets(buf);
		if(strcmp(buf, "exit") == 0){
			send(clntSock, buf, (int)strlen(buf), 0);
			break;
		}

		pad_buf = padding(buf);
		convertor(pad_buf, plain);
    aes_enc(plain, cipher, Round_key);	


    printf("----- Send message info\n");
    printf("### origianl binary: ");
    display_uint8_double_array(plain, 4, 4);
    printf("\n");
    printf("### encrypted binary: ");
    display_uint8_double_array(cipher, 4, 4);
    printf("\n");
    printf("Original data: %s\n\n", pad_buf);

		send(clntSock, (void *)cipher, 16, 0);


	} // end of while
	close(clntSock);
	printf("Close Connection...\n");

	return 0;	
}

