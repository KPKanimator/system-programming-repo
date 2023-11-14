#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
int main(void)
{
    cpu_set_t set;
    int ret, i, cpu;
    /* Очищення набору процесорів */
    CPU_ZERO(&set);
    /* Прив'язка поточного  процесу до процесора 0 */
    CPU_SET(0, &set);
    /* Заборона використання решти процесорів */
    for (int i = 1; i < CPU_COUNT(&set); i++)
        CPU_CLR(i, &set);
    ret = sched_setaffinity(0, sizeof(cpu_set_t), &set);
    if (ret == -1)
        perror("sched_setaffinity");
    for (i = 0; i < CPU_SETSIZE; i++)
    {
        cpu = CPU_ISSET(i, &set);
        printf("cpu=%i is %s\n", i, cpu ? "set" : "unset");
    }
}