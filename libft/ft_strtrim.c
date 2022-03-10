#include "libft.h"

static int	check_charset(const char c, char const *charset)
{
	size_t	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	while (check_charset(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (check_charset(s1[j], set) && i < j)
		j--;
	j = j + 1;
	dest = (char *) malloc(sizeof(char) * (j - i + 1));
	if (dest)
		ft_strlcpy(dest, &s1[i], j - i + 1);
	return (dest);
}
