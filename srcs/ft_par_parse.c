/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_par_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:57 by broplz            #+#    #+#             */
/*   Updated: 2021/04/22 15:27:44 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_par_parse(t_all *all, int fd, t_list **list)
{
	char	*line;
	char	*temp;

	line = NULL;
	temp = NULL;
	while (all->co.pflag && ft_get_valid(all) != 8 && get_next_line(fd, &line)
		&& (temp = line) && ft_param_parser(all, line))
		ft_lstadd_back(list, ft_lstnew(temp));
	if (all->par.col.cb == -1 || all->par.col.cg == -1
		|| all->par.col.cr == -1 || all->par.col.fb == -1
		|| all->par.col.fg == -1 || all->par.col.fr == -1)
		ft_error_close("No color");
	return (1);
}
