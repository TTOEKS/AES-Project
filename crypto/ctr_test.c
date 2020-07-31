#include "aes.h"
#include "../func/func.h"
#include<string.h>

void big_convert(char *string, uint8_t *out){
	int len = strlen(string);

	for(int i=0; i<len; i++){
		out[i] = string[i];
	}
}

void big_inv_convert(uint8_t *in, char *string){
	int len = strlen(in);

	for(int i=0; i<len; i++){
		string[i] = in[i];
	}
	string[len] = '\0';
}

// Encrypt CTR mod
uint8_t *enc_ctr(uint8_t (*iv)[4], char *msg, uint8_t *key){
	char *pad_res;
	uint8_t *ctr_res, *temp_uint8;
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
	temp_uint8 = (uint8_t *)malloc(sizeof(uint8_t) * 16 * (count_mod));
	pad_res = (char *)malloc(sizeof(char) * 16 * (count_mod));
	memset(pad_res, 0, sizeof(pad_res));
	
	printf("Init Matrix in enc_ctr\n");
	strncpy(pad_res, msg, s_len);
 	big_convert(pad_res, temp_uint8);
	
	// display Matrix
	for(int i=0; i<count_mod; i++){
		for(int j=0; j<16; j++){
			printf("%02x " ,temp_uint8[i*16+j]);
		}
		printf("\n");
	}


	// Compute Encrypt 
	for(int i=0; i<count_mod; i++){
		aes_enc(iv, cipher, key);

		// XOR Plain text(after Padding) and Encrypted IV
		for(int j=0; j<16; j++){
			ctr_res[16*i+j] = temp_uint8[16*i+j] ^ cipher[j/4][j%4];
		}

		// Increase Initial Value
		iv += 1;
	}
	
	return ctr_res;
}
 
// Dencrypt CTR mod
char *dec_ctr(uint8_t (*iv)[4], uint8_t *cipher, uint8_t *key){
	char *dec_res;
	uint8_t *temp_uint8;
	uint8_t temp_cipher[4][4];
	int count_mod, s_len;

	s_len = strlen(cipher);
	count_mod = s_len / 16;

	printf("Init Matrix in dec_ctr\n");
	dec_res = (char *)malloc(sizeof(char) * 16 * count_mod);
	temp_uint8 = (uint8_t *)malloc(sizeof(uint8_t) * 16 * count_mod);

	// display Matrix
	for(int i=0; i<count_mod; i++){
		for(int j=0; j<16; j++){
			printf("%02x ", cipher[i*16 + j]);
		}

		printf("\n");
	}
	printf("\n");


	// Compute Decrypt
	for(int i=0; i<count_mod; i++){
		aes_enc(iv, temp_cipher, key);

		// XOR Cipher Text and Encrypt IV
		for(int j=0; j<16; j++){
			temp_uint8[16*i+j] = cipher[16*i+j] ^ temp_cipher[j/4][j%4]; 
		}
		
		// Increase Initial Value
		iv += 1;
	}

	big_inv_convert(temp_uint8, dec_res);
	
	return dec_res;
}


int main()
{
	uint8_t iv[4][4] = {{0x00, 0x01, 0x02, 0x03}, {0x04, 0x05, 0x06, 0x07}, {0x08, 0x09, 0x0a, 0x0b},
		{0x0c, 0x0d, 0x0e, 0x0f}};
	int8_t key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2,
        0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
	uint8_t *Round_key;
	char *s = "Hello! My name is yujinho00. Nice to meet you. I want to be best programmer in the world!!\nalso best cyber security. I study hard these days. what are your want to be?";
	uint8_t *test;
	char *inv_s;

	Round_key = malloc(192);
	key_expansion(key, Round_key);
	test = enc_ctr(iv,  s,  Round_key);

	printf("\n\nAfter Encrypt %ld:\n", strlen(test));
	for(int i=0; i<strlen(test); i++){
		if(i%16 == 0 && i != 0)	printf("\n");
		printf("%02x ", test[i]);
	}
	printf("\n\n");	

	printf("--------------Start Decrypt test------------------\n");
	inv_s = dec_ctr(iv, test, Round_key);

	printf("\n\nAfter Decrypt %ld:\n", strlen(inv_s));
	for(int i=0; i<strlen(inv_s); i++){
		if(i%16 == 0 && i != 0)	printf("\n");
		printf("%02x ", inv_s[i]);
	}
	printf("\n\n");	
	printf("%s\n", inv_s); 
}
