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

void            my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char    *dst;

	dst = all->data.addr + (y * all->data.ln_len + x * (all->data.bts_per_pxl / 8));
	*(unsigned int*)dst = color;
}

void		ft_shut_down()
{
	ft_error_close("Exit program");
}

void 	ft_mv_fwd(t_all *all)
{
	if (all->map.map[(int)(all->plr.pos_x + all->plr.dir_x * 0.5)]
	[(int)(all->plr.pos_y)] == '1')
		all->plr.pos_x += all->plr.dir_x * 0.05;
	if (all->map.map[(int)all->plr.pos_x]
	[(int)(all->plr.pos_y + all->plr.dir_y * 0.05)] == '1')
		all->plr.pos_y += all->plr.dir_y * 0.05;
}

void 	ft_mv_bck(t_all *all)
{
	if (all->map.map[(int)(all->plr.pos_x - all->plr.dir_x * 0.5)]
		[(int)(all->plr.pos_y)] == '1')
		all->plr.pos_x -= all->plr.dir_x * 0.05;
	if (all->map.map[(int)all->plr.pos_x]
		[(int)(all->plr.pos_y - all->plr.dir_y * 0.05)] == '1')
		all->plr.pos_y -= all->plr.dir_y * 0.05;
}

void	ft_mv_lft(t_all *all)
{
	if (all->map.map[(int)(all->plr.pos_x - all->plr.dir_y * 0.05)]
	[(int)all->plr.pos_y] == '1')
		all->plr.pos_x -= all->plr.dir_y * 0.05;
	if (all->map.map[(int)all->plr.pos_x]
	[(int)(all->plr.pos_y + all->plr.dir_x * 0.05)] == '1')
		all->plr.pos_y += all->plr.dir_x * 0.05;
}

void	ft_mv_rgt(t_all *all)
{
	if (all->map.map[(int)(all->plr.pos_x + all->plr.dir_y * 0.05)]
		[(int)all->plr.pos_y] == '1')
		all->plr.pos_x += all->plr.dir_y * 0.05;
	if (all->map.map[(int)all->plr.pos_x]
		[(int)(all->plr.pos_y - all->plr.dir_x * 0.05)] == '1')
		all->plr.pos_y -= all->plr.dir_x * 0.05;
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
	if (all->keys.mv_fwd)
		ft_mv_fwd(all);
	if (all->keys.mv_bck)
		ft_mv_bck(all);
	if (all->keys.mv_lft)
		ft_mv_lft(all);
	if (all->keys.mv_rgt)
		ft_mv_rgt(all);
	if (all->keys.rot_lft)
		ft_rot_lft(all);
	if (all->keys.rot_rgt)
		ft_rot_rgt(all);
	if (all->keys.esc)
		ft_shut_down();
//	if (all->keys.mv_fwd || all->keys.mv_bck
//		|| all->keys.mv_lft || all->keys.mv_rgt
//		|| all->keys.rot_lft || all->keys.rot_rgt)
	ft_draw(all);
	return (1);
}

int		ft_key_prs(int key, t_all *all)
{
	if (key == 13)
		all->keys.mv_fwd = 1;
	if (key == 1)
		all->keys.mv_bck = 1;
	if (key == 124)
		all->keys.mv_lft = 1;
	if (key == 123)
		all->keys.rot_lft = 1;
	if (key == 0)
		all->keys.mv_rgt = 1;
	if (key == 2)
		all->keys.rot_rgt = 1;
	if (key == 53)
		all->keys.esc = 1;
	printf("%d\n", key);
	return (1);
}

int		ft_key_rel(int key, t_all *all)
{
	if (key == 13)
		all->keys.mv_fwd = 0;
	if (key == 1)
		all->keys.mv_bck = 0;
	if (key == 124)
		all->keys.mv_lft = 0;
	if (key == 123)
		all->keys.rot_lft = 0;
	if (key == 0)
		all->keys.mv_rgt = 0;
	if (key == 2)
		all->keys.rot_rgt = 0;
	return (1);
}

int		cre_rgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

void	ft_fl_ce_cst(t_all *all)
{
	int y;
	int x;

	x = 0;
	while (x < W / 2)
	{
		y = 0;
		while (y < H)
		{
			my_mlx_pixel_put(all, x, y, all->par.col.ce);
			y++;
		}
		x++;
	}
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			my_mlx_pixel_put(all, x, y, all->par.col.fl);
			y++;
		}
		x++;
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

