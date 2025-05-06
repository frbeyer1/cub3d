/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:14:56 by frbeyer           #+#    #+#             */
/*   Updated: 2024/06/06 19:56:31 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_map(t_player *player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < player->y_size)
	{
		x = 0;
		while (x < player->x_size)
		{
			printf("%c", player->map[y][x]);
			x++;
		}
		y++;
		printf("\n");
	}
}

void	free_arr(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}

int	ft_free(t_player *player)
{
	delete_no_textures(player);
	delete_ea_textures(player);
	delete_we_textures(player);
	delete_so_textures(player);
	free_arr(player->map);
	return (0);
}

int	get_hex_color(char *line)
{
	char	**str;
	int		r;
	int		g;
	int		b;

	str = ft_split(line + 2, ',');
	if (!str[2])
		return (free_arr(str), 1);
	r = ft_atoi(str[0]);
	g = ft_atoi(str[1]);
	b = ft_atoi(str[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (free_arr(str), 1);
	return (free_arr(str), ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

char	*save_data(char *line)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 3;
	p = ft_calloc(ft_strlen(line), sizeof(char *));
	if (!p)
		return (printf("ERROR - Malloc failed\n"), NULL);
	while (line[j] != '\n')
	{
		p[i] = line[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}
