#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (!fd || !s)
		return ;
	while (s[++i] != '\0')
		write(fd, &s[i], 1);
}
