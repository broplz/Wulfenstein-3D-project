/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_anal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:03 by broplz            #+#    #+#             */
/*   Updated: 2021/03/29 04:56:52 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_map_anal(t_all *all)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	array = all->map.map;
	while (i < all->map.lst_size)
	{
		while (j < all->map.len)
		{
			if (array[i][j] == ' ')
			{
				if (ft_map_hard_anal(all, array, i, j) < 1)
					return (-1 + ft_error_close("Invalid map"));
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
