/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_take.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:55:00 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:55:01 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

unsigned int	*ft_pixel_take(t_tex_info *tex, int x, int y)
{
	return ((unsigned int *)(tex->tex.addr + (y * tex->tex.ln_len
	+ x * (tex->tex.bpp / 8))));
}
