/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_spr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:53:39 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:53:40 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_img_spr(t_all *all)
{
	if (!(all->spr.tex_spr.img = \
		mlx_xpm_file_to_image(all->data.mlx, all->par.path.sp, \
		&all->spr_cst.spr_wid, &all->spr_cst.spr_hei)))
		exit(0);
}
