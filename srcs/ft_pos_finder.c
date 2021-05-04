#include "../include/cub3d.h"

int		ft_pos_finder(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (WWORLDMAP[i])
	{
		while (WWORLDMAP[i][j])
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

	if (all->co.or == 'N')
	{
		all->plr.dir_x = -1;
		all->plr.dir_y = 0;
		all->plr.plane_x = 0;
		all->plr.plane_y = -0.66;
	}
	if (all->co.or == 'W')
	{
		all->plr.dir_x = 0;
		all->plr.dir_y = -1;
		all->plr.plane_x = -0.66;
		all->plr.plane_y = 0;
	}
	if (all->co.or == 'E')
	{
		all->plr.dir_x = 0;
		all->plr.dir_y = 1;
		all->plr.plane_x = 0.66;
		all->plr.plane_y = 0;
	}
	if (all->co.or == 'S')
	{
		all->plr.dir_x = 1;
		all->plr.dir_y = 0;
		all->plr.plane_x = 0;
		all->plr.plane_y = -0.66;
	}
	return (0);
}