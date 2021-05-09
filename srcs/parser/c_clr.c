/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_clr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:31:17 by broplz            #+#    #+#             */
/*   Updated: 2021/05/08 00:38:45 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		c_clr(t_all *all, char **line)
{
	int com;
	int	dig;

	com = 0;
	dig = 0;
	if (all->che.c == 1)
		return (ft_error_close("Duplicated color"));
	while (*(*line))
	{
		if ((*(*line) == ',' && com++ < 3) || (*(*line) == ' '))
			(*line)++;
		if (ft_isdigit(*(*line)) == 1 && com == 0 && dig++ == 0)
			all->par.col.cr = ft_atoi(line);
		if (ft_isdigit(*(*line)) == 1 && com == 1 && dig++)
			all->par.col.cg = ft_atoi(line);
		if (ft_isdigit(*(*line)) == 1 && com == 2 && dig++)
			all->par.col.cb = ft_atoi(line);
		if ((com == 3 && (*(*line))) || com > 2 || dig > 3)
			ft_error_close("Trash in color param");
	}
	if ((ft_color_check(all->par.col.cr,
						all->par.col.cg, all->par.col.cb)) < 0)
		return (ft_error_close("out of color range"));
	return (all->che.c = 1);
}
