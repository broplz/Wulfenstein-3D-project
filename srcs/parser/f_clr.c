/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_clr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:31:23 by broplz            #+#    #+#             */
/*   Updated: 2021/05/08 00:38:45 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		f_clr(t_all *all, char **line)
{
	int	com;
	int	dig;

	com = 0;
	dig = 0;
	if (all->che.f == 1)
		return (ft_error_close("Duplicated color"));
	while (*(*line))
	{
		if ((*(*line) == ',' && com++ < 3) || (*(*line) == ' '))
			(*line)++;
		if (ft_isdigit(*(*line)) == 1 && com == 0 && dig++ == 0)
			all->par.col.fr = ft_atoi(line);
		if (ft_isdigit(*(*line)) == 1 && com == 1 && dig++)
			all->par.col.fg = ft_atoi(line);
		if (ft_isdigit(*(*line)) == 1 && com == 2 && dig++)
			all->par.col.fb = ft_atoi(line);
		if ((com == 3 && (*(*line))) || com > 2 || dig > 3)
			ft_error_close("Trash in color param");
	}
	if ((ft_color_check(all->par.col.fr,
						all->par.col.fg, all->par.col.fb)) < 0)
		return (ft_error_close("out of color range"));
	return (all->che.f = 1);
}
