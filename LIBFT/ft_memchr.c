#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*str;

	str = s;
	while (n--)
	{
		if (*str == (char)c)
			return ((void *)str);
		str++;
	}
	return (0);
}
