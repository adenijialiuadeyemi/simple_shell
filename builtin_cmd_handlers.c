#include "main.h"

/**
 * check_builtin - This func determines if the cmd is builtin
 * @cmd: cmd in question
 * Return: 0 when successful otherwise -1
 */

int check_builtin(char **cmd)
{
inbuilt func[] = {
{"cd", NULL},
{"help", NULL},
{"echo", NULL},
{"env", NULL},
{"history", NULL},
{NULL, NULL}
};
int c = 0;

if (*cmd == NULL)
{
return (-1);
}
while ((func + c)->command)
{
if (_strcmp(cmd[0], (func + c)->command) == 0)
	return (0);
c++;
}
return (-1);
}

/**
 * handle_builtin - The func caters for builtin func which are predefined
 * @cmd: Arr of cmds
 * @cond: cond of prev exec
 * Return: 0 when successful otherwise -1
 */

int handle_builtin(char **cmd, int cond)
{
inbuilt inbuilt[] = {
{"cd", change_dir},
{"env", dis_env},
{"help", display_help},
{"echo", echo_bul},
{"history", history_dis},
{NULL, NULL}};
int c = 0;

while ((inbuilt + c)->command)
{
if (_strcmp(cmd[0], (inbuilt + c)->command) == 0)
{
return ((inbuilt + c)->function(cmd, cond));
}
c++;
}
return (-1);
}

/**
 * exit_file_bool - Exit conditions for built-in commands
 * @cmd: Array of parsed command strings
 * @user_input: user_input
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @c: Shell execution count
 * @cond_exit: Exit conditions
 */

void exit_file_bool(char **cmd, char *user_input, char **argv, int c, int cond_exit)
{
int cond, i = 0;

if (cmd[1] == NULL)
{
free(user_input);
free(cmd);
exit(cond);
}
while (cmd[1][i])
{
if (_isalpha(cmd[1][i++]) != 0)
{
_prerror(argv, c, cmd);
free(user_input);
free(cmd);
exit(2);
}
else
{
cond = _atoi(cmd[1]);
if (cond == 2)
{
_prerror(argv, c, cmd);
free(user_input);
free(cmd);
exit(cond);
}
free(user_input);
free(cmd);
exit(cond);
}
}
}

