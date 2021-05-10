/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:02:06 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 14:02:07 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../srcs/libft/libft.h"
# include "../mlx/mlx1.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define W all->par.res.x
# define H all->par.res.y
# define WWORLDMAP all->map.map
# define PAR all.par.par
# define MAP all.par.map
# define U_DIV 1
# define V_DIV 1
# define V_MOVE 0.0
# define TEXWID 64
# define TEXHIE 64

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				ln_len;
	int				endian;
	void			*mlx;
	void			*win;
}					t_data;

typedef struct		s_tex
{
	void			*img;
	char			*addr;
	int				bpp;
	int				ln_len;
	int				endian;
}					t_tex;

typedef struct		s_tex_info
{
	t_tex			tex;
	int				width;
	int				height;
}					t_tex_info;

typedef struct		s_spr
{
	double			dist;
	double			x;
	double			y;
}					t_spr;

typedef struct		s_all_spr
{
	t_tex			tex_spr;
	t_spr			*arr_spr;
	int				count;
}					t_all_spr;

typedef struct		s_all_tex
{
	t_tex_info		no;
	t_tex_info		so;
	t_tex_info		we;
	t_tex_info		ea;
	t_tex_info		obj;
}					t_all_tex;

typedef struct		s_keys
{
	int				mv_fwd;
	int				mv_bck;
	int				mv_lft;
	int				mv_rgt;
	int				rot_lft;
	int				rot_rgt;
	int				esc;
}					t_key;

typedef struct		s_path
{
	char			*so;
	char			*no;
	char			*we;
	char			*ea;
	char			*sp;

}					t_pth;

typedef struct		s_colors
{
	int				fr;
	int				fg;
	int				fb;
	int				fl;
	int				cr;
	int				cg;
	int				cb;
	int				ce;

}					t_col;

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef	struct		s_co
{
	int				i;
	int				j;
	int				par_fl;
	int				anal;
	char			or;
	int				scr_fl;
	int				map_fl;
}					t_co;

typedef struct		s_params
{
	t_col			col;
	t_res			res;
	t_pth			path;
	t_list			*map;
	t_list			*par;
}					t_par;

typedef struct		s_check
{
	int				r;
	int				f;
	int				c;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				sp;
}					t_che;

typedef struct		s_map
{
	char			**map;
	int				len;
	int				lst_size;
}					t_map;

typedef struct		s_spr_cst
{
	double			spr_x;
	double			spr_y;
	double			inv_det;
	double			tfm_x;
	double			tfm_y;
	int				spr_scr_x;
	int				spr_hei;
	int				draw_start_y;
	int				draw_end_y;
	int				spr_wid;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
	int				tex_y;
	unsigned int	*color;
	int				d;
}					t_spr_cst;

typedef struct		s_w_cst
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_num;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	double			old_dir_x;
	double			old_plane_x;
	double			*z_buf;
	unsigned int	*color;
}					t_w_cst;

typedef struct		s_plr
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_plr;

typedef struct		s_all
{
	t_spr_cst		spr_cst;
	t_data			data;
	t_map			map;
	t_co			co;
	t_par			par;
	t_che			che;
	t_plr			plr;
	t_w_cst			ray;
	t_all_spr		spr;
	t_key			keys;
	t_all_tex		tex;
}					t_all;

void				ft_init_all(t_all *all);
int					ft_get_valid(t_all *all);
int					ft_t_space(char **str);
char				*ft_get_null(int *flag, int *pflag);
int					ft_path_check(char *line);
char				*w_pth(int *flag, char **line, int *pflag);
int					p_pth(t_all *all, char **line);
int					ft_color_check(int r, int g, int b);
int					f_clr(t_all *all, char **line);
int					c_clr(t_all *all, char **line);
int					p_cls(t_all *all, char **line);
int					p_res(t_all *all, char **line);
int					ft_param_parser(t_all *all, char *line);
int					ft_free_mem(t_list **list);
int					ft_free_line(char **line);
void				ft_free_all(t_all *all, t_list **map, t_list **params);
int					ft_par_parse(t_all *all, int fd, t_list **list);
int					ft_map_soft_anal(t_all *all, char *line, char *head);
int					ft_map_copy(void *head, char *all, int len);
int					ft_map_search(t_all *all, char *line);
int					ft_map_init(t_all *all, t_list *list,
					int len, int lst_size);
void				ft_map_hard_anal(t_all *all, char **array, int i, int j);
int					ft_map_anal(t_all *all);
int					ft_map_size(t_all *all, t_list *list);
int					ft_map_parse(t_all *all, int fd, t_list **list);
void				ft_put_error(const char *str);
int					ft_error_close(const char *str);
int					ft_valid_clr(char *str);
int					ft_main_parser(t_all *all, int fd,
					t_list *par, t_list *map);
int					ft_pos_finder(t_all *all);
int					cre_rgb(int r, int g, int b);
void				ft_draw(t_all *all);
void				ft_fl_ce_cst(t_all *all);
void				get_textures_info(t_all *all);
void				get_textures_addr(t_all *all);
void				get_img_spr(t_all *all);
void				get_addr_spr(t_all *all);
int					ft_shut_down();
void				ft_scr_sh(t_all *all);
void				get_img_spr(t_all *all);
void				get_addr_spr(t_all *all);
void				ft_get_scr(t_all *all);
void				ft_spr_swp(t_all *all, int i, int j);
void				ft_q_sort(t_all *all, int first, int last);
void				cal_sort(t_all *all);
void				my_mlx_pixel_put(t_all *all, int x, int y, int color);
int					ft_shut_down();
unsigned int		*ft_pixel_take_spr(t_tex tex, int x, int y);
unsigned int		*ft_pixel_take(t_tex_info *tex, int x, int y);
void				ft_mv_fwd(t_all *all);
void				ft_mv_bck(t_all *all);
void				ft_mv_lft(t_all *all);
void				ft_mv_rgt(t_all *all);
void				ft_rot_lft(t_all *all);
void				ft_rot_rgt(t_all *all);
int					ft_key_ev(t_all *all);
int					ft_key_prs(int key, t_all *all);
int					ft_key_rel(int key, t_all *all);
void				ft_fl_ce_cst(t_all *all);
void				ft_key_init(t_all *all);
void				ft_all_mlx(t_all *all);
void				ft_che_arg(char *line);
void				ft_draw_spr1(t_all *all, int v_mv_scr, int i);
void				ft_draw_spr2(t_all *all, int y, int v_mv_scr, int stripe);
void				ft_draw_spr3(t_all *all, int i);
void				ft_draw_spr(t_all *all);
void				ft_draw_util(t_all *all);
void				ft_draw1(t_all *all, int x);
void				ft_draw2(t_all *all);
void				ft_draw3(t_all *all, int x);
void				ft_draw4(t_all *all, int x);
void				ft_draw5(t_all *all, int x, int y);

#endif
