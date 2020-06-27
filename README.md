# AES-Project  
Last update 2020.06.21   
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
- [ ] Make Convert Character to Binary 
- [ ] Make AES module (Also Inverse Function)
  - [x] Make Add Round Key
  - [x] Make Sub Byte
  - [x] Make Shift Rows
  - [ ] Make Mix Columns
  - [ ] Make Key Expansion  
- [ ] Test AES module
- [ ] Make CTR mode
- [ ] Make file save module  
- [ ] Make file query module  
- [ ] Make server  
- [ ] Make client  
- [ ] Separate modules  


