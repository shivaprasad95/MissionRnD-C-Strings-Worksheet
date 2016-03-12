/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {

	int length;
	int i,j=0;

	if (str == 0)
	return '\0';

	for (length = 0; str[length] != 0; length++);

	for (i = 0; i < length; i++)
	{
		if (str[i] == ' ')
			continue;
		str[j++] = str[i];
	}
	str[j] = '\0';

}