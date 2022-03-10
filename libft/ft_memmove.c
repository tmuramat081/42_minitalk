#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*cast_s;
	unsigned char		*cast_d;

	if (!src && !dst)
		return (dst);
	if (src < dst)
	{
		cast_s = src + len - 1;
		cast_d = dst + len - 1;
		while (len--)
			*(cast_d--) = *(cast_s--);
	}
	else
	{
		cast_s = src;
		cast_d = dst;
		while (len--)
			*(cast_d++) = *(cast_s++);
	}
	return (dst);
}
