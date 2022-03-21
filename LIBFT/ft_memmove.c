#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	unsigned const char	*src2;

	dst2 = dst;
	src2 = src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			*(dst2 + len) = *(src2 + len);
	}
	return (dst);
}
