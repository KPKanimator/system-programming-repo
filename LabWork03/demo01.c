#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define S_IWRITE 0200
#define S_IREAD 0400


int main(void)
{
    int fd;
    char *file_name = "file1.dat";
    if ((fd = creat(file_name, S_IREAD | S_IWRITE)) == -1)
    {
        printf("Error creating file: %s\n", file_name);
        return 1;
    }
    close(fd);
    printf("0K\n");
}