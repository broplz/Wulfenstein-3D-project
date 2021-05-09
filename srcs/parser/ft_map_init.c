/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:28 by broplz            #+#    #+#             */
/*   Updated: 2021/03/29 04:56:52 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		ft_map_init(t_all *all, t_list *list, int len, int lst_size)
{
	int	i;

	i = 0;
	while (i < lst_size - 1)
	{
		if (i == 0)
			ft_map_copy(NULL, all->map.map[i], len);
		else
		{
			if (list)
			{
				ft_map_copy(list->content, all->map.map[i], len);
				list = list->next;
			}
		}
		i++;
	}
	ft_map_copy(NULL, all->map.map[i], len);
	return (1);
}
