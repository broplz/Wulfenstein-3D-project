/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr_spr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:53:34 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:53:35 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_addr_spr(t_all *all)
{
	all->spr.tex_spr.addr = \
	mlx_get_data_addr(all->spr.tex_spr.img, &all->spr.tex_spr.bpp, \
	&all->spr.tex_spr.ln_len, &all->spr.tex_spr.endian);
}
