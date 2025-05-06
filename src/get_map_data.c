/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:14:37 by frbeyer           #+#    #+#             */
/*   Updated: 2024/06/06 21:28:33 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	copy_map(char **av, t_player *player, int count)
{
	int		fd;
	char	*line;
	int		y;

	y = 0;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line && y < player->y_size)
	{
		if (count > 0)
			count--;
		else
		{
			if (map_copy(player, line, y))
				return (printf("ERROR - map not valid\n"), free (line), 1);
			y++;
		}
		free (line);
		line = get_next_line(fd);
	}
	if (player->more_than_one_player == true)
		return (printf("ERROR - more than one player\n"), 1);
	return (0);
}

void	get_map_size(t_player *player, char *line, int fd)
{
	while (line)
	{
		if (player->x_size < (int)ft_strlen(line))
			player->x_size = ft_strlen(line);
		player->y_size++;
		free (line);
		line = get_next_line(fd);
	}
	free (line);
}

int	go_through_file(char **av, t_player *player, int count)
{
	char	*line;
	int		fd;

	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	count = file_textures(player, fd, line, count);
	if (count < 0)
		return (count);
	count++;
	line = get_next_line(fd);
	while (ft_strncmp(line, "\n", 1) == 0)
	{
		free (line);
		count++;
		line = get_next_line(fd);
	}
	player->y_size = 0;
	player->x_size = 0;
	get_map_size(player, line, fd);
	close(fd);
	return (count);
}

int	get_map_data(char **av, t_player *player)
{
	int		count = 0;

	count = go_through_file(av, player, count);
	if (count < 0)
		return (1);
	player->map = map_alloc(player);
	if (!player->map)
		return (printf("ERROR - map alloc failed"), 1);
	if (copy_map(av, player, count))
		return (1);
	if (player->pos_x < 0 || player->pos_y < 0)
		return (printf("ERROR - no player position\n"), 1);
	if (check_if_valid(player))
		return (printf("ERROR - no wall\n"), 1);
	return (0);
}
