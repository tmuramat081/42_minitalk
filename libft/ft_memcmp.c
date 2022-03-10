#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cast;
	unsigned char	*s2_cast;

	s1_cast = (unsigned char *)s1;
	s2_cast = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_cast != *s2_cast)
			return (*s1_cast - *s2_cast);
		s1_cast++;
		s2_cast++;
	}
	return (0);
}
