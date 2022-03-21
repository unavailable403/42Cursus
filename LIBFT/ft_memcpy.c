#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	unsigned char		*cpy;
	unsigned const char	*src_char;

	src_char = src;
	cpy = dst;
	while (n--)
	{
		*cpy = *src_char;
		src_char++;
		cpy++;
	}
	return (dst);
}
