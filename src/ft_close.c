/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:39:54 by frbeyer           #+#    #+#             */
/*   Updated: 2024/06/06 21:12:51 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	delete_ea_textures(t_player *player)
{
	if (player->east_tx_path != NULL)
		free(player->east_tx_path);
}

void	delete_we_textures(t_player *player)
{
	if (player->west_tx_path != NULL)
		free(player->west_tx_path);
}

void	delete_so_textures(t_player *player)
{
	if (player->south_tx_path != NULL)
		free(player->south_tx_path);
}

void	delete_no_textures(t_player *player)
{
	if (player->north_tx_path != NULL)
		free(player->north_tx_path);
}

int	ft_close(t_player *player)
{
	int	i;

	if (player->win_ptr)
		mlx_destroy_window(player->mlx_ptr, player->win_ptr);
	if (player->data.img)
		mlx_destroy_image(player->mlx_ptr, player->data.img);
	i = 0;
	while (i < 6)
	{
		if (player->texture[i].img)
			mlx_destroy_image(player->mlx_ptr, player->texture[i].img);
		i++;
	}
	if (player->mlx_ptr != NULL)
	{
		mlx_destroy_display(player->mlx_ptr);
		free(player->mlx_ptr);
	}
	ft_free(player);
	exit(0);
}
