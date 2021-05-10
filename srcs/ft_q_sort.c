#include "../include/cub3d.h"

void		ft_q_sort(t_all *all, int first, int last)
{
	int		i;
	int		j;
	int		midlle;

	if (first < last)
	{
		midlle = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (all->spr.arr_spr[i].dist >= all->spr.arr_spr[midlle].dist
				&& i < last)
				i++;
			while (all->spr.arr_spr[j].dist < all->spr.arr_spr[midlle].dist)
				j--;
			if (i < j)
				ft_spr_swp(all, i, j);
		}
		ft_spr_swp(all, midlle, j);
		ft_q_sort(all, j + 1, last);
		ft_q_sort(all, first, j - 1);
	}
}
