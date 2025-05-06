/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:42:57 by esteiner          #+#    #+#             */
/*   Updated: 2024/06/06 16:43:26 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_player *player, double move_speed)
{
	double	temp_x;
	double	temp_y;

	temp_y = player->pos_x + player->dir_x * move_speed;
	temp_x = player->pos_y + player->dir_y * move_speed;
	if (is_in_map(player, temp_x, temp_y) == 0)
	{
		player->pos_x += player->dir_x * move_speed;
		player->pos_y += player->dir_y * move_speed;
	}
}

void	move_backward(t_player *player, double move_speed)
{
	double	temp_x;
	double	temp_y;

	temp_y = player->pos_x - player->dir_x * move_speed;
	temp_x = player->pos_y - player->dir_y * move_speed;
	if (is_in_map(player, temp_x, temp_y) == 0)
	{
		player->pos_x -= player->dir_x * move_speed;
		player->pos_y -= player->dir_y * move_speed;
	}
}

void	move_left(t_player *player, double move_speed)
{
	double	temp_x;
	double	temp_y;

	temp_y = player->pos_x + player->dir_y * move_speed;
	temp_x = player->pos_y + -player->dir_x * move_speed;
	if (is_in_map(player, temp_x, temp_y) == 0)
	{
		player->pos_x += player->dir_y * move_speed;
		player->pos_y += -player->dir_x * move_speed;
	}
}

void	move_right(t_player *player, double move_speed)
{
	double	temp_x;
	double	temp_y;

	temp_y = player->pos_x + -player->dir_y * move_speed;
	temp_x = player->pos_y + player->dir_x * move_speed;
	if (is_in_map(player, temp_x, temp_y) == 0)
	{
		player->pos_x += -player->dir_y * move_speed;
		player->pos_y += player->dir_x * move_speed;
	}
}
