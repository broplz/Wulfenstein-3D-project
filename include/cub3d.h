/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:30:50 by broplz            #+#    #+#             */
/*   Updated: 2021/04/30 22:04:08 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../srcs/libft/libft.h"
//# include "../include/mlx.h"
//# include "../include/mlx_int.h"
#include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define W all->par.res.x
# define H all->par.res.y
# define WORLDMAP all.map.map
# define WWORLDMAP all->map.map
# define PAR all.par.par
# define MAP all.par.map

/* TODO =>	PARAM_PARSER start	<= */
# define WEPA all->params.path.we
# define WEST w_pth(&(all->check.we), line, flag)
# define NOPA all->params.path.no
# define NORTH w_pth(&(all->check.no), line, flag)
# define EAPA all->params.path.ea
# define EAST w_pth(&(all->check.ea), line, flag)
# define SOPA all->params.path.so
# define SOUTH w_pth(&(all->check.so), line, flag)
# define SPPA all->params.path.sp
# define SPRITES w_pth(&(all->check.sp), line, flag)
/* TODO =>	PARAM_PARSER end	<= */

# define texWidth 64
# define texHeight 64

typedef struct	s_window
{
	void		*mlx;
	void		*win;
}				t_win;


typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bts_per_pxl;
	int			ln_len;
	int			endian;
	void		*mlx;
	void		*win;
}				t_data;

typedef struct	s_keys
{
	int			mv_fwd;
	int			mv_bck;
	int			mv_lft;
	int			mv_rgt;
	int			rot_lft;
	int			rot_rgt;
	int			esc;
}				t_key;

typedef struct	s_path
{
	char		*so;
	char		*no;
	char		*we;
	char		*ea;
	char		*sp;

}				t_pth;

typedef struct	s_colors
{
	int			fr;
	int			fg;
	int			fb;
	int			fl;
	int			cr;
	int			cg;
	int			cb;
	int			ce;

}				t_col;

typedef struct	s_res
{
	int			x;
	int			y;
}				t_res;

typedef	struct	s_co
{
	int			i;
	int			j;
	int			pflag;
	int			anal;
	char		or;
}				t_co;

typedef struct	s_params
{
	t_col		col;
	t_res		res;
	t_pth		path;
	t_list		*map;
	t_list		*par;
}				t_par;

typedef struct	s_check
{
	int			r;
	int			f;
	int			c;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			sp;
}				t_che;

typedef struct	s_w_spr
{
	int			*texture;
	double		x;
	double		y;
}				t_spr;

typedef struct	s_map
{
	char		**map;
	int			len;
	int			lst_size;
}				t_map;

typedef struct	s_w_cst
{
	double		camera_x; // = 2 * x / (double)w - 1; //x-coordinate in camera space
	double		ray_dir_x; // = dirX + planeX*cameraX;
	double		ray_dir_y; // = dirY + planeY*cameraX;
	int			map_x; // = int(posX);
	int			map_y; // = int(posY);
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x; // = std::abs(1 / rayDirX);
	double		delta_dist_y; // = std::abs(1 / rayDirY);
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit; // = 0; //was there a wall hit?
	int			side; //was a NS or a EW wall hit?
	int			line_height; // = (int)(h / perpWallDist);
	int			draw_start; // = -lineHeight / 2 + h / 2;
	int			draw_end; // = lineHeight / 2 + h / 2;
	int			tex_num; // = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!
	double		wall_x; //where exactly the wall was hit
	int			tex_x; // = int(wallX * double(texWidth));
	int			tex_y; // = (int)texPos & (texHeight - 1);
	double		step; // = 1.0 * texHeight / lineHeight;
	double		tex_pos; // = (drawStart - h / 2 + lineHeight / 2) * step;
	double		frame_time; //= (time - oldTime) / 1000.0; //frametime is the time this frame has taken, in seconds
	double		move_speed; // = frameTime * 5.0; //the constant value is in squares/second
	double		rot_speed; // = frameTime * 3.0; //the constant value is in radians/second
	double		old_dir_x; // = dirX;
	double		old_plane_x; // = planeX;
	double		pos_z;
	double		raw_dist;
	unsigned int	*color;
}				t_w_cst;

typedef struct	s_plr
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_plr;

typedef struct	s_all
{
	t_data		data;
	t_map		map;
	t_co		co;
	t_par		par;
	t_che		che;
	t_plr		plr;
	t_w_cst		ray;
	t_spr		spr;
	t_key		keys;
	double		*z_buf;
}				t_all;

void			ft_init_all(t_all *all);
int				ft_get_valid(t_all *all);
int				ft_t_space(char **str);
char			*ft_get_null(int *flag, int *pflag);
int				ft_path_check(char *line);
char			*w_pth(int *flag, char **line, int *pflag);
int				p_pth(t_all *all, char **line);
int				ft_color_check(int r, int g, int b);
int				f_clr(t_all *all, char **line);
int				c_clr(t_all *all, char **line);
int				p_cls(t_all *all, char **line);
int				p_res(t_all *all, char **line);
int				ft_param_parser(t_all *all, char *line);
int				ft_free_mem(t_list **list);
int				ft_free_line(char **line);
void			ft_free_all(t_all *all , t_list **map, t_list **params);
int				ft_par_parse(t_all *all, int fd, t_list **list);
int				ft_map_soft_anal(t_all *all, char *line, char *head);
int				ft_map_copy(void *head, char *all, int len);
int				ft_map_search(t_all *all, char *line);
int				ft_map_init(t_all *all, t_list *list, int len, int lst_size);
int				ft_map_hard_anal(t_all *all, char **array, int i, int j);
int				ft_map_anal(t_all *all);
int				ft_map_size(t_all *all, t_list *list);
int				ft_map_parse(t_all *all, int fd, t_list **list);
void			ft_put_error(const char *str);
int				ft_error_close(const char *str);
int				ft_valid_clr(char *str);
int				ft_main_parser(t_all *all, int fd, t_list *par, t_list *map);
int				draw(t_all *all);
int				ft_pos_finder(t_all *all);
int				cre_rgb(int r, int g, int b);
int				ft_draw(t_all *all);
void			ft_fl_ce_cst(t_all *all);

#endif
