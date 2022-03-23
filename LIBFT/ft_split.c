/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:03:02 by ergrigor          #+#    #+#             */
/*   Updated: 2022/03/23 21:03:21 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_msize(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			i--;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

void	ft_free_wrt(char **sp)
{
	int	i;
	
	i = -1;
	while(sp[++i])
		free(sp[i]);
	free(sp);
}

static char	**ft_writter(char **split, char const *s, char c, size_t len, size_t i)
{
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			split[i] = ft_substr(s - len, 0, len);
			if (!split[i++])
			{
				ft_free_wrt(split);
				return (NULL);
			}
		}
		else
			s++;
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	msize;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	msize = ft_msize(s, c);
	split = malloc(sizeof(char *) * (msize + 1));
	if (!split)
		return (NULL);
	split = ft_writter(split, s, c, len, i);
	return (split);
}
