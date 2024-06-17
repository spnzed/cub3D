/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:15:19 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/13 12:58:29 by aaronespino      ###   ########.fr       */
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

static void	get_grid(char **grid, char **file, int size[2], int grid_p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size[Y])
	{
		while (j < size[X])
		{
			grid[i][j] = ' ';
			j++;
		}
		put_lines(grid[i], file[grid_p]);
		i++;
		grid_p++;
	}
}

char	**map_to_file(t_data *info, t_map *map, char **file)
{
	char	**grid;

	map->size[X] = get_width(file + info->map.grid_pos);
	map->size[Y] = ft_arrlen(file + info->map.grid_pos);
	grid = (char **)ft_alloc_array(sizeof(char), map->size[Y] + 1,
		map->size[X]);
	if (!grid)
		ft_err("Error: Malloc\n");
	grid[map->size[Y]] = NULL;
	get_grid(grid, file, map->size, map->grid_pos);
	info->map.cell_w = SCALE;
	return (grid);
}
