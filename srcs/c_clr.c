/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_clr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:31:17 by broplz            #+#    #+#             */
/*   Updated: 2021/04/13 20:41:03 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		c_clr(t_all *all, char **line)
{
	int com;
	int	dig;

	com = 0;
	dig = 0;
	if (all->check.c == 1)
		return (ft_error_close("Duplicated color exception"));
	while (*(*line))
	{
		if ((*(*line) == ',' && com++ < 3) || (*(*line) == ' '))
			(*line)++;
		if (ft_isdigit(*(*line)) == 1 && com == 0 && dig++ == 0)
			all->params.colors.cr = ft_atoi(line);
		if (ft_isdigit(*(*line)) == 1 && com == 1 && dig++)
			all->params.colors.cg = ft_atoi(line);
		if (ft_isdigit(*(*line)) == 1 && com == 2 && dig++)
			all->params.colors.cb = ft_atoi(line);
		if (com == 3 && (*(*line)) || com > 3 || dig > 3)
			ft_error_close("Trash in color param exception");
	}
	if ((ft_color_check(all->params.colors.cr,
		all->params.colors.cg, all->params.colors.cb)) < 0)
		return (ft_error_close("out of color range exception"));
	return (all->check.c = 1);
}
