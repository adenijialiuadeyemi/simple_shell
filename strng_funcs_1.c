#include "main.h"
/**
 * _putchar - This function output the char in std output
 * @ch: The printed char
 * Return: char to std_output
 */
int _putchar(char ch)
{
return (write(1, &ch, 1));
}
/**
 * _puts - function that prints a string
 * @strng: pointer to string
 * Return: void
 */
void _puts(char *strng)
{
int count_i;

for (count_i = 0; strng[count_i] != '\0'; count_i++)
{
_putchar(strng[count_i]);
}
_putchar('\n');
}
/**
 * _strncpy - The func moves a strng from sorce to destin
 * @destin: The destin strng
 * @sorce: The sorce strng
 * @count_n: count of chars to be moved
 * Return: strngs moved
 */
char *_strncpy(char *destin, char *sorce, int count_n)
{
int count_i = 0;

while (count_i < count_n && *(sorce + count_i))
{
*(destin + count_i) = *(sorce + count_i);
count_i++;
}
while (count_i < count_n)
{
*(destin + count_i) = '\0';
count_i++;
}
return (destin);
}
/**
 * _strlen - function that counts the length of a string
 * @strng: string input
 * Return: length of string
 */
int _strlen(char *strng)
{
int count_i;

for (count_i = 0; strng[count_i] != '\0'; count_i++)
{
continue;
}
return (count_i);
}
/**
 * _atoi - Func to transform a word to a number
 * @strng: input strng
 * Return: int converted
 */
int _atoi(char *strng)
{
int m = 0, n = 1, p;
unsigned int l = 0;

while (strng[m] != '\0')
{
if (strng[m] == '-')
{
return (2);
}
p = strng[m] - '0';

if (l > 0 && !(p >= 0 && p <= 9))
	break;
if (p >= 0 && p <= 9)
	l = l * 10 + p;
m++;
}
l *= n;
return (l);
}

