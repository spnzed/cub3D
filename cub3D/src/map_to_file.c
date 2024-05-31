/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:15:19 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/31 20:39:51 by erosas-c         ###   ########.fr       */
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

static void	get_grid(char **grid, char **file, int size[2], int grid_p)
{
	int	i;

	i = 0;
	while (i < size[Y])
	{
		put_spaces(grid[i]);
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
	grid[map->size[Y]] = NULL;
	if (!grid)
	{
		ft_err("Error: Malloc: Allocation Failed\n"); // pensar quin missatge posem en cada cas, crec que caldria unificar
		exit(1);
	}
	get_grid(grid, file, map->size, map->grid_pos);
	info->map.cell_w = 48;
	return (grid);
}
