#include "../include/cub3d.h"

unsigned int	*ft_pixel_take(t_tex_info *tex, int x, int y)
{
	return ((unsigned int *)(tex->tex.addr + (y * tex->tex.ln_len + x * (tex->tex.bpp / 8))));
}
