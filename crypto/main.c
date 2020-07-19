#include<stdio.h>
#include"aes.h"


// void display_matrix(int *a, int columns_size, int size);

int main(){
	int i, j;

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

	Round_key = malloc(192);

	key_init(16);
	printf("Original Message: \n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("%02x ", plain[i][j]);
		}
		printf("\n");
	}

	printf("\n-----------------------\n  Functions Test\n-----------------------\n\n");
	key_expansion(key, Round_key);
	printf("### Key Expansion TEST\n");


	printf("----------------------------------\n  PlainText Message:\n");
	for(i=0; i<4; i++){
		printf("%02x %02x %02x %02x ", plain[i][0], plain[i][1], plain[i][2], plain[i][3]);
	}
	printf("\n");

	aes_enc(plain, cipher, Round_key);	
	printf("----------------------------------\n  CipherText Message:\n");
	for(i=0; i<4; i++){
		printf("%02x %02x %02x %02x ", cipher[i][0], cipher[i][1], cipher[i][2], cipher[i][3]);
	}
	printf("\n");

	aes_dec(cipher, dec_test, Round_key);
	printf("----------------------------------\n  Original Message(After decrypt):\n");
	for(i=0; i<4; i++){
		printf("%02x %02x %02x %02x ", dec_test[i][0], dec_test[i][1], dec_test[i][2], dec_test[i][3]);
	}
	printf("\n");

	free(Round_key);
	return 0;
}
/*
void display_matrix(int *a, int columns_size, int size){

    int index = 0;


    printf("   ");
    for(int i=0; i<columns_size; i++){
        printf("%2d ", i);
    }

    printf("\n%2d ", index++);
    for(int i=0; i<size; i++){
        if(i%columns_size == 0 && i != 0){
            printf("\n%2d ", index++);
        }
        printf("%2x ", a[i]);

    }
    printf("\n ------------------end\n\n");
}
*/
