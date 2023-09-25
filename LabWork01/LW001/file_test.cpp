/* Пiдключення потрiбних заголовних файлiв */
#include <stdio.h>

int main(int argc, char** argv)
{
    /* Оголошення покажчика на файлову змiнну */ 
    FILE *out;
    /* Вiдкриття файлу */
    if ((out = fopen(argv[1], "w")) == NULL)
    {
        /* Помилка */
        fprintf(stderr, "Error opening file %s", argv[1]);
        return 1;
    }
    /* Запис рядка символiв у файл */
    fprintf(out, "%s", "Example of using fopen()");
    /* Закриття файлу */
    fclose(out);
    return 0;
}