#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	char	*mem;

	total = count * size;
	mem = malloc(total);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, total);
	return (mem);
}
