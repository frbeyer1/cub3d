/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:38:07 by esteiner          #+#    #+#             */
/*   Updated: 2024/06/06 16:39:27 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	loop_hook(t_player *player)
{
	double	rot_speed;
	double	move_speed;

	calculate_delta_time(player);
	rot_speed = 1 * player->delta_time;
	move_speed = player->sprint * player->delta_time;
	if (player->key_state[W_KEY] == true)
		move_forward(player, move_speed);
	if (player->key_state[A_KEY] == true)
		move_left(player, move_speed);
	if (player->key_state[S_KEY] == true)
		move_backward(player, move_speed);
	if (player->key_state[D_KEY] == true)
		move_right(player, move_speed);
	if (player->key_state[LEFT] == true)
		look_left(player, rot_speed);
	if (player->key_state[RIGHT] == true)
		look_right(player, rot_speed);
	if (player->delta_time > 0.02)
		new_frame(player);
	animation_frames(player);
	return (0);
}

int	mouse_move(int x, int y, t_player *player)
{
	double	mouse_distance;
	double	rot_speed;

	(void)y;
	mouse_distance = abs(x - WINDOW_WIDTH / 2);
	rot_speed = 0.0003 * mouse_distance;
	if (rot_speed > 0.08)
		rot_speed = 0.08;
	if (x > WINDOW_WIDTH / 2)
	{
		look_right(player, rot_speed);
	}
	else if (x < WINDOW_WIDTH / 2)
	{
		look_left(player, rot_speed);
	}
	mlx_mouse_move(player->mlx_ptr, player->win_ptr, WINDOW_WIDTH / 2,
		WINDOW_HEIGHT / 2);
	return (0);
}

int	ft_keypress_input(int keysym, t_player *player)
{
	if (keysym == XK_Escape)
		ft_close(player);
	if (keysym == XK_Left)
		player->key_state[LEFT] = true;
	if (keysym == XK_Right)
		player->key_state[RIGHT] = true;
	if (keysym == XK_W || keysym == XK_w)
		player->key_state[W_KEY] = true;
	if (keysym == XK_S || keysym == XK_s)
		player->key_state[S_KEY] = true;
	if (keysym == XK_A || keysym == XK_a)
		player->key_state[A_KEY] = true;
	if (keysym == XK_D || keysym == XK_d)
		player->key_state[D_KEY] = true;
	if (keysym == XK_Shift_L)
		player->sprint = 2;
	if (keysym == XK_E || keysym == XK_e)
		doors_handling(player);
	return (0);
}

int	ft_keyrelease_input(int keysym, t_player *player)
{
	if (keysym == XK_Left)
		player->key_state[LEFT] = false;
	if (keysym == XK_Right)
		player->key_state[RIGHT] = false;
	if (keysym == XK_W || keysym == XK_w)
		player->key_state[W_KEY] = false;
	if (keysym == XK_S || keysym == XK_s)
		player->key_state[S_KEY] = false;
	if (keysym == XK_A || keysym == XK_a)
		player->key_state[A_KEY] = false;
	if (keysym == XK_D || keysym == XK_d)
		player->key_state[D_KEY] = false;
	if (keysym == XK_Shift_L)
		player->sprint = 1;
	return (0);
}

void	animation_frames(t_player *player)
{
	player->animation_timer += player->delta_time;
	if (player->animation_timer > 0.1)
	{
		player->animation_timer = 0;
		player->frame++;
		if (player->frame > 12)
			player->frame = 0;
	}
}
