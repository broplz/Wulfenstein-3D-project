#include "../include/cub3d.h"

void	ft_draw4(t_all *all, int x)
{
	ft_draw3(all, x);
	if (all->ray.side == 0)
		all->ray.perp_wall_dist = (all->ray.map_x - all->plr.pos_x +
								   (1.0 - (double) all->ray.step_x) / 2) /
								  all->ray.ray_dir_x;
	else
		all->ray.perp_wall_dist = (all->ray.map_y - all->plr.pos_y +
								   (1.0 - (double) all->ray.step_y) / 2) /
								  all->ray.ray_dir_y;
	all->ray.z_buf[x] = all->ray.perp_wall_dist;
	all->ray.line_height = (int) (H / all->ray.perp_wall_dist);
	all->ray.draw_start = -all->ray.line_height / 2 + H / 2;
	if (all->ray.draw_start < 0) all->ray.draw_start = 0;
	all->ray.draw_end = all->ray.line_height / 2 + H / 2;
	if (all->ray.draw_end >= H)
		all->ray.draw_end = H;
	all->ray.tex_num =
			WWORLDMAP[all->ray.map_x][all->ray.map_y] - 1;
	if (all->ray.side == 0)
		all->ray.wall_x = all->plr.pos_y + all->ray.perp_wall_dist *
										   all->ray.ray_dir_y;
	else
		all->ray.wall_x = all->plr.pos_x + all->ray.perp_wall_dist *
										   all->ray.ray_dir_x;
}
