/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:33:01 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/19 12:47:23 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**get_scene_lines(int fd, int lines)
{
	int		i;
	char	**scene;

	i = 0;
	scene = malloc(sizeof(char *) * (lines + 1));
	if (!scene)
	{
		printf(RED"Error: Malloc\n"RESET);
		exit (1);
	}
	scene[lines] = NULL;
	while (i < lines)
	{
		scene[i] = get_next_line(fd);
		i++;
	}
	return (scene);
}

static void	clean_scene(char **scene)
{
	int	i;
	int	j;

	i = 0;
	while (scene[i])
	{
		j = ft_strlen(scene[i]);
		if (scene[i][j - 1] == '\n')
			scene[i][j - 1] = '\0';
		i++;
	}
	return ;
}

void	get_file(char *file, t_data *info)
{
	int		fd;
	int		lines;
	char	**scene;

	fd = open_file(file);
	lines = ft_count_lines(fd);
	close_file(fd, NULL, false);
	fd = open_file(file);
	scene = get_scene_lines(fd, lines);
	close_file(fd, scene, true);
	clean_scene(scene);
	info->scene = scene;
}