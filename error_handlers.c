#include "main.h"

/**
 * print_error - the func shows err msg
 * @user_input: user_input
 * @c: count the shell_loop
 * @argv: args prior to prog exec(argv[0] == Name of shell_prog)
 */

void print_error(char *user_input, int c, char **argv)
{
char *er;

PRINT(argv[0]);
PRINT(": ");
er = _itoa(c);
PRINT(er);
free(er);
PRINT(": ");
PRINT(user_input);
PRINT(": not found\n");
}

/**
 *  _prerror - The func output user_defined error
 * @argv: args prior to prog exec(argv[0] == Name of shell_prog)
 * @c: counter of err
 * @cmd: cmd in question as array
 */

void _prerror(char **argv, int c, char **cmd)
{
char *er = _itoa(c);

PRINT(argv[0]);
PRINT(": ");
PRINT(er);
PRINT(": ");
PRINT(cmd[0]);
PRINT(": Illegal number: ");
PRINT(cmd[1]);
PRINT("\n");
free(er);
}

/**
 * error_file - The func output user_defined error
 * @argv: args prior to prog exec(argv[0] == Name of shell_prog)
 * @c: counter of err
 */

void error_file(char **argv, int c)
{
char *er = _itoa(c);

PRINT(argv[0]);
PRINT(": ");
PRINT(er);
PRINT(": Can't open ");
PRINT(argv[1]);
PRINT("\n");
free(er);
}

