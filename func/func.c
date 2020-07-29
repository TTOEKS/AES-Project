#include "func.h"

// if string size lower than 16, it is filled 0
char *padding(char *string){
	size_t len = strlen(string);
	char *temp;

	int padding_count = len % 16;
	if(padding_count != 0){
		printf("### Start padding\n");
		temp = (char *)malloc(16 * sizeof(char));
		strncpy(temp, string, len);
		for(int i=len; i<16; i++){
			temp[i] = '0';
		}
		temp[16] = '\0';
	}
	printf("%s\n", temp);
	return temp;
}

// Convert string to number
void convertor(char *string, uint8_t (*out)[4]){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			out[i][j] = string[4 * i + j] - 48;
		}
	}
}

// Convert number to string
void inv_convertor(uint8_t (*in)[4], char *string){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			string[4 * i + j] = in[i][j] + 48;
		}		
	}
	
	// End of String
	string[16] = '\0';
	
}
/*

int main()
{
	char title[64];
	uint8_t out[4][4];
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

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			printf("%02x ", out[i][j]);
		}
	}
	printf("\n");
	
	inv_convertor(out, inv_title);
	printf("%s\n",inv_title); 


}
*/
