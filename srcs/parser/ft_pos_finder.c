#include "../../include/cub3d.h"

void	ft_orient_es(t_all *all)
{
	if (all->co.or == 'E')
	{
		all->plr.dir_x = 0.0;
		all->plr.dir_y = 1.0;
		all->plr.plane_x = 0.66;
		all->plr.plane_y = 0.0;
	}
	if (all->co.or == 'S')
	{
		all->plr.dir_x = 1.0;
		all->plr.dir_y = 0.0;
		all->plr.plane_x = 0.0;
		all->plr.plane_y = -0.66;
	}
}

void	ft_orient_nw(t_all *all)
{
	if (all->co.or == 'N')
	{
		all->plr.dir_x = -1.0;
		all->plr.dir_y = 0.0;
		all->plr.plane_x = 0.0;
		all->plr.plane_y = 0.66;
	}
	if (all->co.or == 'W')
	{
		all->plr.dir_x = 0.0;
		all->plr.dir_y = -1.0;
		all->plr.plane_x = -0.66;
		all->plr.plane_y = 0.0;
	}
	ft_orient_es(all);
}

int		ft_pos_finder(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all->map.lst_size)
	{
		while (j < all->map.len)
		{
			if (WWORLDMAP[i][j] == 'W' ||
				WWORLDMAP[i][j] == 'E' ||
				WWORLDMAP[i][j] == 'S' ||
				WWORLDMAP[i][j] == 'N')
			{
				all->plr.pos_x = i + 0.5;
				all->plr.pos_y = j + 0.5;
				all->map.map[i][j] = '0';
			}
			j++;
		}
		j = 0;
		i++;
	}
	ft_orient_nw(all);
	return (0);
}
