#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>


// Initalize function
uint8_t *init(size_t key_size);

// AES Ecnryption Function
void aes_enc(uint8_t *plain, uint8_t *cipher, uint8_t *key);

// AES Decyprtion Function
void aes_desc(uint8_t *cipher, uint8_t *plain, uint8_t *key);

