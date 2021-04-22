/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_res.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:33:29 by broplz            #+#    #+#             */
/*   Updated: 2021/04/22 21:22:34 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		p_res(t_all *all, char **line)
{
	if (*(++(*line)) == ' ' && all->check.r != 1)
	{
		if (ft_isdigit(*(++(*line))))
		{
			// TODO add new if() with W > MAX_LONG || W < MIN_LONG
			W = ft_atol(line);
			if (ft_isdigit(*(++(*line))))
				H = ft_atol(line);
			if (*line && **line == ' ')
				(*line)++;
		}
		if (H < 1 || W < 1 || **line)
			ft_error_close("Invalid resolution");
	}
	else
		ft_error_close("Resolution duplicated");
	all->check.r = 1;
}
