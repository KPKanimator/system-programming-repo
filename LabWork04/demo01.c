struct dirent
{
    /* Iндексний дескриптор файлу */
    ino_t d_ino;
    /* Не використовується */
    off_t d_off;
    /* Довжина структури */
    unsigned short d_reclen;
    /* Тип файлу
    (пiдтримується не всiма файловими системами) */
    unsigned char d_type;
    /* Iм’я файлу (нуль-термiнований рядок) */
    char d_name[256];
};
