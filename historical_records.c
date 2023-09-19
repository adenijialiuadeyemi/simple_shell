#include "main.h"
/**
 * history - The function output doc with input of users
 * @user_input: input of user
 * Return: 0 when successful, otherwise -1
 */
int history(char *user_input)
{
int len = 0;
char *fn = ".history_simple_shell";
ssize_t file_descr, ret_write;

if (!fn)
	return (-1);
file_descr = open(fn, O_CREAT | O_RDWR | O_APPEND, 00600);
if (file_descr < 0)
	return (-1);
if (user_input)
{
while (user_input[len])
	len++;
ret_write = write(file_descr, user_input, len);
if (ret_write < 0)
	return (-1);
}
return (1);
}

