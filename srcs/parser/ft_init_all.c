/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:31:58 by broplz            #+#    #+#             */
/*   Updated: 2021/05/08 02:45:24 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_init_str(t_all *all)
{
	all->par.path.no = NULL;
	all->par.path.ea = NULL;
	all->par.path.so = NULL;
	all->par.path.sp = NULL;
	all->par.path.we = NULL;
	all->map.map = NULL;
	all->par.map = NULL;
	all->par.par = NULL;
}

void	ft_init_all(t_all *all)
{
	ft_init_str(all);
	all->che.we = 0;
	all->che.sp = 0;
	all->che.so = 0;
	all->che.ea = 0;
	all->che.no = 0;
	all->che.c = 0;
	all->che.f = 0;
	all->che.r = 0;
	all->par.col.fb = -1;
	all->par.col.fg = -1;
	all->par.col.fr = -1;
	all->par.col.cr = -1;
	all->par.col.cg = -1;
	all->par.col.cb = -1;
	all->par.res.x = 0;
	all->par.res.y = 0;
	all->co.i = 0;
	all->co.j = 0;
	all->co.anal = 0;
	all->spr.count = 0;
	all->co.par_fl = 1;
	all->co.map_fl = 0;
	all->co.scr_fl = 0;
}
