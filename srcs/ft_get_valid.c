/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:31:53 by broplz            #+#    #+#             */
/*   Updated: 2021/03/23 23:18:44 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_get_valid(t_all *all)
{
	return (all->check.sp + all->check.so + all->check.ea + all->check.no +
			all->check.we + all->check.f + all->check.c + all->check.r);
}
