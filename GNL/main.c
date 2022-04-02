#include "../../../gnlOrig/get_next_line.h"

int main()
{
    int fd = open("63_line_nl", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    return 0;

}
