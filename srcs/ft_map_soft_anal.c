/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_soft_anal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:51 by broplz            #+#    #+#             */
/*   Updated: 2021/03/24 01:36:06 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_map_soft_anal(char *line, char *head)
{
	static int		anal;
	char			*right;

	anal = 0;
	while (*line)
	{
		right = head;
		while (*right && *right != *line)
		{
			if (anal > 1)
				return (0);
			if (*line == 'N' || *line == 'W' || *line == 'E' || *line == 'S')
			{
				anal += 1;
				break ;
			}
			right++;
		}
		if (*right == '\0')
			return (0);
		line++;
	}
	return (1);
}
