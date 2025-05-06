/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+	+#+           */
/*   Created: 2024/04/06 14:27:20 by esteiner          #+#    #+#             */
/*   Updated: 2024/04/30 16:46:28 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>
#include "./minilibx-linux/mlx.h"

# define WINDOW_HEIGHT 1600
# define WINDOW_WIDTH 2100
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define LIGHT_GREEN 0x32CD32
# define LIGHT_BLUE 0x4682B4
# define RED 0xFF0000
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define YELLOW 0xFFFF00
# define GRAY 0x474A51
# define LEFT 0
# define RIGHT 1
# define W_KEY 2
# define S_KEY 3
# define A_KEY 4
# define D_KEY 5
# define CLOCK_MONOTONIC 1

typedef struct raycasting_data
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		hit;
	int		side;
	int		step_x;
	int		step_y;
	double	perp_wall_dist;
	int		line_height;
	int		texture;
	double	wall_hit;
	double	step;
	int		tex_width;
	int		texture_x;
	int		texture_y;
}	t_ray;

typedef struct sprite_casting_data
{
	int		placement;
	double	s_x;
	double	s_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		s_screen_x;
	int		s_height;
	int		s_width;
	int		draw_start_y;
	int		draw_end_y;
	int		draw_start_x;
	int		draw_end_x;
	int		x;
	int		tex_x;
	int		d;
	int		tex_y;
	int		color;
}	t_sprite_cast;

typedef struct s_image_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		texture_width;
	int		texture_h;
}	t_data;

typedef struct s_sprite_data
{
	t_data	img[13];
	int		x;
	int		y;
	double	distance;
}	t_sprite;

typedef struct s_player_data
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	char		**map;
	int			x_size;
	int			y_size;
	double		plane_x;
	double		plane_y;
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		data;
	bool		key_state[6];
	int			speed_control;
	char		*north_tx_path;
	char		*east_tx_path;
	char		*west_tx_path;
	char		*south_tx_path;
	int			floor_color;
	int			ceiling_color;
	bool		stop_flag;
	t_data		texture[6];
	int			mouse_x;
	int			mouse_y;
	double		mouse_distance;
	double		current_frame_time;
	double		delta_time;
	double		last_frame_time;
	double		sprint;
	t_data		door_texture;
	bool		door_open;
	bool		door_reachable;
	int			door_x;
	int			door_y;
	t_sprite	spr[3];
	double		wall_distances[WINDOW_WIDTH];
	double		animation_timer;
	int			frame;
	int			flag;
	bool		more_than_one_player;
	int			sprite_counter;
}	t_player;

typedef bool	(*t_fn_ray_hit_cb)(t_ray *, t_player *, void *);

// parser
int		parser(t_player *player, int ac, char **av);
int		get_map_data(char **av, t_player *player);
int		file_textures(t_player *player, int fd, char *line, int count);
void	print_map(t_player *player);
int		map_copy(t_player *player, char *line, int y);
char	**map_alloc(t_player *player);
void	free_arr(char **str);
char	*save_data(char *line);
int		get_hex_color(char *line);
int		check_if_valid(t_player *player);
int		check_if_complete(char **av, t_player *player);
int		check_xpm_file(char *str);
int		ft_close(t_player *player);
void	delete_no_textures(t_player *player);
void	delete_ea_textures(t_player *player);
void	delete_so_textures(t_player *player);
void	delete_we_textures(t_player *player);

bool	draw_vertical_line(t_data texture, double x, t_ray *r,
			t_player *player);
void	draw_minimap(t_player *player);

/* raycasting */
void	raycasting(t_player *player, char **map);
void	texture_calculations(t_ray *r, t_player *player);
void	texture_index(t_ray *r, t_player *player);
void	dda_loop(t_ray *r, t_player *player, bool (*callback)(t_ray *,
				t_player *, void *), void *cb_data);
void	get_direction(t_ray *r, t_player *player);
void	calculate_delta_dist(t_ray *r, t_player *player);
bool	hit_callback(t_ray *r, t_player *player, const double *x);
double	calculate_ray_length(t_player *player, t_ray *r);

void	new_frame(t_player *player);

int		key_state_check(t_player *player);
void	look_right(t_player *player, double rotSpeed);
void	look_left(t_player *player, double rotSpeed);
int		ft_keypress_input(int keysym, t_player *player);
int		ft_keyrelease_input(int keysym, t_player *player);

void	draw_sky_and_ground(t_player *player);
void	my_pixel_put(int x, int y, int color, t_data *data);
int		get_pixel_colour(int x, int y, t_data *texture);

int		mouse_move(int x, int y, t_player *player);
int		loop_hook(t_player *player);

double	get_time_seconds(void);
void	calculate_delta_time(t_player *player);
void	draw_crosshair(t_player *player);

// sprites
//void	draw_sprite_pixel(int stripe, int spriteHeight, t_player *player,
//int spriteScreenX, int spriteWidth, double texWidth, double texHeight);
void	sprites(t_player *player);
void	animation_frames(t_player *player);
void	draw_sprite(t_sprite_cast *s, t_player *player, int i);
void	calculate_drawing_sprites(t_sprite_cast *s);
void	draw_y_line(t_sprite_cast *s, t_player *player, int i);
void	sort_sprites(t_sprite *sprites, int num_sprites, t_player *player);
void	calculate_sprite_distance(t_player *player, int num_sprites);

void	move_forward(t_player *player, double move_speed);
void	move_backward(t_player *player, double move_speed);
void	move_left(t_player *player, double move_speed);
void	move_right(t_player *player, double move_speed);

int		is_in_map(t_player *player, double x, double y);
void	doors_handling(t_player *player);

void	initalise_values(t_player *player);
int		initialise_textures(t_player *player);
void	initialise_textures2(t_player *player);
void	initialise_textures3(t_player *player);
void	initalise_sprites(t_player *player);

int		ft_close(t_player *player);
int		ft_free(t_player *player);

#endif