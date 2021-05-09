#include "../include/cub3d.h"

void	ft_draw5(t_all *all, int x, int y)
{
	while (y < all->ray.draw_end)
	{
		t_tex_info *tex = NULL;
		if (all->ray.side == 0 && all->ray.step_x > 0)
			tex = &(all->tex.so);
		else if (all->ray.side == 0 && all->ray.step_x < 0)
			tex = &(all->tex.no);
		else if (all->ray.side == 1 && all->ray.step_y > 0)
			tex = &(all->tex.ea);
		else
			tex = &(all->tex.we);
		all->ray.tex_y = (int) all->ray.tex_pos & (TEXHIE - 1);
		all->ray.tex_pos += all->ray.step;
		all->ray.color = ft_pixel_take(tex, all->ray.tex_x, all->ray.tex_y);
		my_mlx_pixel_put(all, x, y, (int)*(all->ray.color));
		y++;
	}
}
