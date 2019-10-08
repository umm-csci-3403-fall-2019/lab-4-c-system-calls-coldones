#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "disemvowel.h"

#define BUF_SIZE 1024


bool hasVowel(char vowel){
        return (vowel == 'a' || vowel == 'e' || vowel == 'i' || vowel == 'o' || vowel == 'u' ||
                vowel == 'A' || vowel == 'E' || vowel == 'I' || vowel == 'O' || vowel == 'U');

}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf){
	int counter = 0;

	for(int i = 0; i < num_chars; i++){
		if(!hasVowel(in_buf[i])){
			out_buf[counter] = in_buf[i];
			counter++;
		}
	}

	return counter;
}

void disemvowel(FILE* inputFile, FILE* outputFile){
	char* in_buffer = (char*) calloc(BUF_SIZE,sizeof(char));
	char* out_buffer = (char*) calloc(BUF_SIZE,sizeof(char));

	int elements_read = fread(in_buffer,sizeof(char),BUF_SIZE,inputFile);

	int non_vowels = copy_non_vowels(elements_read,in_buffer,out_buffer);
	fwrite(out_buffer,sizeof(char),non_vowels,outputFile);
}


int main(int argc, char *argv[]) {

	FILE *inputFile;
	FILE *outputFile;

	if(argc == 1){
		inputFile = stdin;
		outputFile = stdout;
	} else if(argc == 2){
		inputFile = fopen(argv[1],"r");
		outputFile = stdout;
	} else if(argc == 3){
		inputFile = fopen(argv[1],"r");
		outputFile = fopen(argv[2],"w");
	} else {
		printf("You get nothing! You lose! Good day, sir!");
	}

	disemvowel(inputFile,outputFile);
	
	fclose(inputFile);
	fclose(outputFile);

  return 0;
}
