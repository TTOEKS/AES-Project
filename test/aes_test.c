#include <stdio.h>
#include "aes.h"
#include "func.h"

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
	char buf[64], inv_buf[64];
	char *padding_result;
	int  i, j;
	size_t buf_len;

	
	// Start Main Code
  printf("Input content which length under 16: ");
  scanf("%[^\n]s", buf);
	buf_len = strlen(buf);

	if(buf_len > 16){
    printf("you must input contents under 16 length: ");
		exit(1);
	} else{
		padding_result = padding(buf);
		printf("%s, %ld\n", buf, buf_len);
		printf("### Start Convertor\n");
		convertor(buf, plain);
	}

	printf("Your input: %s\n", buf);
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

  printf("plain text: %s\n", buf);
	printf("----------------------------------\nConverted Message(Convert Message):\n");
  display_uint8_double_array(plain, 4, 4);
	printf("\n\n");

	aes_enc(plain, cipher, Round_key);	
	printf("----------------------------------\nCipherText Message:\n");
  display_uint8_double_array(cipher, 4, 4);
	printf("\n\n");

	aes_dec(cipher, dec_test, Round_key);
	printf("----------------------------------\nOriginal Message(After decrypt):\n");
  display_uint8_double_array(dec_test, 4, 4);
	printf("\n\n");

	inv_convertor(dec_test, inv_buf);
	printf("----------------------------------\nRecover input(After inv_convert):\n%s\n", inv_buf);
	printf("\n\n### End of test\n");
	free(Round_key);
	return 0;
}
