/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:55:37 by esteiner          #+#    #+#             */
/*   Updated: 2024/06/06 22:24:38 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	hit_callback(t_ray *r, t_player *player, const double *x)
{
	if (r->side == 0)
		r->perp_wall_dist = (r->side_dist_x - r->delta_dist_x);
	else
		r->perp_wall_dist = (r->side_dist_y - r->delta_dist_y);
	player->wall_distances[(int)*x] = r->perp_wall_dist;
	r->line_height = (int)(WINDOW_HEIGHT / 2 / r->perp_wall_dist);
	texture_calculations(r, player);
	r->step = 1.0 * player->texture[r->texture].texture_h
		/ r->line_height;
	r->tex_width = player->texture[r->texture].texture_width;
	if (*x == WINDOW_WIDTH / 2 && player->map[r->map_y][r->map_x] > '1'
		&& calculate_ray_length(player, r) < 0.7)
	{
		player->door_reachable = true;
		player->door_x = r->map_x;
		player->door_y = r->map_y;
	}
	else if (*x == WINDOW_WIDTH / 2 && player->map[r->map_y][r->map_x] > '1')
		player->door_reachable = false;
	else if (*x == WINDOW_WIDTH / 2 && player->map[r->map_y][r->map_x] < '2')
		player->door_reachable = false;
	return (draw_vertical_line(player->texture[r->texture], *x, r,
			player));
}

void	raycasting(t_player *player, char **map)
{
	double	x;
	t_ray	r;

	(void)map;
	ft_bzero(&r, sizeof(t_ray));
	x = 0;
	player->door_reachable = false;
	while (x < WINDOW_WIDTH)
	{
		r.hit = 0;
		r.camera_x = 2 * x / WINDOW_WIDTH - 1;
		r.ray_dir_x = player->dir_x + player->plane_x * r.camera_x;
		r.ray_dir_y = player->dir_y + player->plane_y * r.camera_x;
		calculate_delta_dist(&r, player);
		get_direction(&r, player);
		dda_loop(&r, player, (t_fn_ray_hit_cb)hit_callback, &x);
		x += 1;
	}
	draw_crosshair(player);
}

void	texture_calculations(t_ray *r, t_player *player)
{
	texture_index(r, player);
	if (r->side == 0)
	{
		r->texture_x = (int)(r->wall_hit * (double)(r->tex_width));
		if (r->ray_dir_x < 0)
			r->texture_x = r->tex_width - r->texture_x - 1;
	}
	else
	{
		r->texture_x = (int)(r->wall_hit * (double)(r->tex_width));
		if (r->ray_dir_y > 0)
			r->texture_x = r->tex_width - r->texture_x - 1;
	}
	if (r->side == 0)
		r->wall_hit = player->pos_y + r->perp_wall_dist * r->ray_dir_y;
	else
		r->wall_hit = player->pos_x + r->perp_wall_dist * r->ray_dir_x;
	r->wall_hit -= floor((r->wall_hit));
}

void	dda_loop(t_ray *r, t_player *player, bool (*callback)(t_ray *,
			t_player *, void *), void *cb_data)
{
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (!player->map[r->map_y] || !player->map[r->map_y][r->map_x])
			return ;
		if (player->map[r->map_y][r->map_x] > '0')
			r->hit = callback(r, player, cb_data);
	}
}

void	get_direction(t_ray *r, t_player *player)
{
	r->map_x = player->pos_x;
	r->map_y = player->pos_y;
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (player->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - player->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (player->pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - player->pos_y) * r->delta_dist_y;
	}
}
