/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:31:58 by broplz            #+#    #+#             */
/*   Updated: 2021/03/23 23:04:46 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_init_all(t_all *all)
{
	all->check.we = 0;
	all->check.sp = 0;
	all->check.so = 0;
	all->check.ea = 0;
	all->check.no = 0;
	all->check.c = 0;
	all->check.f = 0;
	all->check.r = 0;
	all->params.colors.fb = -1;
	all->params.colors.fg = -1;
	all->params.colors.fr = -1;
	all->params.colors.cr = -1;
	all->params.colors.cg = -1;
	all->params.colors.cb = -1;
	all->params.res.x = 0;
	all->params.res.y = 0;
	all->params.path.no = NULL;
	all->params.path.ea = NULL;
	all->params.path.so = NULL;
	all->params.path.sp = NULL;
	all->params.path.we = NULL;
	all->map.map = NULL;
	all->co.pflag = 1;
	all->co.i = 0;
	all->co.j = 0;
}
