/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:41 by broplz            #+#    #+#             */
/*   Updated: 2021/03/28 01:59:10 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_map_search(t_all *all, char *line)
{
	if (!line || *line == '\0')
		return (1);
	while (*line == ' ')
		line++;
	if ((*line) == '1')
		return (1 + (all->co.pflag = 2) - 2);
	else
		return (-1 + (all->co.pflag = -1) + 1 + ft_error_close("No Map"));
}
