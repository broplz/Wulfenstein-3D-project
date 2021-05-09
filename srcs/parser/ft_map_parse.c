/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:35 by broplz            #+#    #+#             */
/*   Updated: 2021/04/22 23:33:32 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_sanya(t_all *all, char *line)
{
	if (*line == '\0' && all->co.map_fl == 1)
	{
		ft_error_close("grob grob kladbishe igor!");
	}
}

int	ft_map_parse(t_all *all, int fd, t_list **list)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line) && (ft_map_search(all, line) > 0))
	{
		ft_sanya(all, line);
		if (!(ft_map_soft_anal(all, line, " 012WESN\0")))
			return (all->co.par_fl = 0);
		if (all->co.par_fl == 2)
			ft_lstadd_back(list, ft_lstnew(line));
		else
			ft_free_line(&line);
	}
	if (all->co.par_fl == 2)
		ft_lstadd_back(list, ft_lstnew(line));
	else if (line)
		ft_free_line(&line);

	if (all->co.anal == 0)
		ft_error_close("add Player and Direction");
	if (all->spr.count && !(all->spr.arr_spr =
			(t_spr *)malloc(all->spr.count * sizeof(t_spr))))
		ft_error_close("Malloc error");
	ft_map_size(all, *list);
	ft_map_anal(all);
	return (1);
}
