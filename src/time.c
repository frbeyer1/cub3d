/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:35:45 by esteiner          #+#    #+#             */
/*   Updated: 2024/06/04 20:50:27 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_time_seconds(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ((double)ts.tv_sec + (double)ts.tv_nsec / 1e9);
}

void	calculate_delta_time(t_player *player)
{
	player->current_frame_time = get_time_seconds();
	player->delta_time = player->current_frame_time - player->last_frame_time;
	player->last_frame_time = player->current_frame_time;
}
