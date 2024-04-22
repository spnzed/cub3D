#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
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

#endif