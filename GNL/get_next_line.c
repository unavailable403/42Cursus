#include "get_next_line.h"

char    *ft_getline(char *buff)
{
    size_t  i;
    char *line;

    i = 0;
    while (buff && (buff[i] != '\n' && buff[i] != '\0'))
        i++;
    line = malloc(i + 2);
    if(!buff || !line)
        return (NULL);
    i = 0;
    while (buff[i] != '\n' && buff[i] != '\0')
    {
        line[i] = buff[i];
        ++i;
    }
    line[i] = '\n';
    line[i + 1] = 0;
    return (line);
}

char    *ft_getbuff(char *buff)
{
    char *newbuff;
    size_t  i;
    size_t  j;
    // size_t len;
    i = 0;
    if (!buff)
        return (NULL);
    while (buff[i] != '\n' && buff[i] != '\0')
        i++;
    if(!buff[i])
    {
        free(buff);
        return NULL;
    }
    // j = i;
    // if(buff[i] == '\n')
    //     while (buff[j])
    //         j++;
    newbuff = malloc(ft_strlen(buff) - i + 1);
    if (!newbuff)
        return NULL;
    ++i;
    j = 0;
    while (buff[i])
        newbuff[j++] = buff[i++];
    newbuff[j] = 0;
    free(buff);
    return (newbuff);
}


char    *get_next_line(int fd)
{
    static char *buff;
    char        *line;
    char        *tmp;
    int         flag;

    if(fd < 0 || fd > 65536)
        return NULL;
    tmp = malloc(BUFFER_SIZE + 1);
    if (!tmp)
        return (NULL);
    while (1)
    {
        flag = read(fd, tmp, BUFFER_SIZE);
        if (flag <= 0)
            break;
        tmp[flag] = 0;
        buff = ft_strjoin(buff, tmp);
        if(ft_memchr(buff, '\n'))
            break;
    }
    free(tmp);
    if(flag < 0)
    {
        free(buff);
        return NULL;
    }
    line = ft_getline(buff);
    //printf("\n%s\n", buff);
    buff = ft_getbuff(buff);
    if(!flag && !line)
    {
        free(buff);
        return NULL;
    }
    return (line);
}

// int main(){
//    char *line;
//    int fd;

//    fd = open("empty", O_RDONLY);
//    while ((line = get_next_line(fd)))
//         printf("%s", line);
// //    line = get_next_line(fd);
// //    printf("line->%s<-", line);
//    free(line);
// //    line = get_next_line(fd);
// //    printf("line->%s", line);
// // while ((line = get_next_line(fd)))
// // {
// //     printf("line[%s]", line);
// //    free(line);
// // }
// // free(line);
// close(fd);
// sleep(1000);
//    // line = get_next_line(fd);
//    // printf("%s", line);
//    return 0;
// }
