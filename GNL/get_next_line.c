#include "get_next_line.h"

char    *ft_getline(char *buff)
{
    size_t  i;
    char *line;

    i = 0;
   // if (!buff)
    
    while (buff && (buff[i++] != '\n' && buff[i] != '\0'))
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
    if (!buff)
        return (NULL);
    char *newbuff;
    size_t  i;
    size_t  j;
    size_t len;
    i = 0;
    while (buff[i] != '\n' && buff[i] != '\0')
        i++;
    j = i;
    if(buff[i] == '\n')
        while (buff[j])
            j++;
    newbuff = malloc(j - i + 1);
    if (!newbuff)
        return NULL;
    len = j - i;
    newbuff[len] = 0;
    while (len)
    {
        len--;
        newbuff[len] = buff[j];
        j--;
    }
    //printf("\n newbuff \n---------------------\n%s\n-----------------------------",newbuff);
    free(buff);
    return (newbuff);
}

// char *ft_getminusbuff(char *buff)
// {
//     size_t i;
//     while (/* condition */)
//     {
//         /* code */
//     }
    
// }

char    *get_next_line(int fd)
{
    static char *buff;
    char        *line;
    char        *tmp;
    size_t      i;
    int         flag;

    i = -1;
    tmp = malloc(BUFFER_SIZE + 1);
    if (!tmp)
        return (NULL);
    while (flag != 0)
    {
        flag = read(fd, tmp, BUFFER_SIZE);
        buff = ft_strjoin(buff, tmp);
        //printf("%s", buff);
        if(ft_memchr(tmp, '\0', flag) || ft_memchr(tmp, '\n', flag))
            break;
        tmp[flag] = 0;
    }
    line = ft_getline(buff);
    //printf("\n%s\n", buff);
    if(flag == 0 && !buff)
        return (line);
    else
        buff = ft_getbuff(buff);
    return (line);
}

int main(){
    char *line;
    int fd;

    fd = open("t.txt", O_RDONLY);
    // while ((line = get_next_line(fd)))
    //      printf("%s", line);
    line = get_next_line(fd);
    printf("\n%s\n", line);
    line = get_next_line(fd);
    printf("\n%s\n", line);
    line = get_next_line(fd);
    printf("\n%s\n", line);
    line = get_next_line(fd);
    printf("\n%s\n", line);
    line = get_next_line(fd);
    printf("\n%s\n", line);
    line = get_next_line(fd);
    printf("\n%s\n", line);
    return 0;
}