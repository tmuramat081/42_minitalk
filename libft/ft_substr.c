#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	s_len;
	size_t	d_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start + len)
		d_len = s_len - start;
	else
		d_len = len;
	if (!len || s_len <= start)
	{	
		dest = malloc(sizeof(char));
		*dest = '\0';
		return (dest);
	}
	dest = malloc(sizeof(char) * (d_len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, &s[start], d_len + 1);
	return (dest);
}
