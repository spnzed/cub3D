/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:14:54 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/17 21:16:23 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdbool.h>
# include <math.h>
# include <limits.h>
# include "../lib/libft_gnl/inc/libft.h"
# include "../lib/mlx/mlx.h"

//Mac Keycodes
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

//Linux Keycodes
// # define KEY_ESC 65307
// # define KEY_W 119
// # define KEY_A 97
// # define KEY_S 115
// # define KEY_D 100
// # define KEY_LEFT 65361
// # define KEY_RIGHT 65363

# define X 0
# define Y 1
# define START 0
# define END 1

# define RESET		"\033[0m"
# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"

# define WALL		0xFFFFFF

# define SCALE 64
//Campus
// # define HEIGHT 1080
// # define WIDTH 1920
//Ester
# define HEIGHT 810
# define WIDTH 1380
//Aaron
//# define HEIGHT 890
//# define WIDTH 1470
# define SPEED 2
//Campus SPEED with Linux
//# define SPEED 4

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		r_arr;
	int		l_arr;
}	t_keys;

typedef struct s_img
{
	void	*img;
	int		*img_adr;
	int		str_len;
	int		bpp;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_keys	*keys;
	t_img	img;
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
}	t_mlx;

typedef struct s_map
{
	char	**grid;
	int		grid_pos;
	int		map_size;
	int		size[2];
	int		spawn[2];
	int		*arr;
	int		p[2];
}			t_map;

typedef struct s_parameters
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
}			t_parameters;

typedef struct s_player
{
	float	x;
	float	y;
	float	dir;
	float	dx;
	float	dy;
}	t_player;

typedef struct s_ray
{
	char	wall_or;
	float	len;
	int		map_p;
	float	end[2];
	float	ang;
	int		text_p;
}	t_ray;

typedef struct s_data
{
	char			**scene;
	t_mlx			*mlx;
	t_ray			*ray;
	t_parameters	parameters;
	t_map			map;
	t_player		player;
	t_player		minipl;
}	t_data;

//		Program
int		check_args(int argc, char **argv, t_data *info);
void	draw_wall(t_data *info, int *scr, int ang, int i);
void	get_file(char *file, t_data *info);
int		handle_map(char *file, t_data *info);
int		check_map_char(char **scene, t_data *info);
int		check_map_border(t_data *info, char **scene);
int		check_textures(char **scene, t_data *info);
char	*get_color(char *str, char rgb);
char	**map_to_file(t_data *info, t_map *map, char **file);
void	put_images(t_data *info);
void	put_position(t_data *info);
int		rgb_check(char *channel);
int		ft_press(int keycode, t_mlx *mlx);
int		ft_release(int keycode, t_mlx *mlx);
int		ft_cross(t_mlx *mlx);
void	move_front(t_player *p, t_player *minipl, t_map *m);
void	move_back(t_player *p, t_player *minipl, t_map *m);
void	move_left(t_player *p, t_player *minipl, t_map *m);
void	move_right(t_player *p, t_player *minipl, t_map *m);
void	move_r_arrow(t_data *info);
void	move_l_arrow(t_data *info);
float	deg_to_rad(float d);
float	angle_correction(float ang);
void	mini_map(t_data *info);
int		render(t_data *info);
void	draw_line(int *scr, t_point *pts, int color);
void	init_temp(t_data *info);
void	create_image(t_data *info);
void	init_texture(t_data *info);
void	cast_rays(t_data *info);
void	ray_end_or(t_map *map, t_player *pl, float ang, t_ray *ray);
void	draw_walls(t_data *info);
int		horiz_maplines(t_map *m, t_player *p, float ang, float *end);
void	h_shorter(float *vend, float *hend, t_ray *ray, int h_mpos);
void	upd_end(float *end, float *rd);
int		move_concave(float dx, float dy, t_player *p, t_map *m);
int		back_rd(float *end, float *rd, int i);

//		Utils
int		ft_count_lines(int fd);
int		open_file(char *file);
void	close_file(int fd, char **scene, bool arr);
int		valid_file(char *file);
int		ft_err(char *str);
int		gen_color(int R, int G, int B);
float	angle_correction(float ang);
float	deg_to_rad(float d);
void	player_direction(char c, t_data *info);
int		is_corner(int *scr, int pos);
float	*alloc_floatarr(t_player *p);
float	*ft_all_floatarr(void);

#endif
