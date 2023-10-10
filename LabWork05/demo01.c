#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define DEBUG 1

int main(int argc, char **argv)
{
    int fd;
    ssize_t len;
    unsigned char *bytes;

    if (argc < 2)
    {
        printf("Too few arguments\n");
        return 1;
    }
    // Вiдкриваємо файл для читання та запису 
    if ((fd = open(argv[1], O_RDWR)) == -1)
    {
        printf("Cannot open input file %s\n", argv[1]);
        return 1;
    }
    // Визначаємо довжину файлу 
    len = lseek(fd, 0, SEEK_END); 
    if (DEBUG)
        printf("File length: %lu\n", len);
    // Вiдображаємо файл у пам’ять
    if ((bytes = (unsigned char *)mmap(0, len, PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }
    // Змiнюємо файл за допомогою
    // модифiкацiї вiдображеної пам’ятi bytes[0] = ’M’;
    bytes[0] = 'M';
    bytes[1] = 'm';
    bytes[2] = 'a';
    bytes[3] = 'p';
    close(fd);
    // Звiльняємо пам’ять
    if (munmap(bytes, len) == -1)
    {
        perror("munmap");
        return 1;
    }
    return 0;
}

