#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cast_s;

	cast_s = (char *)s;
	while (1)
	{
		if (*cast_s == (char)c)
			return (cast_s);
		if (*cast_s == '\0')
			break ;
		cast_s++;
	}
	return (NULL);
}
