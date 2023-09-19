#include "main.h"
/**
 * env_help - Info by built in cmd 'env' is shown with this func
 */
void env_help(void)
{
char *info = "env: env\n\tPrints the current environment.\n";

write(STDOUT_FILENO, info, _strlen(info));
}

/**
 * setenv_help - Info by built in cmd 'setenv' is shown with this func
 */
void setenv_help(void)
{
char *info = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

write(STDOUT_FILENO, info, _strlen(info));
info = "envment variable, or modifies an existing one.\n\n";
write(STDOUT_FILENO, info, _strlen(info));
info = "\tUpon failure, prints a message to stderr.\n";
write(STDOUT_FILENO, info, _strlen(info));
}

/**
 * unsetenv_help - Info by built in cmd 'unsetenv' is shown with this func
 */
void unsetenv_help(void)
{
char *info = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

write(STDOUT_FILENO, info, _strlen(info));
info = "environmental variable.\n\n\tUpon failure, prints a ";
write(STDOUT_FILENO, info, _strlen(info));
info = "message to stderr.\n";
write(STDOUT_FILENO, info, _strlen(info));
}
/**
 * show_help - show help for cmds which are in built
 * @cmd: cmd in question
 * @cond: condition of reviously executed cmd
 * Return: 0 when successful
 */
int show_help(char **cmd, __attribute__((unused)) int cond)
{
if (!cmd[1])
	help_all();
else if (_strcmp(cmd[1], "exit") == 0)
	help_exit();
else if (_strcmp(cmd[1], "cd") == 0)
	help_cd();
else if (_strcmp(cmd[1], "env") == 0)
	env_help();
else if (_strcmp(cmd[1], "alias") == 0)
	help_alias();
else if (_strcmp(cmd[1], "setenv") == 0)
	setenv_help();
else if (_strcmp(cmd[1], "help") == 0)
	help_help();
else if (_strcmp(cmd[1], "unsetenv") == 0)
	unsetenv_help();

return (0);
}

