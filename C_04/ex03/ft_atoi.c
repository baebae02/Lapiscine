#include <stdbool.h>

bool	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (true);
	else if (c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}

int	ft_atoi(char *str)
{
	unsigned int	i;
	int				is_minus;
	int				result;

	i = 0;
	is_minus = 1;
	result = 0;
	while (ft_is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (*str - '0') + (result * 10);
		str++;
	}
	return (result * is_minus);
}
