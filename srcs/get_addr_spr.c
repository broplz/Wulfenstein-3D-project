#include "../include/cub3d.h"

void get_addr_spr(t_all *all)
{
	all->spr.tex_spr.addr = \
 mlx_get_data_addr(all->spr.tex_spr.img, &all->spr.tex_spr.bpp, \
 &all->spr.tex_spr.ln_len, &all->spr.tex_spr.endian);
}