//int		ft_draw(t_all *all)
//{
//	//WALL CASTING
//	int	x;
//
//	x = -1;
//	while (++x < W)
//	{
//		//calculate ray position and direction
//		all->ray.camera_x = 2 * x / (double) W - 1; //x-coordinate in camera space
//		all->ray.ray_dir_x = all->ray.ray_dir_x +
//				all->plr.plane_x * all->ray.camera_x;
//		all->ray.ray_dir_y = all->ray.ray_dir_y +
//				all->plr.plane_y * all->ray.camera_x;
//
//		//which box of the map we're in
//		all->ray.map_x = (int) (all->plr.pos_x);
//		all->ray.map_y = (int) (all->plr.pos_y);
//
//		//length of ray from one x or y-side to next x or y-side
//		all->ray.delta_dist_x = (all->ray.ray_dir_y == 0) ? 0 :
//				((all->ray.ray_dir_x == 0) ? 1 : fabs(1 /
//				all->ray.ray_dir_x));
//		all->ray.delta_dist_y = (all->ray.ray_dir_x == 0) ? 0 :
//				((all->ray.ray_dir_y == 0) ? 1 : fabs(1 /
//				all->ray.ray_dir_y));
//
//		//what direction to step in x or y-direction (either +1 or -1)
//		all->ray.hit = 0; //was there a wall hit?
//
//		//calculate step and initial sideDist
//		if (all->ray.ray_dir_x < 0)
//		{
//			all->ray.step_x = -1;
//			all->ray.side_dist_x = (all->plr.pos_x - all->ray.map_x) *
//					all->ray.delta_dist_x;
//		}
//		else
//		{
//			all->ray.step_x = 1;
//			all->ray.side_dist_x = (all->ray.map_x + 1.0 - all->plr.pos_x)
//					* all->ray.delta_dist_x;
//		}
//		if (all->ray.ray_dir_y < 0)
//		{
//			all->ray.step_y = -1;
//			all->ray.side_dist_y = (all->plr.pos_y - all->ray.map_y)
//					* all->ray.delta_dist_y;
//		}
//		else
//		{
//			all->ray.step_y = 1;
//			all->ray.side_dist_y = (all->ray.map_y + 1.0 - all->plr.pos_y)
//					* all->ray.delta_dist_y;
//		}
//		//perform DDA
//		while (all->ray.hit == 0)
//		{
//			//jump to next map square, OR in x-direction, OR in y-direction
//			if (all->ray.side_dist_x < all->ray.side_dist_y)
//			{
//				all->ray.side_dist_x += all->ray.delta_dist_x;
//				all->ray.map_x += all->ray.step_x;
//				all->ray.side = 0;
//			}
//			else
//			{
//				all->ray.side_dist_y += all->ray.delta_dist_y;
//				all->ray.map_y += all->ray.step_y;
//				all->ray.side = 1;
//			}
//			//Check if ray has hit a wall
//			if (all->map.map[all->ray.map_x][all->ray.map_y]
//				> 0) all->ray.hit = 1;
////			write(1, "1\n", 2);
//		}
//
//		//Calculate distance of perpendicular ray (Euclidean distance will give fisheye effect!)
//		if (all->ray.side == 0)
//			all->ray.perp_wall_dist = (all->ray.map_x - all->plr.pos_x +
//					(1 - (double)all->ray.step_x) / 2) /
//					all->ray.ray_dir_x;
//		else
//			all->ray.perp_wall_dist =
//					(all->ray.map_y - all->plr.pos_y +
//					(1 - (double)all->ray.step_y) / 2) / all->ray.ray_dir_y;
//
//		//Calculate height of line to draw on screen
//		all->ray.line_height = (int) (H / all->ray.perp_wall_dist);
//
//		//calculate lowest and highest pixel to fill in current stripe
//		all->ray.draw_start = -(all->ray.line_height) / 2 + H / 2;
//		if (all->ray.draw_start < 0) all->ray.draw_start = 0;
//		all->ray.draw_end = all->ray.line_height / 2 + H / 2;
//		if (all->ray.draw_end >= H) all->ray.draw_end = H - 1;
//		//texturing calculations
//		all->ray.tex_num =
//				all->map.map[all->ray.map_x][all->ray.map_y] - 1; //1 subtracted from it so that texture 0 can be used!
//
//		//calculate value of wallX
//		if (all->ray.side == 0) all->ray.wall_x = all->plr.pos_y +
//				all->ray.perp_wall_dist * all->ray.ray_dir_y;
//		else all->ray.wall_x = all->plr.pos_x + all->ray.perp_wall_dist *
//				all->ray.ray_dir_x;
//		all->ray.wall_x -= floor((all->ray.wall_x));
//
//		//x coordinate on the texture
//		all->ray.tex_x = (int) (all->ray.wall_x * (double) (texWidth));
//		if (all->ray.side == 0 && all->ray.ray_dir_x > 0) all->ray.tex_x =
//				texWidth- all->ray.tex_x - 1;
//		if (all->ray.side == 1 && all->ray.ray_dir_y < 0) all->ray.tex_x =
//				texWidth - all->ray.tex_x - 1;
//
//		// How much to increase the texture coordinate per screen pixel
//		all->ray.step = 1.0 * texHeight / all->ray.line_height;
//		// Starting texture coordinate
//		all->ray.tex_pos = (all->ray.draw_start - all->ray.line_height / 2 +
//				all->ray.line_height / 2) * all->ray.step;
//		int y;
//
//		y = --all->ray.draw_start;
//		while (++y < all->ray.draw_end)
//		{
//			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
//			all->ray.tex_y = (int) all->ray.tex_pos & (texHeight - 1);
//			all->ray.tex_pos += all->ray.step;
////			all->ray.color = all->spr.texture[all->ray.tex_num][H * all->ray.tex_y + all->ray.tex_x];
//			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
////			all->ray.buffer[y][x] = all->ray.color;
//			all->ray.color = (unsigned int *) 0x00FFFF;
////			my_mlx_pixel_put(all, x, y, (int)(*all->ray.color));
//			my_mlx_pixel_put(all, x, y, 0x00FFFF);
//		}
//		mlx_put_image_to_window(all->data.mlx, all->data.win, all->data.img, 0, 0);
//		mlx_destroy_image(all->data.mlx, all->data.img);
//		all->data.img = mlx_new_image(all->data.mlx, W, H);
//		all->data.addr = mlx_get_data_addr(all->data.img, \
//        &all->data.bts_per_pxl, &all->data.ln_len, &all->data.endian);
//	}
//	return (0);
//}

