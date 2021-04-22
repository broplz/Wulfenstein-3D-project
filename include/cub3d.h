/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:30:50 by broplz            #+#    #+#             */
/*   Updated: 2021/04/22 23:20:17 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../srcs/libft/libft.h"
# include "../../mlx-lib/mlx-linux/mlx.h"
# include "../../mlx-lib/mlx-linux/mlx_int.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define W all->params.res.x
# define H all->params.res.y
# define WORLDMAP all.map.map
# define WWORLDMAP all->map.map
# define PAR all.params.par
# define MAP all.params.map

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

# define screenWidth 640
# define screenHeight 480
# define texWidth 64
# define texHeight 64
# define mapWidth 24
# define mapHeight 24

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
}				t_data;

typedef struct	s_path
{
	char		*so;
	char		*no;
	char		*we;
	char		*ea;
	char		*sp;

}				t_path;

typedef struct	s_colors
{
	int			fr;
	int			fg;
	int			fb;
	int			cr;
	int			cg;
	int			cb;

}				t_colors;

typedef struct	s_res
{
	long		x;
	long		y;
}				t_res;

typedef	struct	s_co
{
	int			i;
	int			j;
	int			pflag;
	int			anal;
	char		orient;
}				t_co;

typedef struct	s_params
{
	t_colors	colors;
	t_res		res;
	t_path		path;
	t_list		*map;
	t_list		*par;
}				t_params;

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
}				t_check;

typedef struct	s_map
{
	char		**map;
	int			len;
	int			lst_size;
}				t_map;

typedef struct	s_ray
{
	double		cameraX; // = 2 * x / (double)w - 1; //x-coordinate in camera space
	double		rayDirX; // = dirX + planeX*cameraX;
	double		rayDirY; // = dirY + planeY*cameraX;
	int			mapX; // = int(posX);
	int			mapY; // = int(posY);
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX; // = std::abs(1 / rayDirX);
	double		deltaDistY; // = std::abs(1 / rayDirY);
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			color;
	int			hit; // = 0; //was there a wall hit?
	int			side; //was a NS or a EW wall hit?
	int			lineHeight; // = (int)(h / perpWallDist);
	int			drawStart; // = -lineHeight / 2 + h / 2;
	int			drawEnd; // = lineHeight / 2 + h / 2;
	int			texNum; // = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!
	double		wallX; //where exactly the wall was hit
	int			texX; // = int(wallX * double(texWidth));
	double		step; // = 1.0 * texHeight / lineHeight;
	double		texPos; // = (drawStart - h / 2 + lineHeight / 2) * step;
	int			texY; // = (int)texPos & (texHeight - 1);
	double		frameTime; //= (time - oldTime) / 1000.0; //frametime is the time this frame has taken, in seconds
	double		moveSpeed; // = frameTime * 5.0; //the constant value is in squares/second
	double		rotSpeed; // = frameTime * 3.0; //the constant value is in radians/second
	double		oldDirX; // = dirX;
	double		oldPlaneX; // = planeX;
}				t_ray;

typedef struct	s_char
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
}				t_char;

typedef struct	s_all
{
	t_data		data;
	t_map		map;
	t_co		co;
	t_params	params;
	t_check		check;
	t_char		character;
	t_ray		ray;
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
int				ft_main_parser(t_all *all, int fd, int argc, t_list *par, t_list *map);
int				draw(t_all *all);

#endif
