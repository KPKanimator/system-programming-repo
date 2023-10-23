#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double *buffer;
    int size = 10;

    /* Динамічне виділення пам’яті */
    if ((buffer = malloc(size * sizeof(double))) == NULL)
    {
        perror("malloc()");
        return 1;
    }

    /* Робота з пам’яттю */ 
    for (int i = 0; i < size; i++)
    {
        buffer[i] = i;
        printf("%lf\n", buffer[i]);
    }
    /* Звільнення пам’яті */ 
    free(buffer);
    return 0;
}
