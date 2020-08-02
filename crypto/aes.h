#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>


// Initalize Function
void key_init(int keysize);

// AES Ecnrypt Function
void aes_enc(uint8_t (*plain)[4], uint8_t (*cipher)[4], uint8_t *key);

// AES Decyprt Function
void aes_dec(uint8_t (*cipher)[4], uint8_t (*plain)[4], uint8_t *key);

// AES Key Scheduler
void key_expansion(uint8_t *key, uint8_t *Round_key);

// Display Matrix 
void display_matrix(uint8_t *a, int columns_size, int size);

// AES Encrypt function with CTR Mode
uint8_t *enc_ctr(uint8_t (*iv)[4], char *msg, uint8_t *key);

// AES Decrypt function with CTR Mode
char *dec_ctr(uint8_t (*iv)[4], uint8_t *cipher, uint8_t *key);

