#include <stdio.h>

int main(void)
{
    FILE *file = fopen("example3.txt" , "w");
    /* Запис рядка символiв у файл */
    fputs("This is string.", file);
    /* Змiна поточної позицiї на 9 байт вiдносно початку файлу */
    fseek(file, 9, SEEK_SET );
    /* Допис нового рядка у файл */
    fputs("chars!", file); 
    fclose(file);
    return 0;
}