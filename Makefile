CC=gcc -Wall 
INCLUDE=-I./include 
LIBS=
DEFS=
BUILD_DIR=lib bin

ALL: client client_plain server server_plain test

client: lib/aes.o lib/func.o client.c
	${CC} ./client.c -g -o ./bin/client lib/aes.o lib/func.o ${INCLUDE} ${LIBS} ${DEFS}

client_plain: lib/func.o client.c
	${CC} ./client_plain.c -g -o ./bin/client_plain lib/aes.o lib/func.o ${INCLUDE} ${LIBS} ${DEFS}

server: lib/aes.o lib/func.o server.c
	${CC} ./server.c -g -o ./bin/server lib/aes.o lib/func.o ${INCLUDE} ${LIBS} ${DEFS}
 
server_plain: lib/func.o server.c
	${CC} ./server_plain.c -g -o ./bin/server_plain lib/aes.o lib/func.o ${INCLUDE} ${LIBS} ${DEFS}
  
test: lib/aes.o lib/func.o
	${CC} ./test/aes_test.c -g -o ./test/aes_test lib/aes.o lib/func.o ${INCLUDE} ${LIBS} ${DEFS}
# ${CC} ./test/db_connect.c -g -o ./test/db_connect lib/aes.o lib/func.o ${INCLUDE} ${LIBS} ${DEFS}

lib/aes.o: ./src/aes.c $(BUILD_DIR)
	${CC} ./src/aes.c -c -o lib/aes.o ${INCLUDE} ${LIBS} ${DEFS}

lib/func.o: ./src/func.c $(BUILD_DIR)
	${CC} ./src/func.c -c -o lib/func.o ${INCLUDE} ${LIBS} ${DEFS}


$(BUILD_DIR): 
	mkdir $(BUILD_DIR)

clean:
	rm -rf ${BUILD_DIR} test/aes_test
