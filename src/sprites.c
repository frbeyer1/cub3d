/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:43:36 by esteiner          #+#    #+#             */
/*   Updated: 2024/06/06 19:49:25 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_sprite_distance(t_player *player, int num_sprites)
{
	double	a;
	double	b;
	int		i;

	i = 0;
	while (i < num_sprites)
	{
		a = player->pos_x - player->spr[i].x;
		b = player->pos_y - player->spr[i].y;
		player->spr[i].distance = sqrt(a * a + b * b);
		i++;
	}
}

void	sort_sprites(t_sprite *sprites, int num_sprites, t_player *player)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	calculate_sprite_distance(player, num_sprites);
	while (i < num_sprites)
	{
		j = 0;
		while (j < num_sprites - i - 1)
		{
			if (sprites[j].distance < sprites[j + 1].distance)
			{
				temp = sprites[j];
				sprites[j] = sprites[j + 1];
				sprites[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	draw_y_line(t_sprite_cast *s, t_player *player, int i)
{
	int	y;

	y = s->draw_start_y;
	while (y < s->draw_end_y)
	{
		s->d = (y - s->placement) * 256 - WINDOW_HEIGHT * 128 + s->s_height
			* 128;
		s->tex_y = ((s->d
					* player->spr[i].img[player->frame].texture_h)
				/ s->s_height) / 256;
		s->color = get_pixel_colour(s->tex_x, s->tex_y,
				&player->spr[i].img[player->frame]);
		if ((s->color & 0x00FFFFFF) != 0)
			my_pixel_put((int)s->x, y, s->color, &player->data);
		y++;
	}
}

void	draw_sprite(t_sprite_cast *s, t_player *player, int i)
{
	s->x = s->draw_start_x;
	while (s->x < s->draw_end_x)
	{
		s->tex_x = (int)(256 * (s->x - (-s->s_width / 2 + s->s_screen_x))
				* player->spr[i].img[player->frame].texture_width
				/ s->s_width) / 256;
		if (s->transform_y > 0 && s->x > 0 && s->x < WINDOW_WIDTH
			&& s->transform_y < player->wall_distances[s->x])
			draw_y_line(s, player, i);
		s->x++;
	}
}

void	calculate_drawing_sprites(t_sprite_cast *s)
{
	s->draw_start_y = (-s->s_height / 2 + WINDOW_HEIGHT / 2) + s->placement;
	if (s->draw_start_y < 0)
		s->draw_start_y = 0;
	s->draw_end_y = (s->s_height / 2 + WINDOW_HEIGHT / 2) + s->placement;
	if (s->draw_end_y >= WINDOW_HEIGHT)
		s->draw_end_y = WINDOW_HEIGHT - 1;
	s->draw_start_x = -s->s_width / 2 + s->s_screen_x;
	if (s->draw_start_x < 0)
		s->draw_start_x = 0;
	s->draw_end_x = s->s_width / 2 + s->s_screen_x;
	if (s->draw_end_x >= WINDOW_WIDTH)
		s->draw_end_x = WINDOW_WIDTH - 1;
}
