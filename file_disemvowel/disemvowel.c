#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "disemvowel.h"

#define BUF_SIZE 1024


bool hasVowel(char vowel){
        return (vowel == 'a' || vowel == 'e' || vowel == 'i' || vowel == 'o' || vowel == 'u' ||
                vowel == 'A' || vowel == 'E' || vowel == 'I' || vowel == 'O' || vowel == 'U');

}


char *disemvowel(char *str) {
	char *newStr;
	int index = 0;
	int counter = 0;

	while(str[index] != '\0'){
		if(!hasVowel(str[index])){
			counter++;
		}
		index++;
	}

	newStr = (char*) calloc (counter + 1, sizeof(char));

	for(int i=0,n=0;i<index;i++){
		if(!hasVowel(str[i])){
			newStr[n] = str[i];
			n++;
		}
	}

	newStr[counter] = '\0';

	return (char*) newStr;
}


int main(int argc, char *argv[]) {
  //FILE *inputFile;
  //FILE *outputFile;

  //disemvowel(inputFile,outputFile);

  return 0;
}
