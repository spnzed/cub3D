/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:15:19 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/25 20:55:37 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_width(char **file)
{
	int	i;
	int	width;

	i = -1;
	width = 0;
	while (file[++i])
	{
		if (ft_strlen(file[i]) > width)
			width = ft_strlen(file[i]);
	}
	return (width);
}

static void	put_spaces(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ' ';
		i++;
	}
}

static void	put_lines(char *str, char *file_line)
{
	int	i;

	i = 0;
	while (file_line[i])
	{
		str[i] = file_line[i];
		i++;
	}
}

static void	get_grid(char **grid, char **file, int size[2])
{
	int	i;

	i = 0;
	while (i < size[1])
	{
		put_spaces(grid[i]);
		put_lines(grid[i], file[i]);
		i++;
	}
}

char **map_to_file(t_data *info, t_map *map, char **file)
{
	char	**grid;

	map->size[0] = get_width(file + info->map.grid_pos);
	map->size[1] = ft_arrlen(file + info->map.grid_pos);
	grid = (char **)ft_alloc_array(sizeof(char), map->size[1] + 1, map->size[0]);
	grid[map->size[1] + 1] = NULL;  //pot ser que aqui el + 1 sobri?
	if (!grid)
	{
		ft_err("Error: Malloc: Allocation Failed\n");
		exit(1);
	}
	get_grid(grid, file, map->size);
	//printf("grid[0]: %s\n", grid[0]); // no esta alimentat encara aqui? no imprimeix res
	return (grid);
}
