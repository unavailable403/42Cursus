/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:34:02 by ergrigor          #+#    #+#             */
/*   Updated: 2022/04/01 18:51:15 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *buff)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buff && (buff[i] != '\n' && buff[i] != '\0'))
		i++;
	if (!buff || !*buff)
		return (0);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		line[i] = buff[i];
		++i;
	}
	if (!buff[i])
		line[i] = 0;
	if (!buff[i])
		return (line);
	line[i] = '\n';
	line[i + 1] = 0;
	return (line);
}

char	*ft_getbuff(char *buff)
{
	char	*newbuff;
	size_t	i;
	size_t	j;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	newbuff = malloc(ft_strlen(buff) - i + 1);
	if (!newbuff)
		return (NULL);
	++i;
	j = 0;
	while (buff[i])
		newbuff[j++] = buff[i++];
	newbuff[j] = 0;
	free(buff);
	return (newbuff);
}

void	norm_fix(int fd, int *flag, char **line, char **buf)
{
	while (1)
	{
		*flag = read(fd, *line, BUFFER_SIZE);
		if (*flag <= 0)
			break ;
		(*line)[*flag] = 0;
		*buf = ft_strjoin(*buf, *line);
		if (ft_memchr(*buf, '\0') || ft_memchr(*buf, '\n'))
			break ;
	}
	free(*line);
}

char	*get_next_line(int fd)
{
	static char	*buff[65536];
	char		*line;
	int			flag;

	if (fd < 0 || fd > 65536 || BUFFER_SIZE < 1)
		return (NULL);
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	norm_fix(fd, &flag, &line, &buff[fd]);
	if (flag < 0)
		return (NULL);
	line = ft_getline(buff[fd]);
	buff[fd] = ft_getbuff(buff[fd]);
	if (!flag && !line)
		free(buff[fd]);
	if (!flag && !line)
		return (NULL);
	return (line);
}
// #include <stdio.h>
// int	main(){
// 	int fd = open("63_line_nl", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return 0;
// }