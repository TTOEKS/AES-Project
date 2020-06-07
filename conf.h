#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<sys/socket.h>
#include<arpa/inet.h>

const int MAX_LINE = 2048;
const int PORT = 6001;
const int BACKLOG = 10;
const int LISTENQ = 6500;
const int MAX_CONNECT = 20;

