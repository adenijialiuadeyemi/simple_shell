#include "main.h"

/**
 * create_env - The func creates arr of env var
 * @env: Env vars Arr
 */
void create_env(char **env)
{
int c;

for (c = 0; env_def[c]; c++)
	env[c] = _strdup(env_def[c]);
env[c] = NULL;
}

/**
 * free_env - The func clears the memory of env var arr
 * @env:  Env vars Arr
 */

void free_env(char **env)
{
int c;

for (c = 0; env[c]; c++)
{
free(env[c]);
}
}
