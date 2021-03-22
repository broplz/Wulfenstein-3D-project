#ifndef CUB3D_H
#define CUB3D_H
#define ERROR_NO_MAP "There Is No Map"

#include "../srcs/libft/libft.h"
#include "./mlx.h"
#include <mlx.h>
#include <fcntl.h>

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int 		endian;
}				t_data;

typedef struct 	s_path
{
	char		*so;
	char		*no;
	char		*we;
	char		*ea;
	char		*sp;

}				t_path;

typedef struct	s_colors
{
	int 		fr;
	int 		fg;
	int 		fb;
	int 		cr;
	int 		cg;
	int 		cb;

}				t_colors;

typedef struct	s_res
{
	int			x;
	int			y;
}				t_res;

typedef	struct 	s_co
{
	int			i;
	int 		j;
	int 		pflag;
}				t_co;

typedef struct	s_params
{
	t_colors	colors;
	t_res		res;
	t_path		path;
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

typedef struct	s_all
{
	t_map		map;
	t_co		co;
	t_params	params;
	t_check		check;
}				t_all;

int		ft_init_all(t_all *all);
int		ft_get_valid(t_all *all);
int		ft_t_space(char **str);
char	*ft_get_null(int *flag, int *pflag);
int		ft_path_check(char *line);
char 	*w_pth(int *flag, char **line, int *pflag);
int		p_pth(t_all *all, char **line);
int		ft_color_check(int r, int g, int b);
int 	f_clr(t_all *all, char **line);
int 	c_clr(t_all *all, char **line);
int		p_cls(t_all *all, char **line);
int		p_res(t_all *all, char **line);
int		ft_param_parser(t_all *all, char *line);
int		ft_free_mem(t_list **list);
int		ft_par_parse(t_all *all, int fd, t_list **list);

#endif