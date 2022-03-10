#include <stdio.h>

void	*ft_memchr(const void *buff, int ch, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)buff;
	while (n--)
	{
		if (*p == (unsigned char)ch)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
