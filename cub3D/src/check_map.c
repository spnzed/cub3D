/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:59:47 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/19 17:22:18 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_grid(char *line)
{
	int			i;
	static int	spawn = 0;

	i = -1;
	while (line[++i])
	{
		if (ft_strchr("NSWE", line[i]))
		{
			if (spawn == 1)
				return (printf(RED"Error: Map: Multiple Spawn Points\n"RESET), 1);
			spawn++;
		}
		if (!ft_strchr("10NSWE ", line[i]))
			return (printf(RED"Error: Map: Invalid Characters\n"RESET), 1);
	}
	return (0);
}

// static int	tile_is_exterior(char **grid, int y, int x, int size[2])
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (i <= 1)
// 	{
// 		j = -1;
// 		while (j <= 1)
// 		{
// 			if (y + i != 0 && x + j != 0)
// 			{
// 				if (y + i >= size[Y] || y + i < 0 || \
// 					x + j >= size[X] || x + j < 0 || \
// 					grid[y + i][x + j] == ' ')
// 					return (1);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// static int	check_map_is_surrounded(char **grid, int size[2])
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < size[Y])
// 	{
// 		j = 0;
// 		while (j < size[X])
// 		{
// 			if (tile_is_exterior(grid, i, j, size))
// 			{
// 				if (grid[i][j] == '0')
// 					return (c3d_error(ERR_MAP_NOT_ENCLOSED));
// 				if (ft_strchr("NSWE", grid[i][j]))
// 					return (c3d_error(ERR_MAP_SPAWN_INVALID));
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (SUCCESS);
// }

int	check_map_border(char **scene)
{
	(void)scene;
	return(0);
}

int	check_map_char(char **scene)
{
	int i = -1;
	int count = 0;

	while (scene[++i])
	{
		if (ft_strlen(scene[i]) > 1)
		{
			if (count > 5)
			{
				if (check_grid(scene[i]))
					return (1);
			}
			count++;
		}
	}
	return (0);
}
