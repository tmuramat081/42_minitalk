#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, (char *)s1, len_s1 + 1);
	ft_strlcat(dest, (char *)s2, len_s1 + len_s2 + 1);
	return (dest);
}
