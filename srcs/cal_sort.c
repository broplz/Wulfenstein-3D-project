/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 22:13:55 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/09 22:15:04 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cal_sort(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->spr.count)
	{
		all->spr.arr_spr[i].dist = ((all->plr.pos_x - all->spr.arr_spr[i].x)
		* (all->plr.pos_x - all->spr.arr_spr[i].x)
		+ (all->plr.pos_y - all->spr.arr_spr[i].y)
		* (all->plr.pos_y - all->spr.arr_spr[i].y));
		i++;
	}
}
