/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

//function declarations
char* get_word(char *input, int start, int end);
int compare_string(char str1[], char str2[]);

char ** commonWords(char *str1, char *str2) {
	

	//returns NULL if either of the strings are NULL
	if (str1 ==0 || str2 == 0)
		return 0;  
	//variables declaration
	int len1;
	int len2;
	int size1 = 0;
	int size2 = 0;
	int t1 = 0, t2 = 0;
	int temp = 0;
	int resIndex = 0;
	
	char **res = (char **)malloc(10 * sizeof(char *));   //storing result 
	char **temp1 = (char **)malloc(10 * sizeof(char *)); //storing all words of str1
	char **temp2 = (char **)malloc(10 * sizeof(char *)); //storing all words of str2
	char *tempWord = (char *)malloc(10 * sizeof(char *));

	//finding lengths of str1 and str2
	for (len1 = 0; str1[len1] != 0; len1++);
	for (len2 = 0; str2[len2] != 0; len2++);

	//for words in string 1
	for (int i = 0; i <= len1; i++)
	{
		if (str1[i] == ' ' || str1[i] == '\0'){
			temp1[t1++] = get_word(str1, temp, i);
			temp = i + 1;
		}
	}
	temp = 0;

	//for words in string 2
	for (int i = 0; i <= len2; i++)
	{
		if (str2[i] == ' ' || str2[i] == '\0'){
			temp2[t2++] = get_word(str2, temp, i);
			temp = i + 1;
		}
	}

	//comparing both the strings
	for (int i = 0; i < t1; i++)
	{
		for (int j = 0; j < t2; j++)
		{
			tempWord = temp1[i];
			int flag = compare_string(temp1[i], temp2[j]);
			if (flag)
				res[resIndex++] = tempWord;
		
		}
	}

	if (resIndex == 0)
		return NULL;

	return res;
}

char* get_word(char *input, int start, int end)
{

	int i, j = 0;
	char *temp = (char *)malloc(3 * sizeof(char *));
	for (i = start;i < end; i++) {
		
		temp[j++] = input[i];
		
	}
	temp[j] = '\0';
	
	
	return temp;
}

int compare_string(char str1[], char str2[]){
	int i = 0, flag = 0;

	if (str1[i] == '\0' && str2[i] == '\0')
		return 0;
	while (str1[i] != '\0' && str2[i] != '\0'){
		if (str1[i] != str2[i] ){
			flag = 1;
			break;
		}
		i++;
	}

	if (flag == 0 && str1[i] == '\0' && str2[i] == '\0')
		return 1;
	else
		return 0;

}