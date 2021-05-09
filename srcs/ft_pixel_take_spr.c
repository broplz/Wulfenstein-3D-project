#include "../include/cub3d.h"

unsigned int	*ft_pixel_take_spr(t_tex tex, int x, int y)
{
	return ((unsigned int *)(tex.addr + (y * tex.ln_len + x * (tex.bpp / 8))));
}
