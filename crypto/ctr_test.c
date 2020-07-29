#include "aes.h"
#include "../func/func.h"
#include<string.h>

/*
	aes_enc(plain, cipher, Round_key);
	aes_dec(cipher, dec_test, Round_key);
*/
uint8_t *enc_ctr(uint8_t (*iv)[4], char *msg, uint8_t *key){
	char *pad_res;
	uint8_t *ctr_res;
	uint8_t cipher[4][4], temp[16] = { 0,};
	int count_mod, s_len;

	s_len = strlen(msg);
	count_mod = s_len / 16;
	
	// If msg byte is not divisiable 16
	if(s_len % 16 != 0){
		count_mod  += 1;
	}
	printf("%d: %s\n",s_len, msg);
	

	// Initialize Memory locale
	ctr_res = (uint8_t *)malloc(sizeof(uint8_t) * 16 * (count_mod));
	pad_res = (char *)malloc(sizeof(char) * 16 * (count_mod));
	memset(pad_res, 0, sizeof(pad_res));
	
	printf("Init Matrix in enc_ctr\n");
	strncpy(pad_res, msg, s_len);
	for(int i=0; i<count_mod; i++){
		for(int j=0; j<16; j++){
			printf("%02x " ,pad_res[i*16+j]);
		}
		printf("\n");
	}


	for(int i=0; i<count_mod; i++){
		aes_enc(iv, cipher, key);

		for(int j=0; j<16; j++){
			ctr_res[16*i+j] = msg[16*i+j] ^ cipher[j/4][j%4];
		}
		for(int j=0; j<16; j++){
			iv[j/4][j%4] += 1;
		}
	}
	


	return ctr_res;
}

void dec_ctr(uint8_t iv, uint8_t (*cipher)[4], uint8_t (*plain)[4], uint8_t *key){

}

void big_convert(char *string, uint8_t *out){
	int len = strlen(string);
	
	for(int i=0; i<len; i++){
		out[i] = string[i] - 48;
	}
}

void big_inv_convert(uint8_t *in, char *string){
	int len = strlen(in);

	for(int i=0; i<len; i++){
		string[i] = in[i] + 48;
	}
	string[len] = '\0';
}

int main()
{
	uint8_t iv[4][4] = {{0x00, 0x01, 0x02, 0x03}, {0x04, 0x05, 0x06, 0x07}, {0x08, 0x09, 0x0a, 0x0b},
		{0x0c, 0x0d, 0x0e, 0x0f}};
	int8_t key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2,
        0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
	uint8_t *Round_key;
	char *s = "Hello! My name is yujinho. Nice to meet you. I want to be best programmer in the world!!\nalso best cyber security. I study hard these days. what are your want to be?";
	uint8_t *test;

	Round_key = malloc(192);
	key_expansion(key, Round_key);
	test = enc_ctr(iv,  s,  Round_key);

	printf("\n\nAfter Encrypt %ld:\n", strlen(test));
	for(int i=0; i<strlen(test); i++){
		if(i%16 == 0 && i != 0)	printf("\n");
		printf("%02x ", test[i]);
	}
	printf("\n\n");	
}
