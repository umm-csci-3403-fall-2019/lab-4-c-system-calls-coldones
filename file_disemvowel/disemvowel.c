#include <stdlib.h>

#include "disemvowel.h"

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


bool hasVowel(char vowel){
	return (vowel == 'a' || vowel == 'e' || vowel == 'i' || vowel == 'o' || vowel == 'u' ||
	        vowel == 'A' || vowel == 'E' || vowel == 'I' || vowel == 'O' || vowel == 'U');

}
