#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define ROUND_KEY_LENGTH    192
#define NUM_KEY_INIT        16

const int MAX_LINE = 2048;
const int PORT = 6001;
const int BACKLOG = 10;
const int LISTENQ = 6500;
const int MAX_CONNECT = 20;


// This is temperary key string (implmeneted key exchagne later I think?)
const uint8_t key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2,
		0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};

