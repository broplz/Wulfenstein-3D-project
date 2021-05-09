#include "../include/cub3d.h"

void		cal_sort(t_all *all)
{
	for(int i = 0; i < all->spr.count; i++)
	{
		all->spr.arr_spr[i].dist = ((all->plr.pos_x - all->spr.arr_spr[i].x)
									* (all->plr.pos_x - all->spr.arr_spr[i].x)
									+ (all->plr.pos_y - all->spr.arr_spr[i].y)
									  * (all->plr.pos_y - all->spr.arr_spr[i].y));
	}
}
