#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>


// Initalize Function
void key_init(int keysize);

// AES Ecnryption Function
void aes_enc(uint8_t (*plain)[4], uint8_t (*cipher)[4], uint8_t *key);

// AES Decyprtion Function
void aes_dec(uint8_t (*cipher)[4], uint8_t (*plain)[4], uint8_t *key);

// AES Key Scheduler
void key_expansion(uint8_t *key, uint8_t *Round_key);

void display_matrix(uint8_t *a, int columns_size, int size);



