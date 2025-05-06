/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:35:46 by esteiner          #+#    #+#             */
/*   Updated: 2024/06/06 22:42:31 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_sky_and_ground(t_player *player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		while (x < WINDOW_WIDTH)
		{
			my_pixel_put(x, y, player->ceiling_color, &player->data);
			x++;
		}
		x = 0;
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		while (x < WINDOW_WIDTH)
		{
			my_pixel_put(x, y, player->floor_color, &player->data);
			x++;
		}
		x = 0;
		y++;
	}
}

int	get_pixel_colour(int x, int y, t_data *texture)
{
	int	offset;
	int	colour;

	colour = 0;
	offset = y * texture->line_length + x * (texture->bits_per_pixel / 8);
	if (!(x >= 0 && x <= texture->texture_width && y <= texture->texture_h
			&& y >= 0))
		return (0);
	colour |= ((unsigned char)texture->addr[offset]);
	colour |= ((unsigned char)texture->addr[offset + 1]) << 8;
	colour |= ((unsigned char)texture->addr[offset + 2]) << 16;
	return (colour);
}

/*coole funktion die eine vertikale linie malt*/
bool	draw_vertical_line(t_data texture, double x, t_ray *r, t_player *player)
{
	int		i;
	int		y;
	int		colour;
	double	tex_pos;

	i = 0;
	y = WINDOW_HEIGHT / 2 - r->line_height / 2;
	tex_pos = (y - (WINDOW_HEIGHT / 2) + (r->line_height / 2)) * r->step;
	while (i < r->line_height && y < WINDOW_HEIGHT)
	{
		r->texture_y = (int)tex_pos % (texture.texture_h);
		tex_pos += r->step;
		if (y >= 0)
		{
			colour = get_pixel_colour(r->texture_x, r->texture_y, &texture);
			if (colour != BLACK)
				my_pixel_put((int)x, y, colour, &player->data);
		}
		y++;
		i++;
	}
	return (true);
}

void	draw_crosshair(t_player *player)
{
	int	x;
	int	y;
	int	size;

	size = 6;
	x = WINDOW_WIDTH / 2 - size;
	y = WINDOW_HEIGHT / 2;
	while (x <= WINDOW_WIDTH / 2 + size)
	{
		my_pixel_put(x, y, RED, &player->data);
		x++;
	}
	y -= size;
	x = WINDOW_WIDTH / 2;
	while (y <= WINDOW_HEIGHT / 2 + size)
	{
		my_pixel_put(x, y, RED, &player->data);
		y++;
	}
}

void	sprites(t_player *player)
{
	int				i;
	t_sprite_cast	s;

	i = 0;
	sort_sprites(player->spr, 3, player);
	while (i < 3)
	{
		s.s_x = player->spr[i].x - player->pos_x;
		s.s_y = player->spr[i].y - player->pos_y;
		s.inv_det = 1.0 / (player->plane_x * player->dir_y - player->dir_x
				* player->plane_y);
		s.transform_x = s.inv_det * (player->dir_y * s.s_x - player->dir_x
				* s.s_y);
		s.transform_y = s.inv_det * (-player->plane_y * s.s_x + player->plane_x
				* s.s_y);
		s.placement = (int)(player->spr[i].img[player->frame].texture_h
				/ s.transform_y / 8);
		s.s_screen_x = (int)(WINDOW_WIDTH / 2) *(1 + s.transform_x
				/ s.transform_y);
		s.s_height = abs((int)(WINDOW_HEIGHT / (s.transform_y))) / 2;
		s.s_width = abs((int)(WINDOW_HEIGHT / (s.transform_y))) / 4;
		calculate_drawing_sprites(&s);
		draw_sprite(&s, player, i);
		i++;
	}
}
