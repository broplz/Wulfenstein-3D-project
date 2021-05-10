/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:49:08 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:49:10 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw1(t_all *all, int x)
{
	all->ray.camera_x = 2 * x / (double)W - 1;
	all->ray.ray_dir_x = all->plr.dir_x + all->plr.plane_x * all->ray.camera_x;
	all->ray.ray_dir_y = all->plr.dir_y + all->plr.plane_y * all->ray.camera_x;
	all->ray.map_x = (int)(all->plr.pos_x);
	all->ray.map_y = (int)(all->plr.pos_y);
	ft_draw_util(all);
}
