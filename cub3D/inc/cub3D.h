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

/*			window.c			*/
int	window(void);

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
	t_parameters	parameters;
}					t_data;

//		Program
int		check_args(int argc, char **argv, t_data *info);
void	get_file(char *file, t_data *info);
int		check_map_char(char **scene);
int		check_map_border(char **scene);
int		check_textures(char **scene, t_data *info);
char	*get_color(char *str, char rgb);
int		rgb_check(char *channel);
//		Utils
int		ft_count_lines(int fd);
int		open_file(char *file);
void	close_file(int fd, char** scene, bool arr);

#endif