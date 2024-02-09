#include "unistd.h"
#include "stdio.h"
#include "string.h"

//https://unix.stackexchange.com/questions/11946/how-big-is-the-pipe-buffer
//65535 is max pipe sizr
int main()
{
	int fd[2];
	pipe(fd);
	int nb_char_write = 66666;
	for (size_t i = 0; i < nb_char_write; i++)
	{
		write(fd[1], "a", 1 );
		printf("%zu\n", i);
	}
	write(fd[1], "z", 1 );

	char buffer[77777];
	bzero(buffer, 77777);

	read(fd[0], buffer, 77777);
	printf("%s\n", buffer);
}
