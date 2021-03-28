/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_soft_anal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:51 by broplz            #+#    #+#             */
/*   Updated: 2021/03/27 21:16:00 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_map_soft_anal(t_all *all, char *line, char *head)
{
	char	*right;

	while (*line)
	{
		right = head;
		while (*right && *right != *line)
		{
			if (all->co.anal > 1)
				return (0 + ft_error_close("Invalid map"));
			if (*line == 'N' || *line == 'W' || *line == 'E' || *line == 'S')
			{
				all->co.anal += 1;
				break ;
			}
			right++;
		}
		if (*right == '\0')
			return (0 + ft_error_close("Invalid map"));
		line++;
	}
	return (1);
}
