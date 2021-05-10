/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:51:28 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:51:29 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_key_init(t_all *all)
{
	all->keys.mv_bck = 0;
	all->keys.mv_fwd = 0;
	all->keys.mv_lft = 0;
	all->keys.mv_rgt = 0;
	all->keys.rot_lft = 0;
	all->keys.rot_rgt = 0;
	all->keys.esc = 0;
}
