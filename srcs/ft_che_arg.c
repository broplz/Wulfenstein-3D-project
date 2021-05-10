/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_che_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:48:03 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:48:08 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_che_arg(char *line)
{
	size_t i;

	if ((i = ft_strlen(line)) < 4)
		ft_error_close("Wrong format for map");
	if (!(line[i - 1] == 'b' &&
				line[i - 2] == 'u' &&
				line[i - 3] == 'c') &&
			line[i - 4] == '.')
		ft_error_close("Invalid format for map");
}
