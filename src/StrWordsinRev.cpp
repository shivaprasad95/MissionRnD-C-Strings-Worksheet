/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void rev_string(char *input, int start,int end,int len);

void str_words_in_rev(char *input, int len){


	int i,j=0;
	int temp = 0;
	

	rev_string(input,0,len,len);
	
	for (i = 0; i <= len; i++)
	{
		if (input[i] == ' ' || input[i] == '\0'){
			rev_string(input, temp, i, len);
			temp = i+1;
		}
	}

}

void rev_string(char *input, int start, int end, int len)
{
	int i, j = 0;
	char temp;

	for (i = start, j = end - 1; i < j; i++, j--) {
		temp = input[i];
		input[i] = input[j];
		input[j] = temp;

	}
	input[len] = '\0';
	
}