#include "../include/cub3d.h"

void	ft_draw_spr3(t_all *all, int v_mv_scr, int i)
{
	all->spr_cst.spr_x = (all->spr.arr_spr)[i].x - all->plr.pos_x;
	all->spr_cst.spr_y = (all->spr.arr_spr)[i].y - all->plr.pos_y;
	all->spr_cst.inv_det = 1.0 / (all->plr.plane_x * all->plr.dir_y -
	all->plr.dir_x * all->plr.plane_y);
	all->spr_cst.tfm_x = all->spr_cst.inv_det * (all->plr.dir_y *
	all->spr_cst.spr_x - all->plr.dir_x * all->spr_cst.spr_y);
	all->spr_cst.tfm_y = all->spr_cst.inv_det * (-all->plr.plane_y *
	all->spr_cst.spr_x + all->plr.plane_x * all->spr_cst.spr_y);
	all->spr_cst.spr_scr_x = (int)((W / 2) * (1 + all->spr_cst.tfm_x /
	all->spr_cst.tfm_y));
}
