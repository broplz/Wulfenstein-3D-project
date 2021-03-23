/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_par_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:57 by broplz            #+#    #+#             */
/*   Updated: 2021/03/24 01:14:00 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_par_parse(t_all *all, int fd, t_list **list)
{
	char	*line;
	char	*temp;

	line = NULL;
	while (all->co.pflag && ft_get_valid(all) != 8 && get_next_line(fd, &line)
		&& (temp = line) && ft_param_parser(all, line))
		ft_lstadd_back(list, ft_lstnew(temp));
	return (1);
}
