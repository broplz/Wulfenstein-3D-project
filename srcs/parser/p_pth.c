/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:33:25 by broplz            #+#    #+#             */
/*   Updated: 2021/04/30 09:48:44 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		p_pth(t_all *all, char **line)
{
	int *flag;

	flag = &all->co.par_fl;
	if (line[0][0] == 'W' && line[0][1] == 'E')
		all->par.path.we = w_pth(&(all->che.we), line, flag);
	else if (line[0][0] == 'N' && line[0][1] == 'O')
		all->par.path.no = w_pth(&(all->che.no), line, flag);
	else if (line[0][0] == 'E' && line[0][1] == 'A')
		all->par.path.ea = w_pth(&(all->che.ea), line, flag);
	else if (line[0][0] == 'S' && line[0][1] == 'O')
		all->par.path.so = w_pth(&(all->che.so), line, flag);
	else if (line[0][0] == 'S' && line[0][1] == ' ')
		all->par.path.sp = w_pth(&(all->che.sp), line, flag);
	else
		ft_error_close("Path error");
	return (1);
}
