/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:30:25 by broplz            #+#    #+#             */
/*   Updated: 2021/03/28 01:50:08 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int		main(int argc, char **argv)
{
	t_all	all;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	ft_main_parser(all, fd, argc);
	int a;

	return (0);
}