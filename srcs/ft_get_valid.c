#include "../include/cub3d.h"

int		ft_get_valid(t_all *all)
{
	return (all->check.sp + all->check.so + all->check.ea + all->check.no +
			all->check.we + all->check.f + all->check.c + all->check.r);
}