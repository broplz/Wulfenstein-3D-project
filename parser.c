/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:30:25 by broplz            #+#    #+#             */
/*   Updated: 2021/03/27 13:10:09 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"
#include <stdio.h> // TODO НЕ ЗАБЫТЬ УДАЛИТЬ ЭТУ СТРОЧКУ

int		main(int argc, char **argv)
{
	t_all	all;
	int		fd;
	t_list *params;
	t_list *map;

	params = NULL;
	map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc == 1)
		ft_error_close("Feed me with map");
	ft_init_all(&all);
	ft_par_parse(&all, fd, &params);
	if (all.co.pflag)
		ft_map_parse(&all, fd, &map);

	int debug_stop; // TODO УДАЛИТЬ СТРОЧКУ ПОСЛЕ ВСЕХ ДЕЙСТВИЙ
	for(int i = 0; all.co.pflag && i < all.map.lst_size; i++)
	{
		for (int j = 0; j < all.map.len; j++)
			printf("%c", all.map.map[i][j]);
		printf("\n");
	}
	ft_free_all(all, &map, &params);
	return (0);
}