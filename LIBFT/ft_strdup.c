#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	i = -1;
	dup = (char *)malloc(ft_strlen(src) + 1);
	if (!dup)
		return (NULL);
	while (src[++i])
		dup[i] = src[i];
	dup[i] = 0;
	return (dup);
}
