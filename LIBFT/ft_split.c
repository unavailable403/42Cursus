#include "libft.h"

int	sp_alloc_size(const char *s, char c)
{
	int	tot;
	int	i;

	i = 0;
	tot = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			tot++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (tot);
}

char	*ft_wrd_wrt(const char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (*s == c && *s)
		s++;
	while (s[i] != c && s[i])
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (*s && *s != c)
	{
		str[i] = *s;
		i++;
		s++;
	}
	str[i] = 0;
	return (str);
}

void	ft_free_wrt(int i, char **sp)
{
	while (i > 0)
	{
		free(sp[i - 1]);
		i--;
	}
	free(sp);
}

char	**ft_writter(char **split, const char *s, char c, int msize)
{
	int	i;

	i = 0;
	while (i < msize)
	{
		while (*s && *s == c)
			s++;
		split[i] = ft_wrd_wrt(s, c);
		if (!split[i])
			ft_free_wrt(i, split);
		while (*s && *s != c)
			s++;
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		msize;

	msize = sp_alloc_size(s, c);
	split = (char **)malloc(sizeof(char *) * (msize + 1));
	if (!split)
		return (NULL);
	if (msize == 0)
	{
		split[0] = NULL;
		return (split);
	}
	split = ft_writter(split, s, c, msize);
	return (split);
}
