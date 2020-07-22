#include "func.h"

// if string size lower than 16, it is filled 0
void padding(char *string, int size){
	printf("### Start padding\n");
	for(int i=size; i<16; i++){
		string[i] = '0';
	}
}

// Convert string to number
void convertor(char *string, uint8_t *out){
	for(int i=0; i<16; i++){
		out[i] = string[i] - 48;
	}
}

// Convert number to string
void inv_convertor(uint8_t *in, char *string){
	for(int i=0; i<16; i++){
		string[i] = in[i] + 48;
	}
	
	// End of String
	string[16] = '\0';
	
}

/*
int main()
{
	char title[64];
	uint8_t out[64];
	char inv_title[64];
	int title_len;

	printf("파일명을 16자리 이하로  입력해주세요:");
	scanf("%s", title);
	title_len = strlen(title);

	if(title_len > 16){
		printf("파일 명을 16자 이하로 입력해주세요!!\n");	
		exit(1);
	} else{
		
		padding(title, title_len);
		printf("%s, %d \n", title, title_len);
		printf("### Start Convertor\n");
		convertor(title, out);
	}

	for(int i=0; i<16; i++){
		printf("%02x ", out[i]);
	}
	printf("\n");
	
	inv_convertor(out, inv_title);
	printf("%s\n",inv_title); 


}
*/
