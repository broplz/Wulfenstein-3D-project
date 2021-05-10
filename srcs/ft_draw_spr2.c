#include "../include/cub3d.h"

void	ft_draw_spr2(t_all *all, int y, int v_mv_scr, int stripe)
{
	while (y < all->spr_cst.draw_end_y)
	{
		all->spr_cst.d = (y - v_mv_scr) * 256 - H * 128 +
		all->spr_cst.spr_hei * 128;
		all->spr_cst.tex_y = ((all->spr_cst.d * TEXHIE) /
		all->spr_cst.spr_hei) / 256;
		all->spr_cst.color = ft_pixel_take_spr(all->spr.tex_spr,
		all->spr_cst.tex_x, all->spr_cst.tex_y);
		if ((*(all->spr_cst.color) & 0x00FFFFFF) != 0x00000000)
		{
			my_mlx_pixel_put(all, stripe, y,
			(int)*(all->spr_cst.color));
		}
		y++;
	}
}
