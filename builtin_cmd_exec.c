#include "main.h"
/**
 * change_dir - The func changes dir
 * @cmd: cmd in question
 * @cond: Condition of the last cmd executed
 * Return: 0 when successful otherwise return 1(If old_pwd the, ret 0)
 */
int change_dir(char **cmd, __attribute__((unused))int cond)
{
int val = -1;
char cwd[PATH_MAX];

if (cmd[1] == NULL)
	val = chdir(getenv("HOME"));
else if (_strcmp(cmd[1], "-") == 0)
{
val = chdir(getenv("OLDPWD"));
}
else
	val = chdir(cmd[1]);

if (val == -1)
{
perror("hsh");
return (-1);
}
else if (val != -1)
{
getcwd(cwd, sizeof(cwd));
setenv("OLDPWD", getenv("PWD"), 1);
setenv("PWD", cwd, 1);
}
return (0);
}
/**
 * disp_env - The func shows env var
 * @cmd: cmd in question
 * @cond: cond for previosly executed cmd
 * Return: 0 everytime
 */
int disp_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int cond)
{
size_t i;
int len;

for (i = 0; environ[i] != NULL; i++)
{
len = _strlen(environ[i]);
write(1, environ[i], len);
write(STDOUT_FILENO, "\n", 1);
}
return (0);
}
/**
 * echo_bool - this execute cases of echo
 * @cond: cond of previous cmd
 * @cmd: cmd in question
 * Return: 1 everytime otherwise exec echo
 */
int echo_bool(char **cmd, int cond)
{
char *path;
unsigned int pid = getppid();

if (_strncmp(cmd[1], "$?", 2) == 0)
{
int_num_print(cond);
PRINT("\n");
}
else if (_strncmp(cmd[1], "$$", 2) == 0)
{
num_print(pid);
PRINT("\n");
}
else if (_strncmp(cmd[1], "$PATH", 5) == 0)
{
path = _getenv("PATH");
PRINT(path);
PRINT("\n");
free(path);
}
else
	return (echo_print(cmd));

return (1);
}
/**
 * disp_hist - output the history of user_inputs
 * @cmd: cmd to be worked on
 * @cond: cond of previously executed cmd
 * Return: 0 when successful, otherwise fail
 */
int disp_hist(__attribute__((unused))char **c, __attribute__((unused))int cond)
{
char *fn = ".simple_shell_history";
FILE *file_pointre;
char *line = NULL;
size_t len = 0;
int c = 0;
char *er;

file_pointre = fopen(fn, "r");
if (file_pointre == NULL)
{
return (-1);
}
while ((getline(&line, &len, file_pointre)) != -1)
{
c++;
er = _itoa(c);
PRINT(er);
free(er);
PRINT(" ");
PRINT(line);
}
if (line)
	free(line);
fclose(file_pointre);
return (0);
}

