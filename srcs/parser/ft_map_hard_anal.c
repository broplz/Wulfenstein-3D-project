/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_hard_anal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:32:17 by broplz            #+#    #+#             */
/*   Updated: 2021/03/29 04:56:52 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_map_hard_anal(t_all *all, char **array, int i, int j)
{
	if (i != 0 && j != 0 && !(array[i - 1][j - 1] == ' '
	|| array[i - 1][j - 1] == '1' || array[i - 1][j - 1] == '\0'))
		ft_error_close("Invalid map");
	if (i != 0 && !(array[i - 1][j] == ' '
	|| array[i - 1][j] == '1' || array[i - 1][j] == '\0'))
		ft_error_close("Invalid map");
	if (i != 0 && !(array[i - 1][j + 1] == ' '
	|| array[i - 1][j + 1] == '1' || array[i - 1][j + 1] == '\0'))
		ft_error_close("Invalid map");
	if (j != 0 && !(array[i][j - 1] == ' '
	|| array[i][j - 1] == '1' || array[i][j - 1] == '\0'))
		ft_error_close("Invalid map");
	if (!(array[i][j + 1] == ' ' || array[i][j + 1] == '1'
	|| array[i][j + 1] == '\0'))
		ft_error_close("Invalid map");
	if (i != all->map.lst_size - 1 && j != 0
	&& !(array[i + 1][j - 1] == ' ' || array[i + 1][j - 1] == '1'
	|| array[i + 1][j - 1] == '\0'))
		ft_error_close("Invalid map");
	if (i != all->map.lst_size - 1 && !(array[i + 1][j] == ' '
	|| array[i + 1][j] == '1' || array[i + 1][j] == '\0'))
		ft_error_close("Invalid map");
	if (i != all->map.lst_size - 1 && !(array[i + 1][j + 1] == ' '
	|| array[i + 1][j + 1] == '1' || array[i + 1][j + 1] == '\0'))
		ft_error_close("Invalid map");
}