int		ft_draw(t_all *all)
{
	int x;

	x = -1;
	while (++x < W)
	{
		all->ray.camera_x = 2 * x / (double)W - 1; //x-coordinate in camera space
		all->ray.ray_dir_x = all->plr.dir_x + all->plr.plane_x*all->ray.camera_x;
		all->ray.ray_dir_y = all->plr.dir_y + all->plr.plane_y*all->ray.camera_x;

		all->ray.map_x = (int)(all->plr.pos_x);
		all->ray.map_y = (int)(all->plr.pos_y);

		all->ray.delta_dist_x = (all->ray.ray_dir_y == 0) ? 0 : ((all->ray.ray_dir_x == 0) ? 1 : fabs(1 / all->ray.ray_dir_x));
		all->ray.delta_dist_y = (all->ray.ray_dir_x == 0) ? 0 : ((all->ray.ray_dir_y == 0) ? 1 : fabs(1 / all->ray.ray_dir_y));

		all->ray.hit = 0;

		if(all->ray.ray_dir_x < 0)
		{
			all->ray.step_x = -1;
			all->ray.side_dist_x = (all->plr.pos_x - all->ray.map_x) * all->ray.delta_dist_x;
		}
		else
		{
			all->ray.step_x = 1;
			all->ray.side_dist_x = (all->ray.map_x + 1.0 - all->plr.pos_x) * all->ray.delta_dist_x;
		}
		if(all->ray.ray_dir_y < 0)
		{
			all->ray.step_y = -1;
			all->ray.side_dist_y = (all->plr.pos_y - all->ray.map_y) * all->ray.delta_dist_y;
		}
		else
		{
			all->ray.step_y = 1;
			all->ray.side_dist_y = (all->ray.map_y + 1.0 - all->plr.pos_y) * all->ray.delta_dist_y;
		}
		//perform DDA
		while (all->ray.hit == 0)
		{
		//jump to next map square, OR in x-direction, OR in y-direction
			if(all->ray.side_dist_x < all->ray.side_dist_y)
			{
				all->ray.side_dist_x += all->ray.delta_dist_x;
				all->ray.map_x += all->ray.step_x;
				all->ray.side = 0;
			}
			else
			{
				all->ray.side_dist_y += all->ray.delta_dist_y;
				all->ray.map_y += all->ray.step_y;
				all->ray.side = 1;
			}
		//Check if ray has hit a wall
			if(WWORLDMAP[all->ray.map_x][all->ray.map_y] > 0) all->ray.hit = 1;
		}

		if(all->ray.side == 0)
			all->ray.perp_wall_dist = (all->ray.map_x - all->plr.pos_x + (1 - all->ray.step_x) / 2) / all->ray.ray_dir_x;
		else
			all->ray.perp_wall_dist = (all->ray.map_y - all->plr.pos_y + (1 - all->ray.step_y) / 2) / all->ray.ray_dir_y;

		//Calculate height of line to draw on screen
		all->ray.line_height = (int)(H / all->ray.perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		all->ray.draw_start = -all->ray.line_height / 2 + H / 2;
		if(all->ray.draw_start < 0) all->ray.draw_start = 0;
			all->ray.draw_end = all->ray.line_height / 2 + H / 2;
		if(all->ray.draw_end >= H)
			all->ray.draw_end = H - 1;

		//texturing calculations
		all->ray.tex_num = WWORLDMAP[all->ray.map_x][all->ray.map_y] - 1; //1 subtracted from it so that texture 0 can be used!

		//calculate value of wallX
		//      all->ray.wall_x; //where exactly the wall was hit
		if(all->ray.side == 0)
			all->ray.wall_x = all->plr.pos_y + all->ray.perp_wall_dist * all->ray.ray_dir_y;
		else
			all->ray.wall_x = all->plr.pos_x + all->ray.perp_wall_dist * all->ray.ray_dir_x;
		all->ray.wall_x -= floor((all->ray.wall_x));

		//x coordinate on the texture
		all->ray.tex_x = (int)(all->ray.wall_x * (double)(texWidth));
		if(all->ray.side == 0 && all->ray.ray_dir_x > 0)
			all->ray.tex_x = texWidth - all->ray.tex_x - 1;
		if(all->ray.side == 1 && all->ray.ray_dir_y < 0)
			all->ray.tex_x = texWidth - all->ray.tex_x - 1;

		// TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
		// How much to increase the texture coordinate per screen pixel
		all->ray.step = 1.0 * texHeight / all->ray.line_height;
		// Starting texture coordinate
		all->ray.tex_pos = (all->ray.draw_start - H / 2 + all->ray.line_height / 2) * all->ray.step;
		for(int y = all->ray.draw_start; y < all->ray.draw_end; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			all->ray.tex_y = (int)all->ray.tex_pos & (texHeight - 1);
			all->ray.tex_pos += all->ray.step;
			all->ray.color = (unsigned int*)(0x00FFFF);
			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			my_mlx_pixel_put(all, x, y, 0x00FFFF);
		}
		mlx_put_image_to_window(all->data.mlx, all->data.win, all->data.img, 0, 0);
		//      mlx_destroy_image(all->data.mlx, all->data.img);
		//      all->data.img = mlx_new_image(all->data.mlx, W, H);
		//      all->data.addr = mlx_get_data_addr(all->data.img, \
		//      &all->data.bts_per_pxl, &all->data.ln_len, &all->data.endian);
		}
		return (0);
}

int		main(int argc, char **argv)
{
	t_all	all;
	int		fd;
	MAP = NULL;
	PAR = NULL;

	fd = open(argv[1], O_RDONLY);
	ft_init_all(&all);
	ft_main_parser(&all,fd, PAR, MAP);
	all.data.mlx = mlx_init();

	all.data.win = mlx_new_window(all.data.mlx, all.par.res.x, all.par.res.y, "rot");
	all.data.img = mlx_new_image(all.data.mlx, all.par.res.x, all.par.res.y);
	all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bts_per_pxl, &all.data.ln_len, &all.data.endian);
	ft_key_init(&all);

	ft_draw(&all);
	mlx_hook(all.data.win, 2, (1L << 0), &ft_key_prs, &all);
	mlx_hook(all.data.win, 3, (1L << 1), &ft_key_rel, &all);
	mlx_loop_hook(all.data.mlx, &ft_key_ev, &all);
	mlx_loop(all.data.mlx);
	return (0);
}