/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:35:41 by esteiner          #+#    #+#             */
/*   Updated: 2024/06/06 22:43:24 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>
//#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	new_frame(t_player *player)
{
	draw_sky_and_ground(player);
	raycasting(player, player->map);
	sprites(player);
	draw_minimap(player);
	mlx_put_image_to_window(player->mlx_ptr, player->win_ptr, player->data.img,
		0, 0);
}

void	mlx_sprites_img(t_player *player, int i, int j, char *path)
{
	player->spr[i].img[j].img = mlx_xpm_file_to_image(player->mlx_ptr, path,
			&player->spr[i].img[j].texture_width,
			&player->spr[i].img[j].texture_h);
	player->spr[i].img[j].addr = mlx_get_data_addr(player->spr[i].img[j].img,
			&player->spr[i].img[j].bits_per_pixel,
			&player->spr[i].img[j].line_length, &player->spr[i].img[j].endian);
}

void	sprites1(t_player *player, int i)
{
	mlx_sprites_img(player, i, 0, "spr/1.xpm");
	mlx_sprites_img(player, i, 1, "spr/2.xpm");
	mlx_sprites_img(player, i, 2, "spr/3.xpm");
	mlx_sprites_img(player, i, 3, "spr/4.xpm");
	mlx_sprites_img(player, i, 4, "spr/5.xpm");
	mlx_sprites_img(player, i, 5, "spr/6.xpm");
	mlx_sprites_img(player, i, 6, "spr/7.xpm");
	mlx_sprites_img(player, i, 7, "spr/8.xpm");
	mlx_sprites_img(player, i, 8, "spr/9.xpm");
	mlx_sprites_img(player, i, 9, "spr/10.xpm");
	mlx_sprites_img(player, i, 10, "spr/11.xpm");
	mlx_sprites_img(player, i, 11, "spr/12.xpm");
	mlx_sprites_img(player, i, 12, "spr/13.xpm");
}

void	initalise_sprites(t_player *player)
{
	int	i;

	player->frame = 0;
	i = 0;
	while (i < 3)
	{
		sprites1(player, i);
		player->spr[i].distance = 0;
		i++;
	}
}

// void	texture_error_free(t_player *player)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 6)
// 	{
// 		if (player->img[i].img != NULL)
// 			mlx_destroy_image(player->mlx_ptr, player->img[i].img);
// 		i++;
// 	}
// 	mlx_destroy_display(player->mlx_ptr);
// 	free(player->mlx_ptr);
// 	free_arr(player->map);
// 	if (player->north_tx_path != NULL)
// 		free(player->north_tx_path);
// 	if (player->east_tx_path != NULL)
// 		free(player->east_tx_path);
// 	if (player->west_tx_path != NULL)
// 		free(player->west_tx_path);
// 	if (player->south_tx_path != NULL)
// 		free(player->south_tx_path);
// }

int	main(int ac, char **av)
{
	t_player	player;

	player.pos_x = -1;
	player.pos_y = -1;
	player.more_than_one_player = false;
	player.sprite_counter = 0;
	if (parser(&player, ac, av))
		return (ft_free(&player), 1);
	player.sprint = 1;
	player.door_open = false;
	player.mlx_ptr = mlx_init();
	if (initialise_textures(&player) == 1)
		return (ft_close(&player), 1);
	player.win_ptr = mlx_new_window(player.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Cub3d Window");
	initalise_values(&player);
	mlx_hook(player.win_ptr, 17, 1L << 5, ft_close, &player);
	mlx_hook(player.win_ptr, 2, 1L << 0, ft_keypress_input, &player);
	mlx_hook(player.win_ptr, 3, 1L << 1, ft_keyrelease_input, &player);
	mlx_hook(player.win_ptr, 6, 1L << 6, mouse_move, &player);
	mlx_loop_hook(player.mlx_ptr, loop_hook, &player);
	mlx_loop(player.mlx_ptr);
	return (0);
}
