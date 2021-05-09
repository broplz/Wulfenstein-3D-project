#include "../include/cub3d.h"

void	ft_fl_ce_cst(t_all *all)
{
	int y;
	int x;

	y = 0;
	while (y < H / 2)
	{
		x = 0;
		while (x < W)
		{
			my_mlx_pixel_put(all, x, y, all->par.col.ce);
			x++;
		}
		y++;
	}
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			my_mlx_pixel_put(all, x, y, all->par.col.fl);
			x++;
		}
		y++;
	}
}
