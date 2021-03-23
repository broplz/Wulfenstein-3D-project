/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:09 by broplz            #+#    #+#             */
/*   Updated: 2021/03/23 22:32:09 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_map_copy(void *head, char *all, int len)
{
	int		i;
	char	*content;

	i = 0;
	content = (char *)head;
	while (i < len)
	{
		if (content && i > 0 && *content)
		{
			all[i++] = *content++;
			continue;
		}
		all[i] = ' ';
		i++;
	}
	return (1);
}
