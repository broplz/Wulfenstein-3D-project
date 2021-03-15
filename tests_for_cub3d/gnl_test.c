#include "./libft/libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char *line;
	int i = 0;
	int fd;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s", line);
		printf("\n");
	}
	return (0);
}