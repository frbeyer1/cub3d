/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:23:35 by esteiner          #+#    #+#             */
/*   Updated: 2024/06/06 20:49:24 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_in_map(t_player *player, double x, double y)
{
	double	buffer;

	buffer = 0.3;
	if ((player->map[(int)(x + buffer)][(int)(y + buffer)] != '1'
			&& player->map[(int)(x - buffer)][(int)(y - buffer)] != '1'
            && player->map[(int)(x - buffer)][(int)(y + buffer)] != '1'
            && player->map[(int)(x + buffer)][(int)(y - buffer)] != '1')
		&& (player->map[(int)(x + buffer)][(int)(y + buffer)] != '2'
			&& player->map[(int)(x - buffer)][(int)(y - buffer)] != '2'))
		return (0);
	return (1);
}

void	look_right(t_player *player, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed) - player->dir_y
		* sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed) - player->plane_y
		* sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed) + player->plane_y
		* cos(rot_speed);
}

void	look_left(t_player *player, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-rot_speed) - player->dir_y
		* sin(-rot_speed);
	player->dir_y = old_dir_x * sin(-rot_speed) + player->dir_y
		* cos(-rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-rot_speed) - player->plane_y
		* sin(-rot_speed);
	player->plane_y = old_plane_x * sin(-rot_speed) + player->plane_y
		* cos(-rot_speed);
}

void	doors_handling(t_player *player)
{
	if (player->door_reachable == true && player->door_open == false)
	{
		player->door_open = true;
		player->map[player->door_y][player->door_x] = '3';
	}
	else if (player->door_reachable == true && player->door_open == true)
	{
		player->door_open = false;
		player->map[player->door_y][player->door_x] = '2';
	}
}
