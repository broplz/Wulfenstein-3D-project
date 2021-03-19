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
//	int			mflag;
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

typedef struct	s_all
{
//	char		**c_s_str;
	t_co		co;
	t_params	params;
	t_check		check;
}				t_all;

#endif
