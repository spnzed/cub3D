/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:14:54 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/21 20:10:32 by erosas-c         ###   ########.fr       */
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
# include <limits.h>  //draw_line, no estic segura que calgui finalment
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

# define SCALE 64
# define HEIGHT 1080
# define WIDTH 1920
//# define HEIGHT 810
//# define WIDTH 1380
# define SPEED 3

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
	char		**grid;
	int			grid_pos; //ES LA LINIA ON COMENÇA EL MAPA DINTRE DE L'ESCENA
	int			map_size;
	int			scale; //tpoc no te sentit si l'unic que fa es igualar-la al define SCALE, per aix[o posem SCALE directament on calgui i llestos]
	int			size[2];
	int			spawn[2];
	int			*arr;  // l'hem dínicialitzar!!
//	int			player_dir; //en principi no cal tenir-ho 2 vegades - JA ES A PARAMETERS
//	int			floor;  //en principi no cal tenir-ho 2 vegades - JA ES A PARAMETERS
//	int			ceiling; //en principi no cal tenir-ho 2 vegades - JA ES A PARAMETERS
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
	int		dir; //era p_dir pero crec que no te sentit, no cal la p i nomes alalrga els caracters que calen
	float	dx; //p_dir_x_cos;  //seria dx suposo (el desplacament d'x)
	float	dy; //p_dir_y_sin; //idem per a y
	int		w;//temp per fer quadradet del jugador en 2D
	int		h;//temp per fer quadradet del jugador en 2D
	//float	dx; // x controlar dif. desplaçament segons angle, encada una de les 2 dimensions
	//float	dy; // x controlar dif. desplaçament segons angle, encada una de les 2 dimensions
	//int		len; //temp per projectar rajos i veure com rota la barra en 2D
}	t_player;

typedef struct s_ray
{
	char	wall_or; // N, S, E, W
	double	len;
	/*float	p[2];  //ray position p[X] , p[Y] (when it gets crossing "map virtual" horizontal/vertical lines of the grid)
	float	off[2]; //ray offset off[X], off[Y], example: Y offset when crossing horizontal lines will be 48 if there are 48 pixels per map row
	int		num; // order/position in the array of t_rays structures. One membre/number per ray, starting from 0, as being an array.
	int		dir;*/
	/*double	perpwalldist;
	int		draw[2];
	int		step[2];
	int		side[2];
	int		lineh;
	bool	hit;*/
}	t_ray;

/*typedef struct s_rays
{
	double	camera;
	double	plane[2];
	double	pos[2];
	double	dir[2];
	double	raydir[2];
	double	deltadist[2];
	double	sidedist[2];
	double	perpwalldist;
	int		draw[2];
	int		step[2];
	int		side[2];
	int		lineh;
	bool	hit;
}	t_rays;*/

typedef struct s_data
{
	char			**scene;
	t_mlx			*mlx;
	t_ray			*ray;
	t_parameters	parameters;
	t_map			map;
//	t_map			minimap;
	t_player		player;
	t_player		minipl;
	int				dir;
	int				dir_cor[2];
	int				p_plane_x;
	int				p_plane_y;
}	t_data;

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
int		render(t_data *info);
void	get_bigmap2d(t_data *info);
void	draw_line(int *scr, t_point *pts, int color);
void	init_temp(t_data *info);
void	new_scene(t_data *info);
void	init_players(t_data *info);
void	fill_ray(int *scr, t_player *pl, t_data *info);
void	create_image(t_data *info);
void	init_texture(t_data *info);
void	ray_casting(t_data *info);
//void	draw_rays(t_data *info);
void	other_angles(int *scr, t_point *pts, int ang);
void	ray_end(int *scr, t_point *pts, int ang);

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

#endif
