# AES-Project  
Last update 2020.07.22   
This project is my graduation class work 

I want make encrypted storage that anyone who not access can't read even admin   
And i should consider how can i save encrypted file name and send search query (EDB Keyword Search)  

Way 1:   
Save encypted file name and request encypted search query 

Way 2:  
After mapping between encrypted file name and token. request token query 

Encrypt type: AES, CBC/CTR(if i can)  
Network way: TCP socket  
Database: Mysql   
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
  - [x] Mix Columns            <-  ~~find bug at this function~~  
  
- [ ] Make CTR mode
  -[ ] Encrypt function
  -[ ] Decrypt function  
  
- [ ] Make file save module  
- [ ] Make file query module  
- [ ] Make server  
- [ ] Make client  
- [ ] Separate modules  

Don't confuse between int type and uint8_t type :(
