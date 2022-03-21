#include "libft.h"

int	start_trim(char const *s1, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (set[i])
	{
		if (set[i] == *s1)
		{
			i = 0;
			count++;
			s1++;
		}
		else
			i++;
	}
	return (count);
}

int	end_trim(char const *s1, char const *set)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	len = ft_strlen(s1) -1;
	while (set[i])
	{
		if (set[i] == s1[len])
		{
			i = 0;
			count++;
			len--;
		}
		i++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	strlen;
	char	*str;

	if (!*set || (start_trim(s1, set) == 0 && end_trim(s1, set) == 0))
	{
		str = ft_strdup(s1);
		return (str);
	}
	start = start_trim(s1, set);
	len = ft_strlen(s1) - (start + end_trim(s1, set));
	str = ft_substr(s1, start, len);
	if (str)
	{
		strlen = ft_strlen(str);
		str[strlen] = '\0';
	}
	else
		str = ft_strdup("");
	return (str);
}
