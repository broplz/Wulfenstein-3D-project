/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:45 by broplz            #+#    #+#             */
/*   Updated: 2021/03/29 04:56:52 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_map_size(t_all *all, t_list *list)
{
	int		i;
	t_list	*head;

	i = 0;
	all->map.len = 0;
	all->map.lst_size = ft_lstsize(list) + 2;
	head = list;
	if (!(all->map.map = ft_calloc(all->map.lst_size + 1, sizeof(char *))))
		return (-1);
	while (list)
	{
		if (all->map.len < ft_strlen((char *)list->content))
			all->map.len = ft_strlen((char *)list->content);
		list = list->next;
	}
	all->map.len += 2;
	while (i < all->map.lst_size)
		if (!(all->map.map[i++] = ft_calloc(all->map.len + 1, sizeof(char))))
			return (-1);
	ft_map_init(all, head, all->map.len, all->map.lst_size);
	return (1);
}
