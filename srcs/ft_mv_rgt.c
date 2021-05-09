#include "../include/cub3d.h"

void	ft_mv_rgt(t_all *all)
{
	if (all->keys.mv_rgt)
	{
		if (all->map.map[(int) (all->plr.pos_x + all->plr.dir_y * 0.1)]
			[(int) all->plr.pos_y] == '0')
			all->plr.pos_x += all->plr.dir_y * 0.051;
		if (all->map.map[(int) all->plr.pos_x]
			[(int) (all->plr.pos_y - all->plr.dir_x * 0.1)] == '0')
			all->plr.pos_y -= all->plr.dir_x * 0.051;
	}
}