/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:30:25 by broplz            #+#    #+#             */
/*   Updated: 2021/05/10 13:53:05 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		main(int argc, char **argv)
{
	t_all	all;
	int		fd;

	if (argc < 2)
		ft_error_close("No args\n");
	fd = open(argv[1], O_RDONLY);
	ft_che_arg(argv[1]);
	ft_init_all(&all);
	all.data.mlx = mlx_init();
	ft_main_parser(&all, fd, PAR, MAP);
	close(fd);
	ft_key_init(&all);
	if (ft_strlen(argv[2]) == 6 && ft_strncmp("--save", argv[2], 6) == 0)
		all.co.scr_fl = 1;
	else if (argc >= 3)
		ft_error_close("wrong args");
	ft_get_scr(&all);
	ft_all_mlx(&all);
	mlx_hook(all.data.win, 2, (1L << 0), &ft_key_prs, &all);
	mlx_hook(all.data.win, 3, (1L << 1), &ft_key_rel, &all);
	mlx_hook(all.data.win, 17, 0, &ft_shut_down, &all);
	mlx_loop_hook(all.data.mlx, &ft_key_ev, &all);
	mlx_loop(all.data.mlx);
	return (0);
}
