#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd;
	char* file_name = "file.dat";
	if ((fd = creat(file_name, S_IREAD | S_IWRITE)) == -1)
	{
		printf("Error creating file: %s\n", file_name);
		return 1;
	}
	close(fd);
	printf("0K\n");
}