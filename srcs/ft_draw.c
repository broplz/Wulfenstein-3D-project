#include "../include/cub3d.h"

void	ft_draw(t_all *all)
{
	int x;
	int y;

	x = -1;
	ft_fl_ce_cst(all);
	while (++x < W)
	{
		ft_draw4(all, x);
		all->ray.wall_x -= floor((all->ray.wall_x));
		all->ray.tex_x = (int) (all->ray.wall_x * (double) (TEXWID));
		if (all->ray.side == 0 && all->ray.ray_dir_x > 0)
			all->ray.tex_x = TEXWID - all->ray.tex_x - 1;
		if (all->ray.side == 1 && all->ray.ray_dir_y < 0)
			all->ray.tex_x = TEXWID - all->ray.tex_x - 1;
		all->ray.step = 1.0 * TEXHIE / all->ray.line_height;
		all->ray.tex_pos = (all->ray.draw_start - (double) H / 2 +
							(double) all->ray
									.line_height / 2) * all->ray.step;
		y = all->ray.draw_start;
		ft_draw5(all, x, y);
	}
	ft_draw_spr(all);
	mlx_put_image_to_window(all->data.mlx, all->data.win, all->data.img,
							0, 0);
}
