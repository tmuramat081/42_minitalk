#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*p;
	size_t	len;

	len = ft_strlen(src) + 1;
	p = (char *) malloc (sizeof(char) * len);
	if (!p)
		return (NULL);
	ft_strlcpy(p, src, len);
	return (p);
}
