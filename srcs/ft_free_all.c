/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:31:38 by broplz            #+#    #+#             */
/*   Updated: 2021/04/22 16:19:23 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free_all(t_all *all, t_list **map, t_list **params)//t_all *all, t_list **map, t_list **params)
{
	if (params)
		ft_free_mem(params);
	if (map)
		ft_free_mem(map);
	if (all)
	{
		while (all->co.pflag && all->co.i < all->map.lst_size)
			free(all->map.map[all->co.i++]);
		free(all->map.map);
	}
}
