#include "main.h"
/**
 * _strcpy - Function to move a strng from sorce to destin
 * @destin: strng in destin
 * @sorce: strng in sorce
 * Return: strng moved to destination
 */
char *_strcpy(char *destin, char *sorce)
{
int count_i = 0;

while (sorce[count_i])
{
destin[count_i] = sorce[count_i];
count_i++;
}
destin[count_i] = '\0';
return (destin);
}
/**
 * _strcat - The func joins two strngs together
 * @destin: Destination strng
 * @sorce: sorce string
 * Return: joined string of the sorce to the destin
 */
char *_strcat(char *destin, char *sorce)
{
char *st = destin;

while (*destin != '\0')
{
destin++;
}

while (*sorce != '\0')
{
*destin = *sorce;
destin++;
sorce++;
}
*destin = '\0';
return (st);
}
/**
 * _strchr - The func search for char in a word/strng
 * @strng: searched word
 * @ch: located char
 * Return: char pointer
 */
char *_strchr(char *strng, char ch)
{
do
{
if (*strng == ch)
{
break;
}
}
while (*strng++);
	return (strng);
}
/**
 * _strncmp - The function comares n chars from the 2 strngs
 * @strng1: strng one
 * @strng2: strng two
 * @c: amount of characters to compare
 * Return: 1 if the strings don't match otherwise 0
 */
int _strncmp(const char *strng1, const char *strng2, size_t c)
{
size_t count_i;

if (strng1 == NULL)
	return (-1);

for (count_i = 0; count_i < c && strng2[count_i]; count_i++)
{
if (strng1[count_i] != strng2[count_i])
{
return (1);
}
}
return (0);
}
/**
 * _strdup - The function duplicate strngs
 * @strng: strng to be duplicated
 * Return: NULL if failed, otherwise duplicated strng
 */
char *_strdup(char *strng)
{
size_t len, count_i;
char *strng2;

len = _strlen(strng);
strng2 = malloc(sizeof(char) * (len + 1));
if (!strng2)
{
return (NULL);
}
for (count_i = 0; count_i <= len; count_i++)
{
strng2[count_i] = strng[count_i];
}
return (strng2);
}

