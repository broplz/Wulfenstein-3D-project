/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_q_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:56:09 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:56:10 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_q_sort(t_all *all, int first, int last)
{
	int		i;
	int		j;
	int		midlle;

	if (first < last)
	{
		midlle = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (all->spr.arr_spr[i].dist >= all->spr.arr_spr[midlle].dist
				&& i < last)
				i++;
			while (all->spr.arr_spr[j].dist < all->spr.arr_spr[midlle].dist)
				j--;
			if (i < j)
				ft_spr_swp(all, i, j);
		}
		ft_spr_swp(all, midlle, j);
		ft_q_sort(all, j + 1, last);
		ft_q_sort(all, first, j - 1);
	}
}
