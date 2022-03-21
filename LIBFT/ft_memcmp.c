#include "libft.h"

int	ft_memcmp(const void *s0, const void *s, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)s0;
	s2 = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
