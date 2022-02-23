#include <stdlib.h>
#include "./ex00/ft.h"
#include "./ex01/ft_boolean.h"
#include "./ex02/ft_abs.h"
#include "./ex03/ft_point.h"
#include "./ex04/ft_strs_to_tab.c"
#include "./ex05/ft_show_tab.c"
int	main(int argc, char **argv)
{
	struct s_stock_str *stock_str;
	stock_str = ft_strs_to_tab(argc, argv);
	ft_show_tab(stock_str);
	for(int i=0;stock_str[i].str!=0;i++)
		free(stock_str[i].copy);
	free(stock_str);
	return (SUCCESS);
}
