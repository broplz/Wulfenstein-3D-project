/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_clr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:16:08 by broplz            #+#    #+#             */
/*   Updated: 2021/03/29 04:56:52 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		ft_valid_clr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'F' || str[i] == 'C' || str[i] == ','
		|| str[i] == ' ' || ft_isdigit(str[i]) == 1)
			;
		else
			ft_error_close("Invalid color params");
		i++;
	}
	return (1);
}
