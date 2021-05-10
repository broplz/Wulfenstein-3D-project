/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:48:55 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:48:57 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw3(t_all *all, int x)
{
	ft_draw1(all, x);
	all->ray.hit = 0;
	all->ray.side_dist_x = 0;
	ft_draw2(all);
	while (all->ray.hit == 0)
	{
		if (all->ray.side_dist_x < all->ray.side_dist_y)
		{
			all->ray.side_dist_x += all->ray.delta_dist_x;
			all->ray.map_x += all->ray.step_x;
			all->ray.side = 0;
		}
		else
		{
			all->ray.side_dist_y += all->ray.delta_dist_y;
			all->ray.map_y += all->ray.step_y;
			all->ray.side = 1;
		}
		if (WWORLDMAP[all->ray.map_x][all->ray.map_y] == '1')
			all->ray.hit = 1;
	}
}
