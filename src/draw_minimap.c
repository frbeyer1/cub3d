/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:33:34 by frbeyer           #+#    #+#             */
/*   Updated: 2024/06/06 22:30:00 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_player(t_player *player, int divider)
{
	int	x;
	int	y;

	y = 14;
	x = 14;
	while (x++ < 25)
	{
		y = 14;
		while (y++ < 25)
			my_pixel_put(((int)player->pos_x * 30 + x + 5) / divider,
				((int)player->pos_y * 30 + y + 5) / divider,
				0xFFFF00, &player->data);
	}
}

void	draw_right_area(t_player *player, int x, int y, int color)
{
	if (x <= WINDOW_WIDTH && y <= WINDOW_HEIGHT)
		my_pixel_put(x, y, color, &player->data);
}

void	draw_map(t_player *player, int divider)
{
	int	x;
	int	y;
	int	k;
	int	j;

	y = -1;
	while (y++ < player->y_size - 1)
	{
		x = -1;
		while (x++ < player->x_size - 1)
		{
			if (player->map[y][x] == '1')
			{
				k = -1;
				while (k++ < 25)
				{
					j = -1;
					while (j++ < 25)
						draw_right_area(player, (x * 30 + 14 + k) / divider,
							(y * 30 + 14 + j) / divider, 0x000000);
				}
			}
		}
	}
}

void	draw_minimap(t_player *player)
{
	int	divider;
	int	y_size;
	int	x_size;

	divider = 1;
	y_size = player->y_size * 30 + 14;
	x_size = player->x_size * 30 + 14;
	while (y_size > WINDOW_HEIGHT / 3 || x_size > WINDOW_WIDTH / 3)
	{
		divider++;
		y_size /= divider;
		x_size /= divider;
	}
	draw_player(player, divider);
	draw_map(player, divider);
}
