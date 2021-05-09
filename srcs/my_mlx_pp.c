#include "../include/cub3d.h"

void		my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char    *dst;

	dst = all->data.addr + (y * all->data.ln_len + x * (all->data.bpp / 8));
	*(unsigned int*)dst = color;
}
