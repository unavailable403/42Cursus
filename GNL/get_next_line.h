#ifndef GET_NEXT_LINE_H

#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char*   get_next_line(int fd);
size_t	ft_strlen(const char *str);
int ft_memchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);

#endif
