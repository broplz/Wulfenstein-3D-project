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

#include "../../include/cub3d.h"

void	ft_spr_cor(t_all *all, int i, int j)
{
	if (all->map.map[i][j] == '2' && all->spr.count)
	{
		all->spr.arr_spr[all->co.j].x = i + 0.5;
		all->spr.arr_spr[all->co.j++].y = j + 0.5;
	}
}

int		ft_map_anal(t_all *all)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	all->co.j = 0;
	array = all->map.map;
	all->spr.arr_spr = (t_spr *)malloc(all->spr.count * sizeof(t_spr));
	while (i < all->map.lst_size)
	{
		while (j < all->map.len)
		{
			if (array[i][j] == ' ')
			{
				ft_map_hard_anal(all, array, i, j);
			}
			ft_spr_cor(all, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
