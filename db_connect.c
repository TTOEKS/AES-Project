#include<stdio.h>
#include"mysql/mysql.h"
#include<stdlib.h>
#include<errno.h>



MYSQL 		*conn;
MYSQL_RES	*res;
MYSQL_ROW	row;

int db_init()
{
	conn = mysql_init(NULL);
	
	if(!conn){
		perror("Mysql init ERROR");
		exit(1);
	} else{
		printf("Mysql Initialize Success\n");
	}
	
	conn = mysql_real_connect(conn, "localhost", "root", "yu16969696yu!","mysql",0,NULL,0);
	if(conn){
		printf("Mysql Connect Success\n");
	}else{
		perror("Mysql Connect ERROR");
		exit(1);
	}

	return 0;

}


int main(int argc, char **argv)
{
	int temp = db_init();
	
	return 0;
}
