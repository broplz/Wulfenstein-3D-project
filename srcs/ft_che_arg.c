#include "../include/cub3d.h"

void	ft_che_arg(char *line)
{
	size_t i;

	if((i = ft_strlen(line)) < 4)
		ft_error_close("Wrong format for map");
	if (!(line[i - 1] == 'b' &&
		  line[i - 2] == 'u' &&
		  line[i - 3] == 'c') &&
		line[i -4] == '.')
		ft_error_close("Invalid format for map");
}