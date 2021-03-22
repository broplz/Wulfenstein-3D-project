#include "../include/cub3d.h"

int 	ft_map_search(t_all *all, char *line)
{
	if (!line || *line == '\0')
		return (1);
	while (*line == ' ')
		line++;
	if ((*line) == '1')
		return (1 + (all->co.pflag = 2) - 2);
	else
		return (-1 + (all->co.pflag = -1) + 1);
}
