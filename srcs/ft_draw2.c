/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:48:40 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:48:42 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw2(t_all *all)
{
	if (all->ray.ray_dir_x < 0)
	{
		all->ray.step_x = -1;
		all->ray.side_dist_x = (all->plr.pos_x - all->ray.map_x)
		* all->ray.delta_dist_x;
	}
	else
	{
		all->ray.step_x = 1;
		all->ray.side_dist_x = (all->ray.map_x + 1.0 - all->plr.pos_x)
		* all->ray.delta_dist_x;
	}
	if (all->ray.ray_dir_y < 0)
	{
		all->ray.step_y = -1;
		all->ray.side_dist_y = (all->plr.pos_y - all->ray.map_y) *
		all->ray.delta_dist_y;
	}
	else
	{
		all->ray.step_y = 1;
		all->ray.side_dist_y = (all->ray.map_y + 1.0 - all->plr.pos_y) *
		all->ray.delta_dist_y;
	}
}
