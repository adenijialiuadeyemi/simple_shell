#include "main.h"

/**
 * read_the_doc - The func read cmds from the file args
 * @doc: file with cmds
 * @argv: passed args i.e arg vector
 * Return: 0 when successful, otherwise -1
 */

void read_the_doc(char *doc, char **argv)
{
FILE *file_pointre;
char *line = NULL;
size_t len = 0;
int cnt = 0;

file_pointre = fopen(doc, "r");
if (file_pointre == NULL)
{
error_doc(argv, cnt);
exit(127);
}
while ((getline(&line, &len, file_pointre)) != -1)
{
cnt++;
handle_doc(line, cnt, file_pointre, argv);
}
if (line)
	free(line);
fclose(file_pointre);
exit(0);
}

/**
 * handle_doc - This function resolves commands and then execution handling
 * @line: Line from file
 * @cnt: cnter of error
 * @file_pointre: pointre to a file
 * @argv: args of cmd line
 */

void handle_doc(char *line, int cnt, FILE *file_pointre, char **argv)
{
char **cmd;
int cond = 0;

cmd = parse_cmd(line);
if (_strncmp(cmd[0], "exit", 4) == 0)
exit_doc_cond(cmd, line, file_pointre);
else if (built_in_chk(cmd) == 0)
{
cond = handle_builtin(cmd, cond);
free(cmd);
}
else
{
cond = cmd_chk(cmd, line, cnt, argv);
free(cmd);
}
}

/**
 * exit_doc_cond - Exit status handler for file input
 * @line: Line from a file
 * @cmd: Parsed command
 * @file_pointre: File Descriptor
 */

void exit_doc_cond(char **cmd, char *line, FILE *file_pointre)
{
int cond;
int count_i = 0;

if (cmd[count_i] == NULL)
{
free(line);
free(cmd);
fclose(file_pointre);
exit(errno);
}
while (cmd[1][count_i])
{
if (_isalpha(cmd[1][count_i++]) < 0)
	perror("number is illegal");
}
cond = _atoi(cmd[1]);
free(line);
free(cmd);
fclose(file_pointre);
exit(cond);
}

