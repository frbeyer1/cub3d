/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:40:32 by esteiner          #+#    #+#             */
/*   Updated: 2024/06/06 21:34:26 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	calculate_ray_length(t_player *player, t_ray *r)
{
	double	hit_x;
	double	hit_y;
	double	dx;
	double	dy;

	hit_x = player->pos_x + r->perp_wall_dist * r->ray_dir_x;
	hit_y = player->pos_y + r->perp_wall_dist * r->ray_dir_y;
	dx = hit_x - player->pos_x;
	dy = hit_y - player->pos_y;
	return (sqrt(dx * dx + dy * dy));
}

void	calculate_delta_dist(t_ray *r, t_player *player)
{
	(void)player;
	if (r->ray_dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1 / r->ray_dir_x);
	if (r->ray_dir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1 / r->ray_dir_y);
}

void	texture_index(t_ray *r, t_player *player)
{
	r->texture_x = 0;
	if (r->side == 1)
		r->texture = 0;
	if (r->side == 0)
		r->texture = 1;
	if (r->side == 1 && r->ray_dir_y > 0)
		r->texture = 2;
	if (r->side == 0 && r->ray_dir_x < 0)
		r->texture = 3;
	if (player->map[r->map_y][r->map_x] == '2')
		r->texture = 4;
	if (player->map[r->map_y][r->map_x] == '3')
		r->texture = 5;
}
