/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:56:19 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:56:29 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->data.addr + (y * all->data.ln_len + x * (all->data.bpp / 8));
	*(unsigned int*)dst = color;
}
