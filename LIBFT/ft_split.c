/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:03:02 by ergrigor          #+#    #+#             */
/*   Updated: 2022/03/23 22:09:39 by ergrigor         ###   ########.fr       */
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

static void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i++])
		free(str[i]);
	free(str);
}

static char	**ft_writter(char **split, char const *s, char c)
{
	size_t	len;
	size_t	i;

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
				ft_free(split);
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

	if (!s)
		return (NULL);
	msize = ft_msize(s, c);
	split = malloc(sizeof(char *) * (msize + 1));
	if (!split)
		return (NULL);
	split = ft_writter(split, s, c);
	return (split);
}
