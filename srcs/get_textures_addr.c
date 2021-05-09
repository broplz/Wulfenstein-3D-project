#include "../include/cub3d.h"

void 		get_textures_addr(t_all *all)
{
	all->tex.no.tex.addr = mlx_get_data_addr(all->tex.no.tex.img, &all->tex.no.tex.bpp, &all->tex.no.tex.ln_len, &all->tex.no.tex.endian);
	all->tex.so.tex.addr = mlx_get_data_addr(all->tex.so.tex.img, &all->tex.so.tex.bpp, &all->tex.so.tex.ln_len, &all->tex.so.tex.endian);
	all->tex.we.tex.addr = mlx_get_data_addr(all->tex.we.tex.img, &all->tex.we.tex.bpp, &all->tex.we.tex.ln_len, &all->tex.we.tex.endian);
	all->tex.ea.tex.addr = mlx_get_data_addr(all->tex.ea.tex.img, &all->tex.ea.tex.bpp, &all->tex.ea.tex.ln_len, &all->tex.ea.tex.endian);
}
