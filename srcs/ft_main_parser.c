/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:24:16 by broplz            #+#    #+#             */
/*   Updated: 2021/03/28 23:24:16 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_main_parser(t_all all, int fd, int argc)
{
	t_list *params;
	t_list *map;

	params = NULL;
	map = NULL;

	if (argc == 1)
		ft_error_close("Feed me with map");
	ft_init_all(&all);
	ft_par_parse(&all, fd, &params);
	if (all.co.pflag)
		ft_map_parse(&all, fd, &map);

	for (int i = 0; i < ft_lstsize(map); i++) {
		printf("%s\n", all.map.map[i]);
	}
	printf("%s\n", all.map.map[ft_lstsize(map)]);
	ft_free_all(all, &map, &params);
	return (0);
}