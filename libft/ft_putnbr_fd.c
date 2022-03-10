#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	l_n;
	char		c;

	l_n = (long int)n;
	if (l_n < 0)
	{
		ft_putchar_fd('-', fd);
		l_n = l_n * -1;
	}
	if (l_n / 10)
		ft_putnbr_fd(l_n / 10, fd);
	c = l_n % 10 + '0';
	ft_putchar_fd(c, fd);
}
