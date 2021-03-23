/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:33:21 by broplz            #+#    #+#             */
/*   Updated: 2021/03/23 22:33:21 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		p_cls(t_all *all, char **line)
{
	if (**line == 'F')
	{
		if (*(++(*line)) != ' ')
			return (-1);
		else
		{
			(*line)++;
			return (f_clr(all, line));
		}
	}
	else if (**line == 'C')
	{
		if (*(++(*line)) != ' ')
			return (-1);
		else
		{
			(*line)++;
			return (c_clr(all, line));
		}
	}
	else
		return (-1);
}
