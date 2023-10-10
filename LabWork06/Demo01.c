#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t pid;
    if ((pid = fork()) == -1)
    {
        perror("Fork");
        return 1;
    }
    if (pid == 0)
        printf("Now working child process with pid = %d\n", getpid());
    else
        printf("Now working parent process with pid = %d\n", getpid());

    return 0;
}
