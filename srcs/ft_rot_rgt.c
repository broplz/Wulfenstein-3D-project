/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_rgt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:53:56 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:53:57 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_rot_rgt(t_all *all)
{
	all->ray.old_dir_x = all->plr.dir_x;
	all->plr.dir_x = all->plr.dir_x * cos(-0.05)
	- all->plr.dir_y * sin(-0.05);
	all->plr.dir_y = all->ray.old_dir_x * sin(-0.05)
	+ all->plr.dir_y * cos(-0.05);
	all->ray.old_plane_x = all->plr.plane_x;
	all->plr.plane_x = all->plr.plane_x * cos(-0.05)
	- all->plr.plane_y * sin(-0.05);
	all->plr.plane_y = all->ray.old_plane_x * sin(-0.05)
	+ all->plr.plane_y * cos(-0.05);
}
