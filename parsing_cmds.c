#include "main.h"

/**
 * parse_cmd - This function resolves strngs receieved from stdin
 * @user_input: user_input
 * Return: Resoved strngs to be used as args
 */

char **parse_cmd(char *user_input)
{
char **args;
char *arg;
int c;
int bufersize = BUFSIZE;

if (user_input[0] == ' ' && user_input[_strlen(user_input)] == ' ')
	exit(0);
if (user_input == NULL)
	return (NULL);
args = malloc(sizeof(char *) * bufersize);
if (!args)
{
free(args);
perror("hsh");
return (NULL);
}
arg = _strtok(user_input, "\n\t\r\a ");
for (c = 0; arg; c++)
{
args[c] = arg;
arg = _strtok(NULL, "\n\t\r\a ");
}
args[c] = NULL;

return (args);
}

