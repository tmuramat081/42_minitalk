#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cast_s;
	char	*p;

	p = NULL;
	cast_s = (char *)s;
	while (1)
	{
		if (*cast_s == (char)c)
			p = cast_s;
		if (*cast_s == '\0')
			break ;
		cast_s++;
	}
	return (p);
}
