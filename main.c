#include "LIBFT/libft.h"

int main(){
    char *a = "      ";
    char **p = ft_split(a, ' ');
    printf("%s", p[0]);
    return 0;
}
