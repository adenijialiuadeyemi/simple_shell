#include "main.h"

/**
 * separator - The func sep cmds by semicolon(;)
 * @user_input: User input
 * Return: useful strngs to be used as cmd
 */

char **separator(char *user_input)
{
char **cmds;
char *cmd;
int i;
int bufer_size = BUFSIZE;

if (user_input[0] == ' ' && user_input[_strlen(user_input)] == ' ')
	exit(0);
if (user_input == NULL)
	return (NULL);
cmds = malloc(sizeof(char *) * bufer_size);
if (!cmds)
{
free(cmds);
perror("hsh");
return (NULL);
}
cmd = _strtok(user_input, ";&");
for (i = 0; cmd; i++)
{
cmds[i] = cmd;
cmd = _strtok(NULL, ";&");
}
cmds[i] = NULL;

return (cmds);
}

