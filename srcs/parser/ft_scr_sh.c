/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scr_sh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 00:05:36 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/08 03:07:05 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_bmp_inf(int fd, t_all *all)
{
	unsigned char	bmp_inf[40];

	ft_bzero(bmp_inf, 40);
	bmp_inf[0] = (unsigned char)(40);
	bmp_inf[4] = (unsigned char)(all->par.res.x);
	bmp_inf[5] = (unsigned char)(all->par.res.x >> 8);
	bmp_inf[6] = (unsigned char)(all->par.res.x >> 16);
	bmp_inf[7] = (unsigned char)(all->par.res.x >> 24);
	bmp_inf[8] = (unsigned char)(all->par.res.y);
	bmp_inf[9] = (unsigned char)(all->par.res.y >> 8);
	bmp_inf[10] = (unsigned char)(all->par.res.y >> 16);
	bmp_inf[11] = (unsigned char)(all->par.res.y >> 24);
	bmp_inf[12] = (unsigned char)(1);
	bmp_inf[14] = (unsigned char)(32);
	write(fd, bmp_inf, 40);
}

void	ft_hdr_bmp(int fd, int f_size)
{
	unsigned char	hdr[14];

	ft_bzero(hdr, 14);
	hdr[0] = (unsigned char)('B');
	hdr[1] = (unsigned char)('M');
	hdr[2] = (unsigned char)(f_size);
	hdr[3] = (unsigned char)(f_size >> 8);
	hdr[4] = (unsigned char)(f_size >> 16);
	hdr[5] = (unsigned char)(f_size >> 24);
	hdr[10] = (unsigned char)(54);
	write(fd, hdr, 14);
}

void	ft_scr_sh(t_all *all)
{
	int	fd;
	int	f_size;
	int	hei;
	int	l_len;

	fd = open("scr.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0655);
	if (fd < 0)
		ft_put_error("Invalid .bmp file");
	ft_draw(all);
	f_size = 14 + 40 + (4 * all->par.res.y * all->par.res.x);
	ft_hdr_bmp(fd, f_size);
	ft_bmp_inf(fd, all);
	hei = all->par.res.y;
	l_len = all->par.res.x * all->data.bpp / 8;
	while (hei > -1)
	{
		write(fd, (unsigned char *)(all->data.addr + hei * all->data.ln_len),
		l_len);
		hei--;
	}
	close(fd);
	ft_shut_down();
}
