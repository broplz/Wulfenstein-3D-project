#include "../include/cub3d.h"

void	ft_all_mlx(t_all *all)
{
	all->data.win = mlx_new_window(all->data.mlx, all->par.res.x, all->par.res.y, "cub3D");
	all->data.img = mlx_new_image(all->data.mlx, all->par.res.x, all->par.res.y);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bpp, &all->data.ln_len, &all->data.endian);
	if (all->co.scr_fl == 1)
		ft_scr_sh(all);
}
