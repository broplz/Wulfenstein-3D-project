/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:24:16 by broplz            #+#    #+#             */
/*   Updated: 2021/04/22 19:37:06 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_main_parser(t_all *all, int fd, int argc, t_list *par, t_list *map)
{
	ft_par_parse(all, fd, &par);
	if (all->co.pflag)
		ft_map_parse(all, fd, &map);
	ft_free_all(NULL, &map, &par);
	return (1);
}