#ifndef SHELL_H
#define SHELL_H

/***** Unchangeable Macro definitions *****/

#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"

/*** Libaries of standard functions ***/

#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <linux/limits.h>

/******** Function prototypes that handles all strngs **********/

char *_strncpy(char *destin, char *sorce, int n);
int _strlen(char *strng);
int _putchar(char ch);
int _atoi(char *strng);
void _putstrng(char *strng);
int _strngcmp(char *str1, char *str2);
int _isalpha(int c);
void rev_arr(char *arr, int len);
int intlen(int n);
char *_itoa(unsigned int n);
char *_strcat(char *destin, char *sorce);
char *_strngcpy(char *destin, char *sorce);
char *_strngchr(char *strng, char l);
int _strncmp(const char *strng1, const char *strng2, size_t n);
char *_strngdup(char *strng);

/*********** Prototypes that handles memory ***********/

void env_free(char **env);
void *array_fill(void *ptr, int el, unsigned int len);
char *_memcpy(char *destin, char *sorce, unsigned int n);
void *_calloc(unsigned int s);
void *_realloc(void *ptr, unsigned int size_old, unsigned int size_new);
void all_free(char **cmd, char *line);

/****** Prototypes that handles inputs and other related *******/

char *_getline();
char *space(char *str);
char *enter(char *str);
void hashtag_handler(char *bufer);
void cmd_prompt(void);
unsigned int check_delim(char c, const char *str);
char *_strtok(char *strng, const char *delim);
int cmd_history(char *us_input);
char **sep_cmds(char *us_input);

/****** Prototypes that handle file mgt ******/

void read_file(char *cmd_file, char **argv);
void handle_file(char *line, int c, FILE *f_pt, char **argv);
void exit_bool_file(char **cmd, char *line, FILE *fd);

/****** Prototype that handles file argument *****/

char **parse_cmd(char *std_input);
int handle_builtin(char **cmd, int er);
int check_cmd(char **cmd, char *us_input, int t, char **argv);
void treat_signal(int s);

/******* Prototype that handles errors ******/

void print_error(char *us_input, int c, char **argv);
void cust_err(char **argv, int c, char **cmd);
void file_err(char **argv, int c);

/****** Prototyes that handles evironment ******/

extern char **environ;
void env_create(char **env);
void env_free(char **env);

/****** Prototypes that handle printing  *****/

void num_print(unsigned int n);
void num_print_int(int n);
int echo_print(char **cmd);

/******* Prototypes that helps to find path *******/

int path_cmd(char **cmd);
char *build(char *token, char *value);
char *_envget(char *env_n);

/******* prototypes that handles help *******/

void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
int display_help(char **cmd, __attribute__((unused))int st);

/****** Prototypes that handles built in cmd and exec ******/

int check_builtin(char **cmd);
int handle_builtin(char **cmd, int st);
void exit_bul(char **cmd, char *input, char **argv, int c,
		int stat);
int change_dir(char **cmd, __attribute__((unused))int st);
int dis_env(__attribute__((unused)) char **cmd,
		__attribute__((unused)) int st);
int echo_bul(char **cmd, int st);
int history_dis(__attribute__((unused))char **c,
		__attribute__((unused)) int st);

/****** This creates a structure that wouul be be used later *****/

/**
 * struct _builtin - The structure defines built in structure
 * in addition to their functionalities
 * @command: - cmd in question
 * @function: - Aiming to the func with same implementation
 * as built in cmds
 */
typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

#endif /*SHELL_H*/
