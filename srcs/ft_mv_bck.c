/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_bck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:51:46 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:51:48 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_mv_bck(t_all *all)
{
	if (all->keys.mv_bck)
	{
		if (all->map.map[(int)(all->plr.pos_x - all->plr.dir_x * 0.25)]
			[(int)(all->plr.pos_y)] == '0')
			all->plr.pos_x -= all->plr.dir_x * 0.18;
		if (all->map.map[(int)all->plr.pos_x]
			[(int)(all->plr.pos_y - all->plr.dir_y * 0.25)] == '0')
			all->plr.pos_y -= all->plr.dir_y * 0.18;
	}
}
