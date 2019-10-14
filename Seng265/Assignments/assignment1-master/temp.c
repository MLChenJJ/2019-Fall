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





void encode(char* line){
	int length = strlen(line);
	// printf("%d\n", length);
	char curr = line[0];
	char prev = curr;
	int counter = 1;

	char result[100];
	char number[10];
	int index =0;


	if(length>=2){
		for(int i=1;i<length;i++){
		    prev = curr;
			curr = line[i];
			if(prev==curr){
				counter++;
			}
			else{
				result[index] = prev;
				index++;
				result[index]=counter+'0';
				index++;
				counter=1;
			}
		}
		result[index] = prev;
		index++;
		result[index]=counter+'0';
		index++;
		result[index] ='\0';

	}
	else{
		sprintf(number, "%d", counter);
		result[0] = prev;
		result[1] = number[0];
		result[2] ='\0';

	}
	printf("%s\n",result );
	
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

	if(argc <=2 ||  argc >=4){
		printf("Invalid Usage, expected: RLE {filename} [e | d]\n");
		exit(0);
	}

	filename = argv[1];
	mode = argv[2];

	if(filename == NULL){
		printf("Error: No input file specified!\n");
		exit(1);
	}

	FILE* stream = fopen(filename, "r");
	if(stream ==NULL)
	{
		printf("Read error: file not found or cannot be read\n" );
		exit(2);
	}
	char *line =NULL;
	size_t len = 0;
	getline(&line, &len, stream);
	fclose(stream);


	int length = strlen(line);
	//remove '\n' or space at the tail
	while(1){
		if(line[length-1] =='\n' || line[length-1] == ' ')
		{
			line[length-1] ='\0';
			length = strlen(line);
		}
		else{
			break;
		}
	}

	if(!ischar(line[0])){
		printf("Error: Invalid format\n");
		exit(3);
	}
	if(length>=2){
		for(int i=1; i<length;i++){
			if(ischar(line[i]) || isdigitnum(line[i]))
			{
				}
			else
			{
				printf("Error: Invalid format\n");
				exit(3);
				}
		}

	}

	if(*mode == 'e'){
		encode(line);
	}
	else if(*mode =='d'){
		decode(line);
	}
	else{
		printf("Invalid Usage, expected: RLE {filename} [e | d]\n");
		exit(0);
	}









	
}