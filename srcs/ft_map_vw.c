#include "../include/cub3d.h"

int		ft_map_vw(t_all *all)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	array = all->map.map;
	while (i < all->map.lst_size)
	{
		while (j < all->map.len)
		{
			if (array[i][j] == ' ')
			{
				if (ft_if_def(all, array, i, j) < 1)
					return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
