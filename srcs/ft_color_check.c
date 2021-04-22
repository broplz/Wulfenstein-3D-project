/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:31:29 by broplz            #+#    #+#             */
/*   Updated: 2021/03/29 04:56:52 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_color_check(int r, int g, int b)
{
	if (!(r > -1 && r < 256))
		return (-1 + ft_error_close("R is bigger than 255"));
	if (!(g > -1 && g < 256))
		return (-1 + ft_error_close("G is bigger than 255"));
	if (!(b > -1 && b < 256))
		return (-1 + ft_error_close("B is bigger than 255"));
	return (1);
}
