/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:35 by broplz            #+#    #+#             */
/*   Updated: 2021/03/28 23:19:18 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_map_parse(t_all *all, int fd, t_list **list)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line) && (ft_map_search(all, line) > 0))
	{
		if (!(ft_map_soft_anal(all, line, " 012WESN\0")))
			return (all->co.pflag = 0);
		if (all->co.pflag == 2)
			ft_lstadd_back(list, ft_lstnew(line));
		else
			ft_free_line(&line);
	}
	if (all->co.pflag == 2)
		ft_lstadd_back(list, ft_lstnew(line));
	else if (line)
		ft_free_line(&line);
	ft_map_size(all, *list);
	ft_map_anal(all);
	return (1);
}
