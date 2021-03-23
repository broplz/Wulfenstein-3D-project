#include "../include/cub3d.h"

int		ft_map_anal(t_all *all)
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
				printf("Valid =======> ? %d\n", ft_map_hard_anal(all, array, i, j));
				if (ft_map_hard_anal(all, array, i, j) < 1)
					return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
