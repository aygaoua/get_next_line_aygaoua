#include "get_next_line.h"
#include <stdio.h>
int main()
{
    int fd;
    char *k;

    fd = open("kiko.txt", O_RDONLY);
    get_next_line(fd);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
}