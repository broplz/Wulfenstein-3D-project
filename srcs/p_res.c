/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_res.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:33:29 by broplz            #+#    #+#             */
/*   Updated: 2021/03/27 18:28:41 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		p_res(t_all *all, char **line)
{
	if (*(++(*line)) != ' ' || all->check.r == 1)
		return (-1 + (all->co.pflag = 0) + ft_error_close("Invalid res"));
	if (ft_isdigit(*(++(*line))) == 1)
		all->params.res.x = ft_atoi(line);
	else
		return (-1 + (all->co.pflag = 0) + ft_error_close("Invalid res"));
	if (ft_isdigit(*(++(*line))) == 1)
		all->params.res.y = ft_atoi(line);
	else
		return (-1 + (all->co.pflag = 0) + ft_error_close("Invalid res"));
	while (*line && **line == ' ')
		(*line)++;
	if (**line)
		return (-1 + (all->co.pflag = 0) + ft_error_close("Invalid res"));
	if (all->params.res.y < 1 || all->params.res.x < 1)
		return (-1 + (all->co.pflag = 0) + ft_error_close("Invalid res"));
	return (all->check.r = 1);
}
