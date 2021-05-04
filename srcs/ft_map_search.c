/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:41 by broplz            #+#    #+#             */
/*   Updated: 2021/04/22 23:23:37 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_map_search(t_all *all, char *line)
{
	if (!line || *line == '\0')
		return (1);
	while (*line == ' ')
		line++;
	if ((*line) == '1' || (*line) == '\0')
		return (1 + (all->co.pflag = 2) - 2);
	else
		ft_error_close("String with trash before map");
	return  (0);
}
