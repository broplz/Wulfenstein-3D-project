/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:33:06 by broplz            #+#    #+#             */
/*   Updated: 2021/04/22 20:38:18 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_param_parser(t_all *all, char *line)
{
	ft_t_space(&line);
	if (ft_strlen(line) == 1)
		return (-1);
	while (line && *line)
	{
		if (*line == ' ')
			line++;
		else if (*line == 'R')
			return (p_res(all, &line));
		else if (*line == 'F' || *line == 'C')
			return (p_cls(all, &line));
		else if (*line == 'N' || *line == 'W' || *line == 'E' ||
		(*line == 'S' && (*(line + 1) == 'O' || *(line + 1) == ' ')))
			return (p_pth(all, &line));
		else
			ft_error_close("wrong parse parameter");
	}
	return (1);
}
