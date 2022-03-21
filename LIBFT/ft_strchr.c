#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	tar;

	if (!c)
		return ((char *)str + ft_strlen(str));
	tar = c;
	while (*str)
	{
		if (*str == tar)
			return ((char *)str);
		else if (!*str++)
			return (0);
	}
	return (0);
}
