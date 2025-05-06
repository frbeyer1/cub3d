/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:14:30 by frbeyer           #+#    #+#             */
/*   Updated: 2024/06/06 22:25:25 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	show_map(t_player *player, char **map)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	printf("\e[1;1H\e[2J");
// 	while (y < player->y_size)
// 	{
// 		x = 0;
// 		while (x < player->x_size)
// 		{
// 			if (map[y][x] == 'F')
// 				printf("\033[1;31m");
// 			printf("%c", map[y][x]);
// 			printf("\033[0m");
// 			x++;
// 		}
// 		y++;
// 		printf("\n");
// 	}
// 	printf("\n");
// }

//	usleep(2000);
//	show_map(player, map);

static int	flood_fill(t_player *player, char **map, int x, int y)
{
	if (map[y][x] == ' ' || map[y] == NULL || map[y][x] == 0)
		return (0);
	if (x < 0 || y < 0)
		return (0);
	if (map[y][x] == 'F' || map[y][x] == '1')
		return (1);
	map[y][x] = 'F';
	return (flood_fill(player, map, x - 1, y)
		&& flood_fill(player, map, x, y - 1)
		&& flood_fill(player, map, x + 1, y)
		&& flood_fill(player, map, x, y + 1));
}

int	check_if_valid(t_player *player)
{
	char			**copy_map;
	int				y;
	int				x;
	int				ret;

	x = 0;
	copy_map = map_alloc(player);
	y = -1;
	while (++y < player->y_size)
	{
		x = 0;
		while (x < player->x_size)
		{
			copy_map[y][x] = player->map[y][x];
			x++;
		}
		copy_map[y][x] = '\0';
	}
	copy_map[y] = NULL;
	if (!flood_fill(player, copy_map, player->pos_x, player->pos_y))
		ret = 1;
	else
		ret = 0;
	free_arr(copy_map);
	return (ret);
}
