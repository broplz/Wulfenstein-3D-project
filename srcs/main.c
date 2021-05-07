/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broplz <broplz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:30:25 by broplz            #+#    #+#             */
/*   Updated: 2021/04/30 22:06:04 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void get_img_spr(t_all *all)
{
	if (!(all->spr.tex_spr.img = \
 mlx_xpm_file_to_image(all->data.mlx, all->par.path.sp, \
 &all->spr_cst.spr_wid, &all->spr_cst.spr_hei)))
		exit(0);
}

void get_addr_spr(t_all *all)
{
	all->spr.tex_spr.addr = \
 mlx_get_data_addr(all->spr.tex_spr.img, &all->spr.tex_spr.bpp, \
 &all->spr.tex_spr.ln_len, &all->spr.tex_spr.endian);
}

void		ft_get_scr(t_all *all)
{
	int		x;
	int		y;

	mlx_get_screen_size(all->data.mlx, &x, &y);
	if (all->par.res.x > 10000)
		all->par.res.x = 10000;
	if (all->par.res.y > 10000)
		all->par.res.y = 10000;
	else
	{
		if (all->par.res.x > x)
			all->par.res.x = x;
		if (all->par.res.x > y)
			all->par.res.x = y;
	}
}

void		ft_spr_swp(t_all *all, int i, int j)
{
	t_spr	tmp;

	tmp.x = all->spr.arr_spr[i].x;
	tmp.y = all->spr.arr_spr[i].y;
	tmp.dist = all->spr.arr_spr[i].dist;

	all->spr.arr_spr[i].x = all->spr.arr_spr[j].x;
	all->spr.arr_spr[i].y = all->spr.arr_spr[j].y;
	all->spr.arr_spr[i].dist = all->spr.arr_spr[j].dist;

	all->spr.arr_spr[j].x = tmp.x;
	all->spr.arr_spr[j].y = tmp.y;
	all->spr.arr_spr[j].dist = tmp.dist;
}

void		sort2(t_all *all)
{
	for (int i = 0 ; i < all->spr.count - 1; i++) {
		// сравниваем два соседних элемента.
		for(int j = 0 ; j < all->spr.count - i - 1; j++) {
			if (all->spr.arr_spr[j].dist < all->spr.arr_spr[j + 1].dist) {
				// если они идут в неправильном порядке, то
				//  меняем их местами.
				ft_spr_swp(all, j, j + 1);
			}
		}
	}
}

void		ft_q_sort(t_all *all, int first, int last)
{
	int		i;
	int		j;
	int		midlle;

	if (first < last)
	{
		midlle = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (all->spr.arr_spr[i].dist >= all->spr.arr_spr[midlle].dist && i < last)
				i++;
			while (all->spr.arr_spr[j].dist < all->spr.arr_spr[midlle].dist)
				j--;
			if (i < j)
				ft_spr_swp(all, i, j);
		}
		ft_spr_swp(all, midlle, j);
		ft_q_sort(all, j + 1, last);
		ft_q_sort(all, first, j - 1);
	}
}

void		cal_sort(t_all *all)
{
	for(int i = 0; i < all->spr.count; i++)
	{
		all->spr.arr_spr[i].dist = ((all->plr.pos_x - all->spr.arr_spr[i].x)
									* (all->plr.pos_x - all->spr.arr_spr[i].x)
									+ (all->plr.pos_y - all->spr.arr_spr[i].y)
									* (all->plr.pos_y - all->spr.arr_spr[i].y)); //sqrt not taken, unneeded
		printf("dist == %f\n", all->spr.arr_spr[i].dist);
	}
}

void		my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char    *dst;

	dst = all->data.addr + (y * all->data.ln_len + x * (all->data.bpp / 8));
	*(unsigned int*)dst = color;
}

void 		get_textures_info(t_all *all)
{
	all->tex.no.tex.img = mlx_xpm_file_to_image(all->data.mlx, all->par.path.no, &all->tex.no.width, &all->tex.no.height);
	all->tex.so.tex.img = mlx_xpm_file_to_image(all->data.mlx, all->par.path.so, &all->tex.so.width, &all->tex.so.height);
	all->tex.we.tex.img = mlx_xpm_file_to_image(all->data.mlx, all->par.path.we, &all->tex.we.width, &all->tex.we.height);
	all->tex.ea.tex.img = mlx_xpm_file_to_image(all->data.mlx, all->par.path.ea, &all->tex.ea.width, &all->tex.ea.height);
//	all->tex.obj.tex.img = mlx_xpm_file_to_image(all->data.mlx, all->par.path.sp, &all->tex.obj.width, &all->tex.obj.height);
}

void 		get_textures_addr(t_all *all)
{
	all->tex.no.tex.addr = mlx_get_data_addr(all->tex.no.tex.img, &all->tex.no.tex.bpp, &all->tex.no.tex.ln_len, &all->tex.no.tex.endian);
	all->tex.so.tex.addr = mlx_get_data_addr(all->tex.so.tex.img, &all->tex.so.tex.bpp, &all->tex.so.tex.ln_len, &all->tex.so.tex.endian);
	all->tex.we.tex.addr = mlx_get_data_addr(all->tex.we.tex.img, &all->tex.we.tex.bpp, &all->tex.we.tex.ln_len, &all->tex.we.tex.endian);
	all->tex.ea.tex.addr = mlx_get_data_addr(all->tex.ea.tex.img, &all->tex.ea.tex.bpp, &all->tex.ea.tex.ln_len, &all->tex.ea.tex.endian);
//	all->tex.obj.tex.addr = mlx_get_data_addr(all->tex.obj.tex.img, &all->tex.obj.tex.bpp, &all->tex.obj.tex.ln_len, &all->tex.obj.tex.endian);
}

void		ft_shut_down()
{
	exit(0);
}

unsigned int	*ft_pixel_take_spr(t_tex tex, int x, int y)
{
	return ((unsigned int *)(tex.addr + (y * tex.ln_len + x * (tex.bpp / 8))));
}

unsigned int	*ft_pixel_take(t_tex_info *tex, int x, int y)
{
	return ((unsigned int *)(tex->tex.addr + (y * tex->tex.ln_len + x * (tex->tex.bpp / 8))));
}

void 	ft_mv_fwd(t_all *all)
{
	if (all->keys.mv_fwd)
	{
		if (all->map.map[(int) (all->plr.pos_x + all->plr.dir_x * 0.25)]
			[(int) (all->plr.pos_y)] == '0')
			all->plr.pos_x += all->plr.dir_x * 0.25;
		if (all->map.map[(int) all->plr.pos_x]
			[(int) (all->plr.pos_y + all->plr.dir_y * 0.25)] == '0')
			all->plr.pos_y += all->plr.dir_y * 0.25;
	}
}

void 	ft_mv_bck(t_all *all)
{
	if (all->keys.mv_bck )
	{
		if (all->map.map[(int) (all->plr.pos_x - all->plr.dir_x * 0.25)]
			[(int) (all->plr.pos_y)] == '0')
			all->plr.pos_x -= all->plr.dir_x * 0.25;
		if (all->map.map[(int) all->plr.pos_x]
			[(int) (all->plr.pos_y - all->plr.dir_y * 0.25)] == '0')
			all->plr.pos_y -= all->plr.dir_y * 0.25;
	}
}

void	ft_mv_lft(t_all *all)
{
	if (all->keys.mv_lft)
	{
		if (all->map.map[(int) (all->plr.pos_x - all->plr.dir_y * 0.1)]
			[(int) all->plr.pos_y] == '0')
			all->plr.pos_x -= all->plr.dir_y * 0.05;
		if (all->map.map[(int) all->plr.pos_x]
			[(int) (all->plr.pos_y + all->plr.dir_x * 0.1)] == '0')
			all->plr.pos_y += all->plr.dir_x * 0.05;
	}
}

void	ft_mv_rgt(t_all *all)
{
	if (all->keys.mv_rgt)
	{
		if (all->map.map[(int) (all->plr.pos_x + all->plr.dir_y * 0.1)]
			[(int) all->plr.pos_y] == '0')
			all->plr.pos_x += all->plr.dir_y * 0.05;
		if (all->map.map[(int) all->plr.pos_x]
			[(int) (all->plr.pos_y - all->plr.dir_x * 0.1)] == '0')
			all->plr.pos_y -= all->plr.dir_x * 0.05;
	}
}

void	ft_rot_lft(t_all *all)
{
	all->ray.old_dir_x = all->plr.dir_x;
	all->plr.dir_x = all->plr.dir_x * cos(0.05)
					 - all->plr.dir_y * sin(0.05);
	all->plr.dir_y = all->ray.old_dir_x * sin(0.05)
					 + all->plr.dir_y * cos(0.05);
	all->ray.old_plane_x = all->plr.plane_x;
	all->plr.plane_x = all->plr.plane_x * cos(0.05)
					   - all->plr.plane_y * sin(0.05);
	all->plr.plane_y = all->ray.old_plane_x * sin(0.05)
					   + all->plr.plane_y * cos(0.05);
}

void	ft_rot_rgt(t_all *all)
{
	all->ray.old_dir_x = all->plr.dir_x;
	all->plr.dir_x = all->plr.dir_x * cos(-0.05)
			- all->plr.dir_y * sin(-0.05);
	all->plr.dir_y = all->ray.old_dir_x * sin(-0.05)
			+ all->plr.dir_y * cos(-0.05);
	all->ray.old_plane_x = all->plr.plane_x;
	all->plr.plane_x = all->plr.plane_x * cos(-0.05)
			- all->plr.plane_y * sin(-0.05);
	all->plr.plane_y = all->ray.old_plane_x * sin(-0.05)
			+ all->plr.plane_y * cos(-0.05);
}

int			ft_key_ev(t_all *all)
{
	mlx_do_sync(all->data.mlx);
	ft_mv_fwd(all);
	ft_mv_bck(all);
	ft_mv_lft(all);
	ft_mv_rgt(all);
	if (all->keys.rot_lft)
		ft_rot_lft(all);
	if (all->keys.rot_rgt)
		ft_rot_rgt(all);
	if (all->keys.esc)
		exit(1);
	ft_draw(all);
	return (1);
}

int		ft_key_prs(int key, t_all *all)
{
	if (key == 13)
		all->keys.mv_fwd = 1;
	if (key == 1)
		all->keys.mv_bck = 1;
	if (key == 0)
		all->keys.mv_lft = 1;
	if (key == 2)
		all->keys.mv_rgt = 1;
	if (key == 123)
		all->keys.rot_lft = 1;
	if (key == 124)
		all->keys.rot_rgt = 1;
	if (key == 53)
		ft_shut_down();
	printf("key = %d\n", key);
	return (0);
}

int		ft_key_rel(int key, t_all *all)
{
	if (key == 13)
		all->keys.mv_fwd = 0;
	if (key == 1)
		all->keys.mv_bck = 0;
	if (key == 0)
		all->keys.mv_lft = 0;
	if (key == 2)
		all->keys.mv_rgt = 0;
	if (key == 123)
		all->keys.rot_lft = 0;
	if (key == 124)
		all->keys.rot_rgt = 0;
	return (0);
}

int		cre_rgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

void	ft_fl_ce_cst(t_all *all)
{
	int y;
	int x;

	y = 0;
	while (y < H / 2)
	{
		x = 0;
		while (x < W)
		{
			my_mlx_pixel_put(all, x, y, all->par.col.ce);
			x++;
		}
		y++;
	}
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			my_mlx_pixel_put(all, x, y, all->par.col.fl);
			x++;
		}
		y++;
	}
}

void	ft_key_init(t_all *all)
{
	all->keys.mv_bck = 0;
	all->keys.mv_fwd = 0;
	all->keys.mv_lft = 0;
	all->keys.mv_rgt = 0;
	all->keys.rot_lft = 0;
	all->keys.rot_rgt = 0;
	all->keys.esc = 0;
}

void	ft_draw_spr(t_all *all)
{
	//SPRITE CASTING
	//sort sprites from far to close
	cal_sort(all);
	sort2(all);
//	ft_q_sort(all, 0, all->spr.count - 1);

	//after sorting the sprites, do the projection and draw them
	for(int i = 0; i < all->spr.count; i++)
	{
		//translate sprite position to relative to camera
		all->spr_cst.spr_x = (all->spr.arr_spr)[i].x - all->plr.pos_x;
		all->spr_cst.spr_y = (all->spr.arr_spr)[i].y - all->plr.pos_y;

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		all->spr_cst.inv_det = 1.0 / (all->plr.plane_x * all->plr.dir_y - all->plr.dir_x * all->plr.plane_y); //required for correct matrix multiplication

		all->spr_cst.tfm_x = all->spr_cst.inv_det * (all->plr.dir_y * all->spr_cst.spr_x - all->plr.dir_x * all->spr_cst.spr_y);
		all->spr_cst.tfm_y = all->spr_cst.inv_det * (-all->plr.plane_y * all->spr_cst.spr_x + all->plr.plane_x * all->spr_cst.spr_y); //this is actually the depth inside the screen, that what Z is in 3D

		all->spr_cst.spr_scr_x = (int)((W / 2) * (1 + all->spr_cst.tfm_x / all->spr_cst.tfm_y));

		//calculate height of the sprite on screen
		#define uDiv 1
		#define vDiv 1
		#define vMove 0.0

		int vMoveScreen = (int)vMove / all->spr_cst.tfm_y;
		all->spr_cst.spr_hei = abs((int)(H / (all->spr_cst.tfm_y))) / vDiv; //using 'transformY' instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		all->spr_cst.draw_start_y = -all->spr_cst.spr_hei / 2 + H / 2 + vMoveScreen;
		if(all->spr_cst.draw_start_y < 0) all->spr_cst.draw_start_y = 0;
		all->spr_cst.draw_end_y = all->spr_cst.spr_hei / 2 + H / 2 + vMoveScreen;
		if(all->spr_cst.draw_end_y >= H) all->spr_cst.draw_end_y = H - 1;

		//calculate width of the sprite
		all->spr_cst.spr_wid = abs((int)(H / (all->spr_cst.tfm_y))) / uDiv;
		all->spr_cst.draw_start_x = -all->spr_cst.spr_wid / 2 + all->spr_cst.spr_scr_x;
		if(all->spr_cst.draw_start_x < 0) all->spr_cst.draw_start_x = 0;
		all->spr_cst.draw_end_x = all->spr_cst.spr_wid / 2 + all->spr_cst.spr_scr_x;
		if(all->spr_cst.draw_end_x >= W) all->spr_cst.draw_end_x = W - 1;

		//loop through every vertical stripe of the sprite on screen
		for(int stripe = all->spr_cst.draw_start_x; stripe < all->spr_cst.draw_end_x; stripe++)
		{
			all->spr_cst.tex_x = (int) (256 * (stripe - (-all->spr_cst.spr_wid / 2 + all->spr_cst.spr_scr_x)) * texWidth / all->spr_cst.spr_wid) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance

			if (all->spr_cst.tfm_y > 0 && stripe >= 0 && stripe < W && all->spr_cst.tfm_y < all->ray.z_buf[stripe])
			{
				int y = all->spr_cst.draw_start_y;
				while (y < all->spr_cst.draw_end_y)
				{
					all->spr_cst.d = (y - vMoveScreen) * 256 - H * 128 + all->spr_cst.spr_hei * 128; //256 and 128 factors to avoid floats
					all->spr_cst.tex_y = ((all->spr_cst.d * texHeight) / all->spr_cst.spr_hei) / 256;

					all->spr_cst.color = ft_pixel_take_spr(all->spr.tex_spr, all->spr_cst.tex_x, all->spr_cst.tex_y);// texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
					if ((*(all->spr_cst.color) & 0x00FFFFFF) != 0x00000000)
					{
						my_mlx_pixel_put(all, stripe, y, (int)*(all->spr_cst.color));
					}//buffer[y][stripe] = all->spr_cst.color; //paint pixel if it isn't black, black is the invisible color
					y++;
				}
			}
		}
	}
}

void	ft_draw(t_all *all)
{
	int x;

	x = -1;
	ft_fl_ce_cst(all);
	while (++x < W)
	{
		all->ray.camera_x = 2 * x / (double) W - 1; //x-coordinate in camera space
		all->ray.ray_dir_x = all->plr.dir_x + all->plr.plane_x * all->ray.camera_x;
		all->ray.ray_dir_y = all->plr.dir_y + all->plr.plane_y * all->ray.camera_x;

		all->ray.map_x = (int) (all->plr.pos_x);
		all->ray.map_y = (int) (all->plr.pos_y);

		all->ray.delta_dist_x = (all->ray.ray_dir_y == 0) ? 0 : ((all->ray.ray_dir_x == 0) ? 1 : fabs(
				1 / all->ray.ray_dir_x));
		all->ray.delta_dist_y = (all->ray.ray_dir_x == 0) ? 0 : ((all->ray.ray_dir_y == 0) ? 1 : fabs(
				1 / all->ray.ray_dir_y));

		all->ray.hit = 0;
		all->ray.side_dist_x = 0;
		if (all->ray.ray_dir_x < 0) {
			all->ray.step_x = -1;
			all->ray.side_dist_x = (all->plr.pos_x - all->ray.map_x) * all->ray.delta_dist_x;
		} else {
			all->ray.step_x = 1;
			all->ray.side_dist_x = (all->ray.map_x + 1.0 - all->plr.pos_x) * all->ray.delta_dist_x;
		}
		if (all->ray.ray_dir_y < 0) {
			all->ray.step_y = -1;
			all->ray.side_dist_y = (all->plr.pos_y - all->ray.map_y) * all->ray.delta_dist_y;
		} else {
			all->ray.step_y = 1;
			all->ray.side_dist_y = (all->ray.map_y + 1.0 - all->plr.pos_y) * all->ray.delta_dist_y;
		}
		//perform DDA
		while (all->ray.hit == 0) {
			//jump to next map square, OR in x-direction, OR in y-direction
			if (all->ray.side_dist_x < all->ray.side_dist_y) {
				all->ray.side_dist_x += all->ray.delta_dist_x;
				all->ray.map_x += all->ray.step_x;
				all->ray.side = 0;
			} else {
				all->ray.side_dist_y += all->ray.delta_dist_y;
				all->ray.map_y += all->ray.step_y;
				all->ray.side = 1;
			}
			//Check if ray has hit a wall
			if (WWORLDMAP[all->ray.map_x][all->ray.map_y] == '1') all->ray.hit = 1;
		}

		if (all->ray.side == 0)
			all->ray.perp_wall_dist = (all->ray.map_x - all->plr.pos_x + (1.0
			- (double) all->ray.step_x) / 2) /
			all->ray.ray_dir_x;
		else
			all->ray.perp_wall_dist = (all->ray.map_y - all->plr.pos_y + (1.0
			- (double) all->ray.step_y) / 2) /
			all->ray.ray_dir_y;
//		printf("a = %f", all->ray.perp_wall_dist);
		all->ray.z_buf[x] = all->ray.perp_wall_dist;

		//Calculate height of line to draw on screen
		all->ray.line_height = (int) (H / all->ray.perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		all->ray.draw_start = -all->ray.line_height / 2 + H / 2;
		if (all->ray.draw_start < 0) all->ray.draw_start = 0;
		all->ray.draw_end = all->ray.line_height / 2 + H / 2;
		if (all->ray.draw_end >= H)
			all->ray.draw_end = H - 1;

		//texturing calculations
		all->ray.tex_num =
				WWORLDMAP[all->ray.map_x][all->ray.map_y] - 1; //1 subtracted from it so that texture 0 can be used!

		//calculate value of wallX
		//      all->ray.wall_x; //where exactly the wall was hit
		if (all->ray.side == 0)
			all->ray.wall_x = all->plr.pos_y + all->ray.perp_wall_dist * all->ray.ray_dir_y;
		else
			all->ray.wall_x = all->plr.pos_x + all->ray.perp_wall_dist * all->ray.ray_dir_x;
		all->ray.wall_x -= floor((all->ray.wall_x));

		//x coordinate on the texture
		all->ray.tex_x = (int) (all->ray.wall_x * (double) (texWidth));
		if (all->ray.side == 0 && all->ray.ray_dir_x > 0)
			all->ray.tex_x = texWidth - all->ray.tex_x - 1;
		if (all->ray.side == 1 && all->ray.ray_dir_y < 0)
			all->ray.tex_x = texWidth - all->ray.tex_x - 1;

		// TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
		// How much to increase the texture coordinate per screen pixel
		all->ray.step = 1.0 * texHeight / all->ray.line_height;
		// Starting texture coordinate
		all->ray.tex_pos = (all->ray.draw_start - (double) H / 2 + (double) all->ray
				.line_height / 2) * all->ray.step;
		for (int y = all->ray.draw_start; y < all->ray.draw_end; y++) {
			t_tex_info *tex = NULL;
			if (all->ray.side == 0 && all->ray.step_x > 0)
				tex = &(all->tex.so);
			else if (all->ray.side == 0 && all->ray.step_x < 0)
				tex = &(all->tex.no);
			else if (all->ray.side == 1 && all->ray.step_y > 0)
				tex = &(all->tex.ea);
			else
				tex = &(all->tex.we);
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			all->ray.tex_y = (int) all->ray.tex_pos & (texHeight - 1);
			all->ray.tex_pos += all->ray.step;
			all->ray.color = ft_pixel_take(tex, all->ray.tex_x, all->ray.tex_y);
			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			my_mlx_pixel_put(all, x, y, (int)*(all->ray.color));
		}

	}

		ft_draw_spr(all);
		mlx_put_image_to_window(all->data.mlx, all->data.win, all->data.img, 0, 0);

//		mlx_destroy_image(all->data.mlx, all->data.img);
//		all->data.img = NULL;
//		all->data.addr = NULL;
//		all->data.img = mlx_new_image(all->data.mlx, W, H);
//		all->data.addr = mlx_get_data_addr(all->data.img, \
//		&all->data.bpp, &all->data.ln_len, &all->data.endian);
}


int		main(int argc, char **argv)
{
	t_all	all;
	int		fd;
	MAP = NULL;
	PAR = NULL;

	fd = open(argv[1], O_RDONLY);
	ft_init_all(&all);
	all.data.mlx = mlx_init();
	ft_main_parser(&all,fd, PAR, MAP);
	close(fd);
	ft_key_init(&all);
	ft_get_scr(&all);

	all.data.win = mlx_new_window(all.data.mlx, all.par.res.x, all.par.res.y,"rot");
	all.data.img = mlx_new_image(all.data.mlx, all.par.res.x, all.par.res.y);
	all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bpp, &all.data.ln_len, &all.data.endian);

//	ft_draw(&all);

	mlx_hook(all.data.win, 2, (1L << 0), &ft_key_prs, &all);
	mlx_hook(all.data.win, 3, (1L << 1), &ft_key_rel, &all);
	mlx_loop_hook(all.data.mlx, &ft_key_ev, &all);
	mlx_loop(all.data.mlx);
	return (0);
}