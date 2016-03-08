/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>



void number_to_str(float number, char *str, int afterdecimal){

	int i = 0, j = 0, k;
	int arr[7];
	int temp = 1;
	int length = 0;
	int negFlag = 0;
	int flag = 0;

	int num1, num2;

	//for getting 10^n as I cannot use math.h
	for (k = 0; k< afterdecimal; k++)
		temp = temp * 10;

	num1 = number * temp;
	num2 = (int)num1;


	if (num2 < 0)
	{
		num2 = -(num2);
		negFlag = 1;
	}

	while (num2)
	{
		arr[length++] = num2 % 10;
		num2 = num2 / 10;
	}

	i = length - 1;

	for (j = 0; j < length + 1;) {

		if (j == 0 && negFlag == 1)
			str[j++] = '-';
		if (negFlag != 1 && j == length - afterdecimal)
		{
			str[j++] = '.';
		}
		if (negFlag == 1 && j == length - afterdecimal + 1)
		{
			str[j++] = '.';
			length++;
		}
		str[j++] = (char)arr[i--] + '0';
	}


	str[length + 1] = '\0';

}
