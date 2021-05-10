/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_prs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:51:36 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:51:37 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_key_prs(int key, t_all *all)
{
	if (key == 13)
		all->keys.mv_fwd = 1;
	if (key == 1)
		all->keys.mv_bck = 1;
	if (key == 0)
		all->keys.mv_lft = 1;
	if (key == 2)
		all->keys.mv_rgt = 1;
	if (key == 123)
		all->keys.rot_lft = 1;
	if (key == 124)
		all->keys.rot_rgt = 1;
	if (key == 53)
		ft_shut_down();
	return (0);
}
