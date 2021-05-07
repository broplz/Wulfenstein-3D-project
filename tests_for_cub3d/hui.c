#include "header.h"
void draw_start_end_y(t_all *all)
{
	all->sprite->draw_start_y = -all->sprite->sprite_height
								/ 2 + all->sett->resolution_y / 2;
	if (all->sprite->draw_start_y < 0)
		all->sprite->draw_start_y = 0;
	all->sprite->draw_end_y = all->sprite->sprite_height
							  / 2 + all->sett->resolution_y / 2;
	if (all->sprite->draw_end_y >= all->sett->resolution_y)
		all->sprite->draw_end_y = all->sett->resolution_y - 1;
}
void draw_start_end_x(t_all *all)
{
	all->sprite->draw_start_x = -all->sprite->sprite_width
								/ 2 + all->sprite->sprite_screen_x;
	if (all->sprite->draw_start_x < 0)
		all->sprite->draw_start_x = 0;
	all->sprite->draw_end_x = all->sprite->sprite_width
							  / 2 + all->sprite->sprite_screen_x;
	if (all->sprite->draw_end_x >= all->sett->resolution_x)
		all->sprite->draw_end_x = all->sett->resolution_x - 1;
}
void drawing_sprites_y(t_all *all)
{
	int color;
	all->sprite->y = all->sprite->draw_start_y;
	while (all->sprite->y < all->sprite->draw_end_y)
	{
		all->sprite->d = all->sprite->y * 256 - all->sett->resolution_y
												* 128 + all->sprite->sprite_height * 128;
		all->sprite->tex_y = ((all->sprite->d * all->t_sp->height)
							  / all->sprite->sprite_height) / 256;
		color = *(int *)(all->t_sp->addr + (all->sprite->tex_y * all->t_sp->l_l
											+ all->sprite->tex_x * (all->t_sp->b_per_pixel / 8)));
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_p_put(all->wind, all->sprite->stripe, all->sprite->y, color);
		all->sprite->y++;
	}
}
void drawing_sprites(t_all *all)
{
	all->sprite->stripe = all->sprite->draw_start_x;
	while (all->sprite->stripe < all->sprite->draw_end_x)
	{
		all->sprite->tex_x = (int)(256 * (all->sprite->stripe -
										  (-all->sprite->sprite_width / 2 + all->sprite->sprite_screen_x))
								   * all->t_sp->width / all->sprite->sprite_width) / 256;
		if (all->sprite->transform_y > 0 && all->sprite->stripe > 0
			&& all->sprite->stripe < all->sett->resolution_x
			&& all->sprite->transform_y < all->ray->buffer[all->sprite->stripe])
			drawing_sprites_y(all);
		all->sprite->stripe++;
	}
}
void calculate_sprite_param(t_all *all)
{
	all->sprite->inv_det = 1.0 / (all->ray->plane_x
								  * all->ray->dir_y - all->ray->dir_x * all->ray->plane_y);
	all->sprite->transform_x = all->sprite->inv_det * (all->ray->dir_y
													   * all->sprite->sprite_x
													   - all->ray->dir_x * all->sprite->sprite_y);
	all->sprite->transform_y = all->sprite->inv_det * (-all->ray->plane_y
													   * all->sprite->sprite_x
													   + all->ray->plane_x * all->sprite->sprite_y);
	all->sprite->sprite_screen_x = (int)(all->sett->resolution_x / 2)
								   * (1 + all->sprite->transform_x / all->sprite->transform_y);
	all->sprite->sprite_height = abs((int)(all->sett->resolution_x
										   * 0.66 / (all->sprite->transform_y)));
	all->sprite->sprite_width = abs((int)(all->sett->resolution_x
										  * 0.66 / (all->sprite->transform_y)));
	draw_start_end_y(all);
	draw_start_end_x(all);
	drawing_sprites(all);
}
#include "header.h"
void raycast_sprites(t_all *all)
{
	int i;
	if (all->sett->cnt)
	{
		quick_sort(all, 0, all->sett->cnt - 1);
		i = 0;
		while (i < all->sett->cnt)
		{
			all->sprite->sprite_x = all->loc[i].x - all->ray->pos_x;
			all->sprite->sprite_y = all->loc[i].y - all->ray->pos_y;
			calculate_sprite_param(all);
			i++;
		}
	}
}