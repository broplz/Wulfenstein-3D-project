/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_take_spr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:55:22 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:55:23 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

unsigned int	*ft_pixel_take_spr(t_tex tex, int x, int y)
{
	return ((unsigned int *)(tex.addr + (y * tex.ln_len + x * (tex.bpp / 8))));
}
