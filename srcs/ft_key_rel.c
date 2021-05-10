/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_rel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:54:32 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:54:33 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_key_rel(int key, t_all *all)
{
	if (key == 13)
		all->keys.mv_fwd = 0;
	if (key == 1)
		all->keys.mv_bck = 0;
	if (key == 0)
		all->keys.mv_lft = 0;
	if (key == 2)
		all->keys.mv_rgt = 0;
	if (key == 123)
		all->keys.rot_lft = 0;
	if (key == 124)
		all->keys.rot_rgt = 0;
	return (0);
}
