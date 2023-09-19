#include "main.h"
/**
 * _realloc -  Reallocate_mem
 *@ptr: ptr
 *@size_old: Old Size
 *@size_new: current size
 *Return: ptr
 */
void *_realloc(void *ptr, unsigned int size_old, unsigned int size_new)
{
void *res;

if (size_new == size_old)
	return (ptr);
if (size_new == 0 && ptr)
{
free(ptr);
return (NULL);
}
res = malloc(size_new);
if (res == NULL)
{
free(res);
return (NULL);
}
if (ptr == NULL)
{
fill_an_array(res, '\0', size_new);
free(ptr);
}
else
{
_memcpy(res, ptr, size_old);
free(ptr);
}
return (res);
}
/**
 * free_all - empty alloc_mem
 * @cmd: ptr of arr
 * @line: ptr of char
 * Return: nothing
 */
void free_all(char **cmd, char *line)
{
free(cmd);
free(line);
cmd = NULL;
line = NULL;
}
/**
 * _memcpy - cpy mem_bytes
 *@destin: destin_ptr
 *@sorce: sorce_ptr
 *@n: size_copied
 *Return: destin_ptr
 */
char *_memcpy(char *destin, char *sorce, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
{
destin[i] = sorce[i];
}
return (destin);
}
/**
 * fill_an_array - const_byte arr
 *@a: void_ptr
 *@el: integer
 *@len: int_length
 *Return: void_ptr
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
char *pt = a;
unsigned int c = 0;

while (c < len)
{
*pt = el;
pt++;
c++;
}
return (a);
}
/**
 * _calloc - mem_alloc with malloc
 *@size: mem_size
 *Return: nothing
 */
void *_calloc(unsigned int size)
{
char *p;
unsigned int c;

if (size == 0)
	return (NULL);
p = malloc(size);
if (p == NULL)
	return (NULL);
for (c = 0; c < size; c++)
{
p[c] = '\0';
}
return (p);
}

