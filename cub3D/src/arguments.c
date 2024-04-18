/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:46:42 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/18 20:27:30 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int comprove_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i > 2 && file[i - 4] == '.' && file[i - 3] == 'c'
		&& file[i - 2] == 'u' && file[i - 1] == 'b')
		return (0);
	else
		return (1);
}

static char	**get_file(int fd, int lines)
{
	int		i;
	char	**scene;

	i = 0;
	scene = malloc(sizeof(char *) * (lines + 1));
	scene[lines] = NULL;
	while (i < lines)
	{
		scene[i] = get_next_line(fd);
		printf("LINE: %s\n", scene[i]);
		i++;
	}
	return (scene);
}

static int	check_file(char *file, t_data *info)
{
	int		fd;
	int		lines;
	char	**scene;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (printf(RED"Error: Cannot Open File\n"RESET), 1);
	printf("SEGF\n");
	lines = ft_count_lines(fd);
	if (close(fd) == -1)
		return (printf(RED"Error: Cannot Close File\n"RESET), 1);
	scene = get_file(fd, lines);
	if (!scene)
		return (printf(RED"Error: Malloc\n"RESET), 1);
	if (close(fd) == -1)
	{
		ft_arrfree(scene);
		return (printf(RED"Error: Cannot Close File\n"RESET), 1);
	}
	// clean_scene(scene);
	info->scene = scene;
	return (0);
}

int	check_args(int argc, char **argv, t_data *info)
{
	if (argc < 2)
		return (printf(RED"Error: Not Enough Arguments\n"RESET), 1);
	if (argc > 2)
		return (printf(RED"Error: Too Much Arguments\n"RESET), 1);
	if (ft_strlen(argv[1]) <= 4)
		return (printf(RED"Error: Invalid Path\n"RESET), 1);
	if (comprove_extension(argv[1]))
		return (printf(RED"Error: Incorret File Extension\n"RESET), 1);
	if (check_file(argv[1], info))
		return (1);
	return 0;
}