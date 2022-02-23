#include "ft_stock_str.h"
#include <stdlib.h>
#include <stdio.h>
struct s_stock_str *ft_strs_to_tab(int ac, char **av);
char **ft_strcpy(char *str);
int ft_strlen(char *str);

int	main(int argc, char **argv)
{
	struct s_stock_str *stock_str;
	stock_str = ft_strs_to_tab(argc, argv);
	for(int i = 0; stock_str[i].str!=0; i++)
	{
		printf("%d, %s\n", stock_str[i].size, stock_str[i].str);
	}
	for(int i=0;stock_str[i].str!=0;i++)
		free(stock_str[i].copy);
	free(stock_str);
	return (0);
}
