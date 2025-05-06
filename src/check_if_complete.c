/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_complete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:14:15 by frbeyer           #+#    #+#             */
/*   Updated: 2024/06/06 22:03:15 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*check_if_complete2(t_player *player, char *line, char *str, int fd)
{
	if (ft_strncmp(line, str, 2) == 0)
	{
		player->flag += 1;
		free (line);
		line = get_next_line(fd);
		while (ft_strncmp(line, str, 2) == 0 && line)
		{
			free (line);
			line = get_next_line(fd);
		}
	}
	return (line);
}

int	check_if_complete(char **av, t_player *player)
{
	char	*line;
	int		fd;

	player->flag = 0;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = check_if_complete2(player, line, "NO", fd);
		line = check_if_complete2(player, line, "SO", fd);
		line = check_if_complete2(player, line, "WE", fd);
		line = check_if_complete2(player, line, "EA", fd);
		line = check_if_complete2(player, line, "F ", fd);
		line = check_if_complete2(player, line, "C ", fd);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	free (line);
	if (player->flag == 6)
		return (0);
	else
		return (1);
}
