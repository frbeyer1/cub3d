/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:14:56 by frbeyer           #+#    #+#             */
/*   Updated: 2024/06/06 22:29:01 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**map_alloc(t_player *player)
{
	int		y;
	char	**map;

	y = 0;
	map = ft_calloc(player->y_size + 1, sizeof(char **));
	if (!map)
		return (NULL);
	while (y < player->y_size)
	{
		map[y] = ft_calloc(player->x_size + 1, sizeof(char *));
		if (!map[y])
			return (free_arr(map), NULL);
		y++;
	}
	return (map);
}

void	save_position_2(t_player *player, char direction)
{
	if (direction == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -1 * 1.25;
		player->plane_y = 0;
	}
	if (direction == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0 * 1.25;
		player->plane_y = 1 * 1.25;
	}
	if (direction == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0 * 1.25;
		player->plane_y = -1 * 1.25;
	}
}

int	save_position(t_player *player, char direction, int y, int x)
{
	if (direction == 'V')
	{
		player->spr[player->sprite_counter].x = x;
		player->spr[player->sprite_counter].y = y;
		player->sprite_counter++;
		player->map[y][x] = '0';
		return (0);
	}
	if (player->pos_x != -1 || player->pos_y != -1)
		player->more_than_one_player = true;
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	player->map[y][x] = '0';
	if (direction == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 1 * 1.25;
		player->plane_y = 0 * 1.25;
	}
	save_position_2(player, direction);
	return (0);
}

int	map_copy(t_player *player, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x] != '\n' && line[x])
	{
		if (line[x] == ' ' || line[x] == '1' || line[x] == '0'
			|| line[x] == '2' || line[x] == 'N' || line[x] == 'E'
			|| line[x] == 'S' || line[x] == 'W' || line[x] == 'V')
		{
			if (line[x] == 'N' || line[x] == 'E'
				|| line[x] == 'S' || line[x] == 'W' || line[x] == 'V')
				save_position(player, line[x], y, x);
			else
				player->map[y][x] = line[x];
		}
		else
			return (1);
		x++;
	}
	x--;
	while (x++ < player->x_size - 1)
		player->map[y][x] = ' ' ;
	player->map[y][x] = '\0';
	return (0);
}
