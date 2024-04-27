/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:14:54 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/27 13:14:00 by erosas-c         ###   ########.fr       */
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
# include "../lib/libft_gnl/inc/libft.h"
# include "../lib/mlx/mlx.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define RESET		"\033[0m"
# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"

# define SCALE 64
# define HEIGHT 1080
# define WIDTH 1920
//# define HEIGHT 400
//# define WIDTH 800
# define SPEED 3

typedef struct s_sq
{
	void	*sq_ptr;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_squ;

typedef struct s_keys
{
	int	W;
	int	A;
	int	S;
	int	D;
	int	R_ARR;
	int	L_ARR;
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
	char		**grid;
	int			grid_pos;
	int			map_size;
	int			scale;
	int			size[2];
	int			spawn[2];
	int			player_dir;
	int			floor;
	int			ceiling;
}				t_map;

typedef struct s_parameters
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
}				t_parameters;

typedef struct s_player
{
	float	x;
	float	y;
	int		p_dir;
	int		p_dir_x_cos;
	int		p_dir_y_sin;
}	t_player;

typedef struct s_data
{
	char			**scene;
	t_mlx			*mlx;
	t_parameters	parameters;
	t_map			map;
	t_player		player;
}					t_data;

//		Program
int		check_args(int argc, char **argv, t_data *info);
void	get_file(char *file, t_data *info);
int		handle_map(char *file, t_data *info);
int		check_map_char(char **scene, t_data *info);
int		check_map_border(char **scene);
int		check_textures(char **scene, t_data *info);
char	*get_color(char *str, char rgb);
char	**map_to_file(t_data *info, t_map *map, char **file);
void	put_images(t_data *info);
void	put_position(t_data *info);
int		rgb_check(char *channel);
int		ft_press(int keycode, t_mlx *mlx);
int		ft_release(int keycode, t_mlx *mlx);
int		ft_esc(int keycode, t_mlx *mlx);
int		ft_cross(t_mlx *mlx);
void	move_right(t_data *info);
void	move_left(t_data *info);
void	move_front(t_data *info);
void	move_back(t_data *info);
void	move_r_arrow(t_data *info);
void	move_l_arrow(t_data *info);
float	deg_to_rad(float d);
float	angle_correction(float ang);
void	mini_map(t_data *info);

//		Utils
int		ft_count_lines(int fd);
int		open_file(char *file);
void	close_file(int fd, char **scene, bool arr);
int		valid_file(char *file);
int		ft_err(char *str);

#endif
