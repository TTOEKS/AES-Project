#include<stdio.h>
#include"aes.h"
#include"../func/func.h"

// void display_matrix(int *a, int columns_size, int size);

int main(){
	uint8_t key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2,
		0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};

	uint8_t plain[4][4] = {
		{0x00, 0x11, 0x22, 0x33},
		{0x44, 0x55, 0x66, 0x77},
		{0x88, 0x99, 0xaa, 0xbb},
		{0xcc, 0xdd, 0xee, 0xff}};

	uint8_t cipher[4][4];
	uint8_t dec_test[4][4];
	uint8_t *Round_key;
	char title[64], inv_title[64];
	char *padding_result;
	int  i, j;
	size_t title_len;

	
	// Start Main Code
	printf("파일명을 16자리 이하로 입력해주세요:");
	scanf("%s", title);
	title_len = strlen(title);

	if(title_len > 16){
		printf("파일명을 16자리 이하로 입력해주세요!!\n");
		exit(1);
	} else{
		padding_result = padding(title);
		printf("%s, %ld\n", title, title_len);
		printf("### Start Convertor\n");
		convertor(title, plain);
	}

	printf("Your title: %s\n", title);
	printf("\n");

	// Memory allocate for key space
	Round_key = malloc(192);
	key_init(16);
	
/*
	printf("Original Message: \n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("%02x ", plain[i][j]);
		}
		printf("\n");
	}
*/
	// Key Expansion
	printf("Key INFO:\n");
	key_expansion(key, Round_key);

	printf("----------------------------------\n  Converted Message(Convert Message):\n");
	for(i=0; i<4; i++){
		printf("%02x %02x %02x %02x ", plain[i][0], plain[i][1], plain[i][2], plain[i][3]);
	}
	printf("\n\n");

	aes_enc(plain, cipher, Round_key);	
	printf("----------------------------------\n  CipherText Message:\n");
	for(i=0; i<4; i++){
		printf("%02x %02x %02x %02x ", cipher[i][0], cipher[i][1], cipher[i][2], cipher[i][3]);
	}
	printf("\n\n");

	aes_dec(cipher, dec_test, Round_key);
	printf("----------------------------------\n  Original Message(After decrypt):\n");
	for(i=0; i<4; i++){
		printf("%02x %02x %02x %02x ", dec_test[i][0], dec_test[i][1], dec_test[i][2], dec_test[i][3]);
	}
	printf("\n\n");

	inv_convertor(dec_test, inv_title);
	printf("----------------------------------\n  Recover title(After inv_convert):\n%s\n", inv_title);
	printf("\n\n### End of test coden\n");
	free(Round_key);
	return 0;
}
