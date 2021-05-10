/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:51:18 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:51:19 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_util(t_all *all)
{
	if (all->ray.ray_dir_y == 0)
		all->ray.delta_dist_x = 0;
	else
	{
		if (all->ray.ray_dir_x == 0)
			all->ray.delta_dist_x = 1;
		else
			all->ray.delta_dist_x = fabs(1 / all->ray.ray_dir_x);
	}
	if (all->ray.ray_dir_x == 0)
		all->ray.delta_dist_y = 0;
	else
	{
		if (all->ray.ray_dir_y == 0)
			all->ray.delta_dist_y = 1;
		else
			all->ray.delta_dist_y = fabs(1 / all->ray.ray_dir_y);
	}
}
