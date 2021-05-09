#include "../include/cub3d.h"

void	ft_draw_spr1(t_all *all, int v_mv_scr, int i)
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
	v_mv_scr = (int)V_MOVE / all->spr_cst.tfm_y;
	all->spr_cst.spr_hei = abs((int)(H / (all->spr_cst.tfm_y))) / V_DIV;
	all->spr_cst.draw_start_y = -all->spr_cst.spr_hei / 2 + H / 2 + v_mv_scr;
	if(all->spr_cst.draw_start_y < 0) all->spr_cst.draw_start_y = 0;
	all->spr_cst.draw_end_y = all->spr_cst.spr_hei / 2 + H / 2 + v_mv_scr;
	if(all->spr_cst.draw_end_y >= H) all->spr_cst.draw_end_y = H;
	all->spr_cst.spr_wid = abs((int)(W / (all->spr_cst.tfm_y))) / U_DIV;
	all->spr_cst.draw_start_x = -all->spr_cst.spr_wid / 2 +
								all->spr_cst.spr_scr_x;
	if(all->spr_cst.draw_start_x < 0) all->spr_cst.draw_start_x = 0;
	all->spr_cst.draw_end_x = all->spr_cst.spr_wid / 2 +
							  all->spr_cst.spr_scr_x;
	if(all->spr_cst.draw_end_x >= W) all->spr_cst.draw_end_x = W;
}