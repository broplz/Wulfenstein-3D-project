#include "../include/cub3d.h"

void ft_print(t_all *mprms)
{
  printf("R = %d %d\n", mprms->par.res.x, mprms->par.res.y);
  printf("C = %d %d %d\n", mprms->par.col.cr, mprms->par.col.cg, mprms->par.col.cb);
  printf("F = %d %d %d\n", mprms->par.col.fr, mprms->par.col.fg, mprms->par.col.fb);
  printf("S = %s\n", mprms->par.path.sp);
  printf("SO = %s\n", mprms->par.path.so);
  printf("NO = %s\n", mprms->par.path.no);
  printf("EA = %s\n", mprms->par.path.ea);
  printf("WE = %s\n", mprms->par.path.we);
//  printf("check = %d %d %d %d %d %d %d %d = %d\n", mprms->full.res, mprms->full.c_clr, mprms->full.f_clr,
//    mprms->full.sprt, mprms->full.so, mprms->full.no, mprms->full.ea, mprms->full.we, mprms->check);
  for(int i = 0; mprms->map.map && mprms->map.map[i]; i++)
    printf("%s\n", mprms->map.map[i]);
  printf("size map = %d %d", mprms->map.len, mprms->map.lst_size);
}