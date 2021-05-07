/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_soft_anal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:51 by broplz            #+#    #+#             */
/*   Updated: 2021/04/15 18:22:33 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_get_ori(t_all *all, char ch)
{
	if (ch == 'W')
		all->co.or = 'W';
	if (ch == 'E')
		all->co.or = 'E';
	if (ch == 'S')
		all->co.or = 'S';
	if (ch == 'N')
		all->co.or = 'N';
}

int		ft_map_soft_anal(t_all *all, char *line, char *head)
{
	char	*right;

	while (*line)
	{
		right = head;
		while (*right && *right != *line)
		{
			if (all->co.anal > 1)
				return (ft_error_close("Invalid map"));
			if (*line == 'N' || *line == 'W' || *line == 'E' || *line == 'S')
			{
				all->co.anal += 1;
				ft_get_ori(all, *line);
				break ;
			}
			right++;
		}
		if (*line == '2')
			all->spr.count++;
		if (*right == '\0')
			return (ft_error_close("Invalid map"));
		line++;
	}
	return (1);
}
