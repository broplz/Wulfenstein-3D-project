#include "../include/cub3d.h"

int		ft_path_check(char *line)
{
	int fd;

	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (1);
}
