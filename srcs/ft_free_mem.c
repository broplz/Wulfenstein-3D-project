/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:31:43 by broplz            #+#    #+#             */
/*   Updated: 2021/03/23 23:04:46 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_free_mem(t_list **list)
{
	t_list	*temp;

	if (list == NULL)
		return (-1);
	while ((*list)->content && (*list)->next)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp->content);
		free(temp);
	}
	if ((*list)->content)
		free((*list)->content);
	free(*list);
	return (1);
}
