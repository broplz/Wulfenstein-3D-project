/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:31:53 by broplz            #+#    #+#             */
/*   Updated: 2021/03/29 04:56:52 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		ft_get_valid(t_all *all)
{
	return (all->che.sp + all->che.so + all->che.ea + all->che.no +
			all->che.we + all->che.f + all->che.c + all->che.r);
}
