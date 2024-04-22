/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:14:54 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/22 17:39:59 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdbool.h>
# include "../lib/libft_gnl/inc/libft.h"
# include "../lib/mlx/mlx.h"

# define RESET		"\033[0m"
# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"

# define HEIGHT		1080
# define WIDTH		1920

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*image;
}	t_vars;

typedef struct s_map
{
	char		**grid;
	int			size[2];
	int			spawn[2];
	int			player_dir[2];
}				t_map;

/*			window.c			*/

typedef struct s_parameters
{
	char*	north;
	char*	south;
	char*	west;
	char*	east;
	char*	sprite;
	char*	door;
	int		floor;
	int		ceiling;
}				t_parameters;

typedef struct 		s_data
{
	char			**scene;
	t_map			map;
	t_parameters	parameters;
}					t_data;

//		Program
int		init_window(void);
int		check_args(int argc, char **argv);
void	get_file(char *file, t_data *info);
int		handle_map(char *file, t_data *info);
int		check_map_char(char **scene);
int		check_map_border(char **scene);
int		check_textures(char **scene, t_data *info);
char	*get_color(char *str, char rgb);
char	**map_to_file(t_map *map, char **file);
int		rgb_check(char *channel);
//		Utils
int		ft_count_lines(int fd);
int		open_file(char *file);
void	close_file(int fd, char** scene, bool arr);

#endif