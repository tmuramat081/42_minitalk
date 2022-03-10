#include "libft.h"

int	ft_atoi(const char *str)
{
	int			flag;
	long int	num;

	flag = 1;
	num = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+')
		str += 1;
	else if (*str == '-')
	{
		flag = 0;
		str += 1;
	}
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (!flag)
		num = 0 - num;
	return (num);
}
