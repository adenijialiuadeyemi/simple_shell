#include "main.h"
/**
 * main - Star oint of the simple shell
 * @argc: Count of Arg
 * @argv: Arg vector
 * Return: status
 */
int main(__attribute__((unused)) int argc, char **argv)
{
char *user_input, **cmd, **cmds;
int count = 0;
int indx, cond = 0;

if (argv[1] != NULL)
	read_the_doc(argv[1], argv);
signal(SIGINT, signal_to_be_treated);
while (1)
{
count++;
if (isatty(STDIN_FILENO))
	cmd_prompt();
user_input = _getline();
if (user_input[0] == '\0')
	continue;
history(user_input);
cmds = separator(user_input);
for (indx = 0; cmds[indx] != NULL; indx++)
{
cmd = parse_cmd(cmds[indx]);
if (_strcmp(cmd[0], "exit") == 0)
{
free(cmds);
exit_file_bool(cmd, user_input, argv, count, stat);
}
else if (check_builtin(cmd) == 0)
{
cond = handle_builtin(cmd, cond);
free(cmd);
continue;
}
else
	cond = check_cmd(cmd, user_input, count, argv);
free(cmd);
}
free(user_input);
free(cmds);
wait(&cond);
}
return (cond);
}

