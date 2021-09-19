/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:33:16 by broplz            #+#    #+#             */
/*   Updated: 2021/03/24 00:36:19 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_t_space(char **str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (*str == NULL)
		return (-1);
	while ((*str)[i])
	{
		(*str)[k] = (*str)[i];
		if ((*str)[i] == ' ')
		{
			while ((*str)[i + 1] == ' ')
				i++;
		}
		k++;
		i++;
	}
	(*str)[k] = '\0';
	return (1);
}