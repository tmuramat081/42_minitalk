#include "libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	cnt;

	cnt = 0;
	while (*c++ != '\0')
		cnt += 1;
	return (cnt);
}
