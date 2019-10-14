#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool ischar(char letter){
	if(letter =='A' || letter =='C' || letter =='G' ||  letter == 'T' ){
		return true;
	}
	else{
		return false;
	}
}
bool isdigitnum(char d){
	if(d>='1' && d<='9'){
		return true;
	}
	else{
		return false;
	}
}

void encode(char* content){
	int length = strlen(content);
	char result[100];
	char curr = content[0];
	char amount[20];
	char letter[10];
	int counter =1;
	
	
	for(int i=1;i<length; i++){
		if(content[i] == curr){
			counter++;
		}
		else{
			sprintf(amount, "%d", counter);
			letter[0] = curr;
			letter[1]='\0';
			amount[1]='\0';
			strcat(result, letter);
			strcat(result, amount);
			curr = content[i];
			counter =1;

		}

	}
	sprintf(amount, "%d", counter);
	letter[0] = curr;
	letter[1]='\0';
	amount[1]='\0';
	strcat(result, letter);
	strcat(result, amount);

	result[strlen(result)]='\0';
	printf("%s\n", result);

}


void decode(char* content){
	char result[100];
	int j=0;
	for(int i=0;i< strlen(content);i+=2){
		char l = content[i];
		int number = content[i+1]-'0';
		for(int m =0;m<number;m++){
			
			result[j] = l;
			j++;
		}
	}
	result[j] ='\0';
	printf("%s\n",result );

}


int main(int argc, char *argv[]){

	char *filename = NULL;
	char *mode = NULL;
	if(argc!=3){
		printf("Invalid Usage, expected: RLE {filename} [e | d]\n");
		exit(4);
	}

	filename = argv[1];
	mode = argv[2];

	if(*mode !='e' && *mode != 'd'){
		printf("Invalid Usage, expected: RLE {filename} [e | d]\n");
		exit(4);
	}

	if(filename == NULL){
		printf("Error: No input file specified!\n");
		exit(1);
	}

	FILE* file = fopen(filename, "r");
	if(file ==NULL)
	{
		printf("Read error: file not found or cannot be read\n" );
		exit(2);
	}
	char *line =NULL;
	size_t len = 0;
	getline(&line, &len, file);
	fclose(file);
	if(len >=0){

	}
	else{
		printf("Read error: file not found or cannot be read\n" );
		exit(2);
	}


	int length =strlen(line);
	while(1){
		if(line[length-1] !=' '&& line[length-1] !='\n'){
			break;
		}else{
			line[length-1] ='\0';
			length = strlen(line);
		}

	}

	if(*mode =='e'){
		encode(line);
	}else{
		decode(line);
	}



}