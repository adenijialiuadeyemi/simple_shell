#include "main.h"
/**
 * _strcmp - The function compares two strngs
 * @strng1: Strng one
 * @strng2: Strng two
 * Return: 0 when they are the same
 */
int _strcmp(char *strng1, char *strng2)
{
int compre = 0, count_i, len1, len2;

len1 = _strlen(strng1);
len2 = _strlen(strng2);

if (strng1 == NULL || strng2 == NULL)
	return (1);

if (len1 != len2)
	return (1);

for (count_i = 0; strng1[count_i]; count_i++)
{
if (strng1[count_i] != strng2[count_i])
{
compre = strng1[count_i] - strng2[count_i];
break;
}
else
	continue;
}
return (compre);
}
/**
 * _isalpha - This func checks if ch is a char
 * @ch: checked char
 * Return: 1 when it is true otherwise return 0
 */
int _isalpha(int ch)
{
if (((ch >= 97) && (ch <= 122)) || ((ch >= 65) && (ch <= 90)))
{
return (1);
}
else
{
return (0);
}
}
/**
 * _itoa - This function converts integer to alphabet
 * @num: converted integer
 * Return: pointer char
 */
char *_itoa(unsigned int num)
{
int len = 0, count_i = 0;
char *strng;

len = intlen(num);
strng = malloc(len + 2);

if (!strng)
{
free(strng);
return (NULL);
}
*strng = '\0';

while (num / 10)
{
strng[count_i] = (num % 10) + '0';
num /= 10;
count_i++;
}

strng[count_i] = (num % 10) + '0';
array_rev(strng, len);
strng[count_i + 1] = '\0';

return (strng);
}
/**
 * array_rev - These function reverses an array
 * @arr: reversed arr
 * @len: array length
 */
void array_rev(char *arr, int len)
{
int count_i;
char temp;

for (count_i = 0; count_i < (len / 2); count_i++)
{
temp = arr[count_i];
arr[count_i] = arr[(len - 1) - count_i];
arr[(len - 1) - count_i] = temp;
}
}
/**
 * intlen - This function determines the length of int
 * @num: integer in question
 * Return: integer length
 */
int intlen(int num)
{
int len = 0;

while (num != 0)
{
len++;
num /= 10;
}
return (len);
}

