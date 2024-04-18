#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../lib/libft_gnl/inc/libft.h"

#define RESET	"\033[0m"
#define BLACK	"\033[0;30m"
#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"
#define YELLOW	"\033[0;33m"
#define BLUE	"\033[0;34m"
#define MAGENTA	"\033[0;35m"
#define CYAN	"\033[0;36m"
#define WHITE	"\033[0;37m"

typedef struct 		s_data
{
	char	**scene;
}					t_data;

//		Program
int		check_args(int argc, char **argv, t_data *info);
//		Utils
int		ft_count_lines(int fd);

#endif