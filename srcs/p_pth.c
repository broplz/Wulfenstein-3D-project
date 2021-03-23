/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:33:25 by broplz            #+#    #+#             */
/*   Updated: 2021/03/23 22:33:25 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		p_pth(t_all *all, char **line)
{
	int *flag;

	flag = &all->co.pflag;
	if (line[0][0] == 'W' && line[0][1] == 'E')
		all->params.path.we = w_pth(&(all->check.we), line, flag);
	else if (line[0][0] == 'N' && line[0][1] == 'O')
		all->params.path.no = w_pth(&(all->check.no), line, flag);
	else if (line[0][0] == 'E' && line[0][1] == 'A')
		all->params.path.ea = w_pth(&(all->check.ea), line, flag);
	else if (line[0][0] == 'S' && line[0][1] == 'O')
		all->params.path.so = w_pth(&(all->check.so), line, flag);
	else if (line[0][0] == 'S' && line[0][1] == ' ')
		all->params.path.sp = w_pth(&(all->check.sp), line, flag);
	else
		return (-1);
	return (1);
}
