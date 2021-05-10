/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_ev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:50:01 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 13:50:03 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			ft_key_ev(t_all *all)
{
	mlx_do_sync(all->data.mlx);
	ft_mv_fwd(all);
	ft_mv_bck(all);
	ft_mv_lft(all);
	ft_mv_rgt(all);
	if (all->keys.rot_lft)
		ft_rot_lft(all);
	if (all->keys.rot_rgt)
		ft_rot_rgt(all);
	if (all->keys.esc)
		exit(1);
	ft_draw(all);
	return (1);
}
