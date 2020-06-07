# AES-Project
This project is my graduation class work

I want make encrypted storage that anyone who not access can't read even admin 
and I should consider how can i save encrypted file name and send search query (EDB Keyword Search)

Way 1: 
Save encypted file name and request encypted search query 

Way 2:
Mapping between encrypted file name and token. and request token query 

Encrypt type: AES, CBC/CTR(if i can)
Network way: TCP socket
Database: Mysql 
Rand function: rand of openssl

### To-do List  

-[x]Make simple socket (test by chat)  
-[ ]Connect Database and work test  
-[ ]Make AES module  
-[ ]Make file save module  
-[ ]Make file query module  
-[ ]Make server  
-[ ]Make client  
-[ ]Separate modules  

Update 2020.06.07
