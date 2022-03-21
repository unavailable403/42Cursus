#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	mall_len;
	int		i;

	i = -1;
	if (!s || !f)
		return (NULL);
	mall_len = ft_strlen((char *)s);
	str = (char *)malloc(mall_len + 1);
	if (!str)
		return (NULL);
	while (s[++i])
		str[i] = f(i, s[i]);
	str[i] = '\0';
	return (str);
}
