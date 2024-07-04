# AES-Project  
Last update 2020.07.31   
This project is my personal project devised by graduation class word

Current project goal: AES encrypted communcation

originally, this project goal was make encrypted storage.
this project was stopped so long times ago. so, change the project goal from encrypted storage to encrypted socket communcation
I was started this project for implmented AES cryptography using C lang.
Altough project goal changed, my goal was not changed.

Encrypt type: AES (CTR mode)
Network way: TCP socket  
Rand function: rand of openssl  

### To-do List  

- [x] Make simple socket (test by chat)    
- [x] Connect Database and work test    
- [x] Make Convert Character to Hex   
- [x] Make AES module (Also Inverse Function)    
  - [x] Make Add Round Key
  - [x] Make Sub Byte
  - [x] Make Shift Rows
  - [x] Make Mix Columns
  - [x] Make Key Expansion    
  
- [x] Test AES module  
  - [x] Key Expansion  
  - [x] Sub Byte  
  - [x] Shift Rows  
  - [x] Mix Columns              <-  ~~find bug at this function~~  
  
- [x] Make CTR mode
  - [x] Encrypt function
  - [x] Decrypt function  
  
Don't confuse between int type and uint8_t type :(

## Function Test
### AES Cryptogarphy function test
#### AES encryption/decription 
![AES Cipher test](./rsrc/aes_cipher_test.png)
  - Original Message: Hello World!!

### AES Cryptography communication test
#### Plain text communication
![AES plain communcation](./rsrc/plain_socket_communication.png)
  - Communcation flow
    1. Client send: Hello World
    2. Server send: Hello World too.
  - You can see payload data

#### Encyprted test communcation
![AES cipher communcation](./rsrc/cipher_socket_communication.png)
  - Communcation flow
    1. Client send: Hello World
    2. Server send: Hello World too.
  - You can't see payload data (encrypted)
  - but, endpoint host can see payload data