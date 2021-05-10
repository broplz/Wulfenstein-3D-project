#include "../include/cub3d.h"

void	get_textures_info(t_all *all)
{
	all->tex.no.tex.img = mlx_xpm_file_to_image(all->data.mlx, all->par.path.no,
	&all->tex.no.width, &all->tex.no.height);
	all->tex.so.tex.img = mlx_xpm_file_to_image(all->data.mlx, all->par.path.so,
	&all->tex.so.width, &all->tex.so.height);
	all->tex.we.tex.img = mlx_xpm_file_to_image(all->data.mlx, all->par.path.we,
	&all->tex.we.width, &all->tex.we.height);
	all->tex.ea.tex.img = mlx_xpm_file_to_image(all->data.mlx, all->par.path.ea,
	&all->tex.ea.width, &all->tex.ea.height);
	if (all->tex.ea.tex.img == NULL ||
		all->tex.we.tex.img == NULL ||
		all->tex.so.tex.img == NULL ||
		all->tex.no.tex.img == NULL)
		ft_error_close("Invalid texture");
}
