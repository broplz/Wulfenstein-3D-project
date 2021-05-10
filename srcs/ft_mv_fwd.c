#include "../include/cub3d.h"

void	ft_mv_fwd(t_all *all)
{
	if (all->keys.mv_fwd)
	{
		if (all->map.map[(int)(all->plr.pos_x + all->plr.dir_x * 0.25)]
			[(int)(all->plr.pos_y)] == '0')
			all->plr.pos_x += all->plr.dir_x * 0.18;
		if (all->map.map[(int)all->plr.pos_x]
			[(int)(all->plr.pos_y + all->plr.dir_y * 0.25)] == '0')
			all->plr.pos_y += all->plr.dir_y * 0.18;
	}
}
