#include	"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	src1;
	size_t	x;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	src1 = dstlen;
	i = 0;
	if (dstsize == 0)
		return (srclen);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (i < (dstsize - src1 - 1) && src[i])
	{
		dst[dstlen] = src[i];
		i++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (src1 + srclen);
}
