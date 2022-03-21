#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	str;

	str = ft_strlen(needle);
	if (!*needle)
		return ((char *)(haystack));
	while (len)
	{
		if (!*haystack || str > len--)
			return (0);
		if (!ft_strncmp(haystack, needle, str))
			return ((char *)(haystack));
		haystack++;
	}
	return (0);
}
