#include "conf.h"
#include "func.h"
#include "aes.h"

int main()
{
	// Set Values
	struct sockaddr_in servAddr;
	int clntSock;

	char sAddr[15];
	int sPort, nRecv;
	unsigned int Addr;
	char buf[MAX_LINE];

  char conv_buf[MAX_LINE];
  char *pad_buf;
	uint8_t *Round_key;
  uint8_t plain[4][4] = {0, };
  uint8_t cipher[4][4] = {0, };


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

    Round_key = malloc(ROUND_KEY_LENGTH);
    key_init(NUM_KEY_INIT);

    printf("Key INFO:\n");
    key_expansion(key, Round_key);
	}

	while(1){
		printf("\nSend Message (context size must under 16): ");
    gets(buf);

		if(strcmp(buf, "exit") == 0){
			send(clntSock, buf, (int)strlen(buf), 0);
			break;
		}

    // Ecrypt AES function
		pad_buf = padding(buf);
		convertor(pad_buf, plain);
    aes_enc(plain, cipher, Round_key);	
    inv_convertor(cipher, conv_buf);

    printf("----- Send message info\n");
    printf("### origianl binary: ");
    display_uint8_double_array(plain, 4, 4);
    printf("\n");
    printf("### encrypted binary: ");
    display_uint8_double_array(cipher, 4, 4);
    printf("\n");
    printf("Original data: %s\n\n", pad_buf);

		send(clntSock, (void *)cipher, 16, 0);
		printf("Message Receives ...\n");

		nRecv = recv(clntSock, buf, sizeof(buf) - 1, 0);
		if(nRecv < 0){
			perror("Receive Error...\n");
			break;
		}

		buf[nRecv] = '\0';

    aes_dec(buf, plain, Round_key);	
    inv_convertor(plain, conv_buf);

		if(strcmp(buf, "exit") == 0){
			printf("Close Server Connection...\n");
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

	}

	close(clntSock);
	printf("Close Connection...\n");

	return 0;



}
