#include "get_next_line.h"

char    *ft_getline(char *buff)
{
    size_t  i;
    char *line;

    i = 0;
   // if (!buff)
    
    while (buff && (buff[i] != '\n' && buff[i] != '\0'))
        i++;
    line = malloc(i + 2);
    if(!line)
        return (NULL);
    line[i + 1] = 0;
    line[i] = '\n';
    i = 0;
    while (buff && (buff[i] != '\n' && buff[i] != '\0'))
    {
        line[i] = buff[i];
        i++;
    }
    return (line);
}

char    *ft_getbuff(char *buff)
{
    char    *newbuff;
    size_t  j;
    size_t  len;    

    j = 0;
    if (!buff)
        return (NULL);
    
    while (buff && (buff[j] != '\n' && buff[j] != '\0'))
        j++;
   // printf("\n%d\n", 0);
    if (buff[j] == '\0')
    {
        free(buff);
        return (NULL);
    }
    len = ft_strlen(buff)-j;
    newbuff = malloc(len + 1);
    if(!newbuff)
        return (NULL);
    newbuff[len] = 0;
    len = 0;
    j++;
    while (buff[j] != '\n' && buff[j] != '\0')
    {
        newbuff[len] = buff[j];
        j++;
        len++;
    }
    free(buff);
    return (newbuff);
}

char    *get_next_line(int fd)
{
    static char *buff = 0;
    char        *line;
    char        *tmp;
    size_t      i;
    int         flag;

    i = -1;
    tmp = malloc(BUFFER_SIZE + 1);
    if (!tmp)
        return (NULL);
    while (1)
    {
        flag = read(fd, tmp, BUFFER_SIZE);
        if (flag < 1)
            break;
        buff = ft_strjoin(buff, tmp);
        if(ft_memchr(tmp, '\0', flag) || ft_memchr(tmp, '\n', flag))
            break;
        tmp[flag] = 0;
    }
 //   printf("\n%s\n", buff);
    line = ft_getline(buff);
    buff = ft_getbuff(buff);
   // printf("\n%s\n", buff);
    if (flag == 0 && !buff)
    {
        return (NULL);
    }
    
    return (line);
}

int main(){
    char *line;
    int fd;

    fd = open("t.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
         printf("%s", line);
    return 0;
}