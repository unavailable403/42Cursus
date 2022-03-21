#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		if (j < len && start <= i)
		{
			new_str[j] = s[i];
			++j;
		}
		i++;
	}
	new_str[j] = 0;
	return (new_str);
}
