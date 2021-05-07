/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:24:16 by broplz            #+#    #+#             */
/*   Updated: 2021/04/30 09:48:43 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_main_parser(t_all *all, int fd, t_list *par, t_list *map)
{
	ft_par_parse(all, fd, &par);
	if (all->co.pflag)
		ft_map_parse(all, fd, &map);
	ft_pos_finder(all);
	all->par.col.ce = cre_rgb(all->par.col.cr, all->par.col.cg, all->par.col.cb);
	all->par.col.fl = cre_rgb(all->par.col.fr, all->par.col.fg, all->par.col.fb);
	get_textures_info(all);
	get_textures_addr(all);

	get_img_spr(all);
	get_addr_spr(all);
	all->ray.z_buf = (double *)malloc(W * sizeof(double));

	ft_free_all(NULL, &map, &par);
	return (1);
}