#include "libft.h"

size_t	ft_strlcpy(char *dst, const char*src, size_t dstsize)
{
	size_t	len;

	if (!dst || !src)
		return (0);
	len = ft_strlen((char *)src);
	if (!dstsize)
		return (len);
	if (len >= dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	else
		ft_memcpy(dst, src, len + 1);
	return (len);
}
