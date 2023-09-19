#include "main.h"

/**
 * help_help - Info by built in cmd 'help' is shown with this func
 */
void help_help(void)
{
char *info = "help: help\n\tSee all possible Shellby builtin commands.\n";

write(STDOUT_FILENO, info, _strlen(info));
info = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
write(STDOUT_FILENO, info, _strlen(info));
info = "builtin command.\n";
write(STDOUT_FILENO, info, _strlen(info));
}

/**
 * cd_help - Info by built in cmd 'cd' is shown with this func
 */
void cd_help(void)
{
char *info = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

write(STDOUT_FILENO, info, _strlen(info));
info = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
write(STDOUT_FILENO, info, _strlen(info));
info = "command is interpreted as cd $HOME. If the argument '-' is";
write(STDOUT_FILENO, info, _strlen(info));
info = " given, the command is interpreted as cd $OLDPWD.\n\n";
write(STDOUT_FILENO, info, _strlen(info));
info = "\tThe environment variables PWD and OLDPWD are updated ";
write(STDOUT_FILENO, info, _strlen(info));
info = "after a change of directory.\n";
write(STDOUT_FILENO, info, _strlen(info));
}

/**
 * all_help - Show all help
 */
void all_help(void)
{
char *info = "Shellby\nThese shell commands are defined internally.\n";

write(STDOUT_FILENO, info, _strlen(info));
info = "Type 'help' to see this list.\nType 'help name' to find ";
write(STDOUT_FILENO, info, _strlen(info));
info = "out more about the function 'name'.\n\n  alias   \t";
write(STDOUT_FILENO, info, _strlen(info));
info = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
write(STDOUT_FILENO, info, _strlen(info));
info = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
write(STDOUT_FILENO, info, _strlen(info));
info = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
write(STDOUT_FILENO, info, _strlen(info));
info = "unsetenv [VARIABLE]\n";
write(STDOUT_FILENO, info, _strlen(info));
}

/**
 * alias_help - Info by built in cmd 'alias' is shown with this func
 */
void alias_help(void)
{
char *info = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

write(STDOUT_FILENO, info, _strlen(info));
info = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
write(STDOUT_FILENO, info, _strlen(info));
info = " the aliases name, name2, etc. one per line, in the ";
write(STDOUT_FILENO, info, _strlen(info));
info = "\n\talias: Prints a list of all aliases, one per line, in ";
write(STDOUT_FILENO, info, _strlen(info));
info = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
write(STDOUT_FILENO, info, _strlen(info));
info = "is already an alias, replace its value with VALUE.\n";
write(STDOUT_FILENO, info, _strlen(info));
info = " an alias for each NAME whose VALUE is given. If NAME ";
write(STDOUT_FILENO, info, _strlen(info));
}

/**
 * exit_help - Info by built in cmd 'exit' is shown with this func
 */
void exit_help(void)
{
char *info = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

write(STDOUT_FILENO, info, _strlen(info));
info = "STATUS argument is the integer used to exit the shell.";
write(STDOUT_FILENO, info, _strlen(info));
info = " If no argument is given, the command is interpreted as";
write(STDOUT_FILENO, info, _strlen(info));
info = " exit 0.\n";
write(STDOUT_FILENO, info, _strlen(info));
}

