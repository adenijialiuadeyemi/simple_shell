#include "main.h"
/**
 * path_cmd -  Checking for exec cmd
 * @cmd: cmd in question
 * Return: 0 when successful otherwise 1
 */
int path_cmd(char **cmd)
{
char *pth, *val, *cmd_pth;
struct stat buf;

pth = _getenv("pth");
val = _strtok(pth, ":");
while (val != NULL)
{
cmd_pth = build(*cmd, val);
if (stat(cmd_pth, &buf) == 0)
{
*cmd = _strdup(cmd_pth);
free(cmd_pth);
free(pth);
return (0);
}
free(cmd_pth);
val = _strtok(NULL, ":");
}
free(pth);
free(val);
return (1);
}
/**
 * build - The func builds cmds
 * @tok: exec_cmd
 * @val: cmd folder
 * Return: full path otherwise null
 */
char *build(char *tok, char *val)
{
char *cmd;
size_t len;

len = _strlen(val) + _strlen(tok) + 2;
cmd = malloc(sizeof(char) * len);
if (cmd == NULL)
{
free(cmd);
return (NULL);
}

memset(cmd, 0, len);

cmd = _strcat(cmd, val);
cmd = _strcat(cmd, "/");
cmd = _strcat(cmd, tok);

return (cmd);
}
/**
 * _getenv - The func obtain the env varname
 * @env_name: env var_name
 * Return: val of env_var_name otherwise null
 */
char *_getenv(char *env_name)
{
size_t len_name, len_val;
char *val;
int c, m, n;

len_name = _strlen(env_name);
for (c = 0; env_def[c]; c++)
{
if (_strncmp(env_name, env_def[c], len_name) == 0)
{
len_val = _strlen(env_def[c]) - len_name;
val = malloc(sizeof(char) * len_val);
if (!val)
{
free(val);
perror("unable to alloc");
return (NULL);
}

m = 0;
for (n = len_name + 1; env_def[c][n]; n++, m++)
{
val[m] = env_def[c][n];
}
val[m] = '\0';

return (val);
}
}
return (NULL);
}

