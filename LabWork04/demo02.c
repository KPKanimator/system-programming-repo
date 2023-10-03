#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv)
{
    DIR *dir;
    struct dirent *entry;
    char *path = "."; /* Поточна папка */

    if (argc > 1)
        path = argv[1];
    if ((dir = opendir(path)) == NULL)
    {
        fprintf(stderr, "Unable open directory %s\n", path);
        return 1;
    }
    while ((entry = readdir(dir)) != NULL)
        printf("%s\n", entry->d_name);
    closedir(dir);
    return 0;
}

