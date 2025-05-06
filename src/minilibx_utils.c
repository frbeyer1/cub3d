/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:51:16 by esteiner          #+#    #+#             */
/*   Updated: 2024/06/06 20:59:50 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_pixel_put(int x, int y, int color, t_data *data)
{
	int		offset;
	char	*dst;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}
