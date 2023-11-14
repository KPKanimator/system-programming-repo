#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
/* Зміна пріоритету
поточного користувача */
int main(int argc, char **argv)
{
    int uid,
        prior;

    if (argc < 3)
    {
        printf("Too few arguments!\n");
        return 1;
    }
    /* Визначаємо uid */
    if ((uid = atoi(argv[1])) == 0 && !errno)
    {
        printf("Incorrect uid!\n");
        return 1;
    }

    /* Визначаємо новий пріоритет */
    if ((prior = atoi(argv[2])) == 0 && !errno)
    {
        printf("Incorrect new priority!\n");
        return 1;
    }
    /* Задаємо новий пріоритет */
    if (setpriority(PRIO_USER, uid, prior) == -1)
    {
        perror("setpriority()");
        return 1;
    }
    printf("New user priority: %d\n",
           getpriority(PRIO_USER, uid));
    return 0;
}