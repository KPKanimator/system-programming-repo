#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/* Потокова функція */
void *thread_func(void *args)
{
    while (1)
        printf("Thread is working...\n");
    return NULL;
}

int main(void)
{
    pthread_t ptid; /* Ідентифікатор потоку */

    /* Створення потоку */
    if (pthread_create(&ptid, NULL, &thread_func, NULL) != 0)
    {
        perror("pthread_create()");
        return 1;
    }

    /* Затримка на одну секунду */
    sleep(1);
    return 0;
}
