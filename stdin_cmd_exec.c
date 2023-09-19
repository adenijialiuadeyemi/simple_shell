#include "main.h"

/**
 * cmd_chk - This function perform the cmds in the path
 * @cmd: cmd strngs in an array
 * @user_input: User Input (this should be freed)
 * @tc:Time case of cmds not found
 * @argv:Arg vector befor the prog starts (argv[0] == Shell Program Name)
 * Return: 0 when cmd is executed, -1 when there is error, 1 when NULL
 */

int cmd_chk(char **cmd, char *user_input, int tc, char **argv)
{
int cond;
pid_t pid;

if (*cmd == NULL)
return (EXIT_FAILURE);
pid = fork();
if (pid == -1)
{
perror("Error");
return (-1);
}
if (pid == 0)
{
if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
	path_cmd(cmd);
if (access(cmd[0], R_OK) != 0)
{
print_error(cmd[0], tc, argv);
free_all(cmd, user_input);
exit(127);
}
if (execve(*cmd, cmd, environ) == -1)
	return (2);
else
	return (0);
}
wait(&cond);
if (WIFEXITED(cond))
{
if (WEXITSTATUS(cond) == 0)
	return (0);
else if (WEXITSTATUS(cond) == 2)
	return (2);
else if (WEXITSTATUS(cond) == 127)
	return (127);
}
return (127);
}

/**
 * signal_to_be_treated - This prevents Ctr+C to be a terminator
 * @treated_sig: treated signal
 */

void signal_to_be_treated(int treated_sig)
{
if (treated_sig == SIGINT)
{
PRINT("\n$ ");
}
}

