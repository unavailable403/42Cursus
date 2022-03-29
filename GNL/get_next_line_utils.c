#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str)
		while (str[len])
			len++;
	return (len);
}

int ft_memchr(const char *s, int c)
{
	const char		*str;

	str = s;
	while (*str)
	{
		if (*str == (char)c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{	
	char	*joined_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	joined_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined_str)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		joined_str[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2 && s2[i] != '\0')
	{
		joined_str[j] = s2[i];
		j++;
		i++;
	}
	joined_str[j] =  0;
	free(s1);
	return (joined_str);
}
