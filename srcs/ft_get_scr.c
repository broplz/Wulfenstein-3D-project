#include "../include/cub3d.h"

void		ft_get_scr(t_all *all)
{
	int		x;
	int		y;

	mlx_get_screen_size(all->data.mlx, &x, &y);
	if (all->co.scr_fl == 1)
	{
		if (all->par.res.x > 10000)
			all->par.res.x = 10000;
		if (all->par.res.y > 10000)
			all->par.res.y = 10000;
	}
	else
	{
		if (all->par.res.x > x)
			all->par.res.x = x;
		if (all->par.res.y > y)
			all->par.res.y = y;
	}
}
