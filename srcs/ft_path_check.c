/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:33:11 by broplz            #+#    #+#             */
/*   Updated: 2021/03/23 22:33:11 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_path_check(char *line)
{
	int fd;

	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (1);
}
