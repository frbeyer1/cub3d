/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:14:49 by esteiner          #+#    #+#             */
/*   Updated: 2024/06/06 21:33:23 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initalise_values(t_player *player)
{
	int	i;

	player->data.img = mlx_new_image(player->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	player->data.addr = mlx_get_data_addr(player->data.img,
			&player->data.bits_per_pixel, &player->data.line_length,
			&player->data.endian);
	i = 0;
	while (i < 6)
	{
		player->key_state[i] = false;
		i++;
	}
	player->speed_control = 0;
	mlx_mouse_hide(player->mlx_ptr, player->win_ptr);
}

int	initialise_textures(t_player *player)
{
	int	i;

	i = 0;
	initialise_textures2(player);
	while (i < 6)
	{
		if (player->texture[i].img == NULL)
			return (perror("While trying to read texture"), 1);
		i++;
	}
	initialise_textures3(player);
	initalise_sprites(player);
	return (0);
}

void	initialise_textures2(t_player *player)
{
	player->texture[0].img = mlx_xpm_file_to_image(player->mlx_ptr,
			player->north_tx_path, &player->texture[0].texture_width,
			&player->texture[0].texture_h);
	player->texture[1].img = mlx_xpm_file_to_image(player->mlx_ptr,
			player->east_tx_path, &player->texture[1].texture_width,
			&player->texture[1].texture_h);
	player->texture[2].img = mlx_xpm_file_to_image(player->mlx_ptr,
			player->west_tx_path, &player->texture[2].texture_width,
			&player->texture[2].texture_h);
	player->texture[3].img = mlx_xpm_file_to_image(player->mlx_ptr,
			player->south_tx_path, &player->texture[3].texture_width,
			&player->texture[3].texture_h);
	player->texture[5].img = mlx_xpm_file_to_image(player->mlx_ptr,
			"./textures/portal.xpm", &player->texture[5].texture_width,
			&player->texture[5].texture_h);
	player->texture[4].img = mlx_xpm_file_to_image(player->mlx_ptr,
			"textures/door.xpm", &player->texture[4].texture_width,
			&player->texture[4].texture_h);
}

void	initialise_textures3(t_player *player)
{
	player->texture[0].addr = mlx_get_data_addr(player->texture[0].img,
			&player->texture[0].bits_per_pixel, &player->texture[0].line_length,
			&player->texture[0].endian);
	player->texture[1].addr = mlx_get_data_addr(player->texture[1].img,
			&player->texture[1].bits_per_pixel, &player->texture[1].line_length,
			&player->texture[1].endian);
	player->texture[2].addr = mlx_get_data_addr(player->texture[2].img,
			&player->texture[2].bits_per_pixel, &player->texture[2].line_length,
			&player->texture[2].endian);
	player->texture[3].addr = mlx_get_data_addr(player->texture[3].img,
			&player->texture[3].bits_per_pixel, &player->texture[3].line_length,
			&player->texture[3].endian);
	player->texture[5].addr = mlx_get_data_addr(player->texture[5].img,
			&player->texture[5].bits_per_pixel, &player->texture[5].line_length,
			&player->texture[5].endian);
	player->texture[4].addr = mlx_get_data_addr(player->texture[4].img,
			&player->texture[4].bits_per_pixel, &player->texture[4].line_length,
			&player->texture[4].endian);
}
