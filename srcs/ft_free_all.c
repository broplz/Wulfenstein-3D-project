#include "../include/cub3d.h"

void	ft_free_all(t_all all, t_list *map, t_list *params)
{
	if (params)
		ft_free_mem(&params);
	if (map)
		ft_free_mem(&map);
	while (all.co.pflag && all.co.i < all.map.lst_size)
		free(all.map.map[all.co.i++]);
	free(all.map.map);
}