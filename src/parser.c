/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:15:01 by frbeyer           #+#    #+#             */
/*   Updated: 2024/06/06 19:47:36 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_xpm_file(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_strchr(str, '.');
	if (!ret)
		return (1);
	if ((ft_strncmp(&ret[i + 1], "x", 1) == 0)
		&& (ft_strncmp(&ret[i + 2], "p", 1) == 0)
		&& (ft_strncmp(&ret[i + 3], "m", 1) == 0)
		&& (ft_strncmp(&ret[i + 4], "\0", 1) == 0))
		return (0);
	return (1);
}

int	check_format(char *av)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_strchr(&av[i], '.');
	if ((ft_strncmp(&ret[i + 1], "c", 1) == 0)
		&& (ft_strncmp(&ret[i + 2], "u", 1) == 0)
		&& (ft_strncmp(&ret[i + 3], "b", 1) == 0)
		&& (ft_strncmp(&ret[i + 4], "\0", 1) == 0))
		return (0);
	return (1);
}

int	parser(t_player	*player, int ac, char **av)
{
	player->stop_flag = false;
	if (ac == 2)
	{
		if (check_format(av[1]))
			return (printf("ERROR - worng format\n"), 1);
		if (check_if_complete(av, player))
			return (printf("ERROR - file incomplete\n"), 1);
		if (get_map_data(av, player))
			return (1);
	}
	else
		return (printf
			("ERROR - input program name and map in *.cub format\n"), 1);
	return (0);
}
