char *ft_strdup(char *src);
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
	char *str;
	char *allocated;

	str = "Hello World with malloc()";
	printf("x : base : $%s$ @ %p\n", str, str);
	allocated = strdup(str);
	printf("c : alloc : $%s$ @ %p\n", allocated, allocated);
	allocated = ft_strdup(str);
	printf("ft: alloc: $%s$ @ %p\n", allocated, allocated);
}
