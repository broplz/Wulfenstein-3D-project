/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_clr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:31:23 by broplz            #+#    #+#             */
/*   Updated: 2021/03/28 23:43:10 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		f_clr(t_all *all, char **line)
{
	int com;

	com = 0;
	if (all->check.f == 1)
		return (-1 + (all->co.pflag = 0) + ft_error_close("Duplicated color"));
	while (*(*line))
	{
		if (*(*line) == ',' && com++ < 3 || *(*line) == ' ')
			(*line)++;
		if (ft_isdigit(*(*line)) == 1 && com == 0)
			all->params.colors.fr = ft_atoi(line);
		if (ft_isdigit(*(*line)) == 1 && com == 1)
			all->params.colors.fg = ft_atoi(line);
		if (ft_isdigit(*(*line)) == 1 && com++ == 2)
			all->params.colors.fb = ft_atoi(line);
		if (com == 3 && (*(*line)) || com > 3)
			ft_error_close("Trash in color param");
	}
	if ((ft_color_check(all->params.colors.fr,
		all->params.colors.fg, all->params.colors.fb)) < 0)
		return (-1 + (all->co.pflag = 0));
	return (all->check.f = 1);
}
