/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_spr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:53:26 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:53:29 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_spr_util(t_all *all, int y, int v_mv_scr, int stripe)
{
	if (all->spr_cst.tfm_y > 0 && stripe >= 0 && stripe <=
		W && all->spr_cst.tfm_y < all->ray.z_buf[stripe])
	{
		y = all->spr_cst.draw_start_y;
		ft_draw_spr2(all, y, v_mv_scr, stripe);
	}
}

void	ft_draw_spr(t_all *all)
{
	int	v_mv_scr;
	int	i;
	int	y;
	int	stripe;

	i = 0;
	y = 0;
	v_mv_scr = 0;
	cal_sort(all);
	ft_q_sort(all, 0, all->spr.count - 1);
	while (i < all->spr.count)
	{
		ft_draw_spr1(all, v_mv_scr, i);
		stripe = all->spr_cst.draw_start_x;
		while (stripe < all->spr_cst.draw_end_x)
		{
			all->spr_cst.tex_x = (int)(256 * (stripe -
					(-all->spr_cst.spr_wid / 2 + all->spr_cst.spr_scr_x))
							* TEXWID / all->spr_cst.spr_wid) / 256;
			ft_draw_spr_util(all, y, v_mv_scr, stripe);
			stripe++;
		}
		i++;
	}
}
