#include "main.h"
/**
 * check_delim - This func checks if a char is the same with another
 * @ch: char in question
 * @strng: delimeter strng
 * Return: 0 when failed otherwise return 1
 */
unsigned int check_delim(char ch, const char *strng)
{
unsigned int count;

for (count = 0; strng[count] != '\0'; count++)
{
if (ch == strng[count])
	return (1);
}
return (0);
}
/**
 * _strtok - function that extracts tokens of a string
 * @strng: Strng in question
 * @delim: Strng_Delimeter
 * Return: Null or next_token pointer
 */
char *_strtok(char *strng, const char *delim)
{
static char *toks;
static char *tok_new;
unsigned int count;

if (strng != NULL)
	tok_new = strng;
toks = tok_new;
if (toks == NULL)
	return (NULL);
for (count = 0; toks[count] != '\0'; count++)
{
if (check_delim(toks[count], delim) == 0)
	break;
}
if (tok_new[count] == '\0' || tok_new[count] == '#')
{
tok_new = NULL;
return (NULL);
}
toks = tok_new + count;
tok_new = toks;
for (count = 0; tok_new[count] != '\0'; count++)
{
if (check_delim(tok_new[count], delim) == 1)
	break;
}
if (tok_new[count] == '\0')
	tok_new = NULL;
else
{
tok_new[count] = '\0';
tok_new = tok_new + count + 1;
if (*tok_new == '\0')
	tok_new = NULL;
}
return (toks);
}

