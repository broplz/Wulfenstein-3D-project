#include "../include/cub3d.h"

int		ft_key_rel(int key, t_all *all)
{
	if (key == 13)
		all->keys.mv_fwd = 0;
	if (key == 1)
		all->keys.mv_bck = 0;
	if (key == 0)
		all->keys.mv_lft = 0;
	if (key == 2)
		all->keys.mv_rgt = 0;
	if (key == 123)
		all->keys.rot_lft = 0;
	if (key == 124)
		all->keys.rot_rgt = 0;
	return (0);
}
