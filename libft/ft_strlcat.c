#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;

	if (!dstsize)
		return (ft_strlen(src));
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize < d_len)
		return (s_len + dstsize);
	ft_strlcpy (dst + d_len, src, dstsize - d_len);
	return (d_len + s_len);
}
