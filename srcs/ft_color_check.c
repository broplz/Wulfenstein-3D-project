#include "../include/cub3d.h"

int		ft_color_check(int r, int g, int b)
{
	if (!(r > -1 && r < 256))
		return (-1);
	if (!(g > -1 && r < 256))
		return (-1);
	if (!(b > -1 && r < 256))
		return (-1);
	return (1);
}