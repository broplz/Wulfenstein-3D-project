/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_spr1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:43:56 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:43:58 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_spr1(t_all *all, int v_mv_scr, int i)
{
	ft_draw_spr3(all, i);
	v_mv_scr = (int)V_MOVE / all->spr_cst.tfm_y;
	all->spr_cst.spr_hei = abs((int)(H / (all->spr_cst.tfm_y))) / V_DIV;
	all->spr_cst.draw_start_y = -all->spr_cst.spr_hei / 2 + H / 2 + v_mv_scr;
	if (all->spr_cst.draw_start_y < 0)
		all->spr_cst.draw_start_y = 0;
	all->spr_cst.draw_end_y = all->spr_cst.spr_hei / 2 + H / 2 + v_mv_scr;
	if (all->spr_cst.draw_end_y >= H)
		all->spr_cst.draw_end_y = H;
	all->spr_cst.spr_wid = abs((int)(W / (all->spr_cst.tfm_y))) / U_DIV;
	all->spr_cst.draw_start_x = -all->spr_cst.spr_wid / 2 +
	all->spr_cst.spr_scr_x;
	if (all->spr_cst.draw_start_x < 0)
		all->spr_cst.draw_start_x = 0;
	all->spr_cst.draw_end_x = all->spr_cst.spr_wid / 2 +
	all->spr_cst.spr_scr_x;
	if (all->spr_cst.draw_end_x >= W)
		all->spr_cst.draw_end_x = W;
}
