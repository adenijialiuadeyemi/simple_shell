#include "main.h"
/**
 * _getline - This takes whatever the user entered
 * Return: the user input in a bufer
 */
char *_getline()
{
int i, res_read, bufer_size = BUFSIZE;
char ch = 0, *bufer, *buf;

bufer = malloc(bufer_size);
if (bufer == NULL)
{
free(bufer);
return (NULL);
}
for (i = 0; ch != EOF && ch != '\n'; i++)
{
fflush(stdin);
res_read = read(STDIN_FILENO, &ch, 1);
if (res_read == 0)
{
free(bufer);
exit(EXIT_SUCCESS);
}
bufer[i] = ch;
if (bufer[0] == '\n')
	return (enter(bufer));
if (i >= bufer_size)
{
bufer = realloc(bufer, (bufer_size + 2));
if (bufer == NULL)
{
free(bufer);
return (NULL);
}
}
}
bufer[i] = '\0';
buf = space(bufer);
free(bufer);
hashtag_treated(buf);
return (buf);
}
/**
 * enter - This caters for NewLine
 * @strng: Strng in question
 * Return: clear strng
 */
char *enter(char *strng)
{
free(strng);
return ("\0");
}

/**
 * space - This clears spaces before the actual strngs
 * @strng: strng in question
 * Return: Modified strng
 */
char *space(char *strng)
{
int i, j = 0;
char *bufer;

bufer = malloc(sizeof(char) * (_strlen(strng) + 1));
if (bufer == NULL)
{
free(bufer);
return (NULL);
}
for (i = 0; strng[i] == ' '; i++);
	for (; strng[i + 1] != '\0'; i++)
{
bufer[j] = strng[i];
j++;
}
bufer[j] = '\0';
if (bufer[0] == '\0' || bufer[0] == '#')
{
free(bufer);
return ("\0");
}
return (bufer);
}
/**
 * hashtag_treated - This clears all chars before the '#' tag
 * @bufer: bufer input
 * Return: void
 */
void hashtag_treated(char *bufer)
{
int c;

for (c = 0; bufer[c] != '\0'; c++)
{
if (bufer[c] == '#' && bufer[c - 1] == ' ' && bufer[c + 1] == ' ')
{
bufer[c] = '\0';
}
}
}

