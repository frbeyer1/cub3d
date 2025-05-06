/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:14:37 by frbeyer           #+#    #+#             */
/*   Updated: 2024/06/06 22:49:21 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int	get_textures_2(char *line, t_player *player)
{
	if (ft_strncmp(line, "SO", 2) == 0)
	{
		delete_so_textures(player);
		player->south_tx_path = save_data(line);
		if (check_xpm_file(player->south_tx_path))
			return (printf("ERROR - texture not in .xpm format\n"), 1);
	}
	if (ft_strncmp(line, "F", 1) == 0)
	{
		player->floor_color = get_hex_color(line);
		if (player->floor_color == 1)
			return (
				printf("ERROR - invalid FLOORCOLOR (min. 0, max. 255)\n"), 1);
	}
	if (ft_strncmp(line, "C", 1) == 0)
	{
		player->ceiling_color = get_hex_color(line);
		if (player->ceiling_color == 1)
			return (
				printf("ERROR - invalid CEILINGCOLOR (min. 0, max. 255)\n"), 1);
		player->stop_flag = true;
	}
	return (0);
}

int	get_textures(char *line, t_player *player)
{
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		delete_no_textures(player);
		player->north_tx_path = save_data(line);
		if (check_xpm_file(player->north_tx_path))
			return (printf("ERROR - texture not in .xpm format\n"), 1);
	}
	if (ft_strncmp(line, "WE", 2) == 0)
	{
		delete_we_textures(player);
		player->west_tx_path = save_data(line);
		if (check_xpm_file(player->west_tx_path))
			return (printf("ERROR - texture not in .xpm format\n"), 1);
	}
	if (ft_strncmp(line, "EA", 2) == 0)
	{
		delete_ea_textures(player);
		player->east_tx_path = save_data(line);
		if (check_xpm_file(player->east_tx_path))
			return (printf("ERROR - texture not in .xpm format\n"), 1);
	}
	if (get_textures_2(line, player))
		return (1);
	return (0);
}

int	file_textures(t_player *player, int fd, char *line, int count)
{
	while (line)
	{
		if (get_textures(line, player))
		{
			count = -1;
			return (free(line), count);
		}
		if (player->stop_flag == true)
			return (free(line), count);
		free (line);
		count++;
		line = get_next_line(fd);
	}
	free (line);
	return (count);
}
