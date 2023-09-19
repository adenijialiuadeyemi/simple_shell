#include "main.h"

/**
 * print_number - output unsigned_int
 * @num: int to output
 */

void print_number(unsigned int num)
{
unsigned int y = num;

if ((y / 10) > 0)
	print_number(y / 10);

_putchar(y % 10 + '0');
}

/**
 * print_number_int - output int
 * @num: int to output
 */

void print_number_int(int num)
{
unsigned int y = num;

if (num < 0)
{
_putchar('-');
y = -y;
}
if ((y / 10) > 0)
	print_number(y / 10);

_putchar(y % 10 + '0');
}

/**
 * print_echo - exec echo
 * @cmd: cmd in question
 * Return: 0 when successful otherwise -1
 */

int print_echo(char **cmd)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
{
if (execve("/bin/echo", cmd, env_def) == -1)
{
return (-1);
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
return (-1);
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}

