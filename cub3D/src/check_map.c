/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:59:47 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/18 21:00:02 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_grid(char *line, int y, t_data *info)
{
	int			x;
	static int	spawn = 0;

	x = -1;
	while (line[++x])
	{
		if (ft_strchr("10NSWE", line[x]))
		{
			if (info->map.grid_pos == -1)
				info->map.grid_pos = y;
		}
		if (ft_strchr("NSWE", line[x]))
		{
			if (spawn > 0)
				return (ft_err("Error: Map: Multiple Spawn Points\n"), 1);
			player_direction(line[x], info);
			info->map.spawn[0] = x;
			info->map.spawn[1] = y;
			spawn++;
		}
		if (!ft_strchr("10NSWE \t", line[x]))
			return (ft_err("Error: Map: Invalid Characters\n"), 1);
	}
	return (0);
}

static int	weatborder(t_data *info, char **grid, int y, int x)
{
	int	i;
	int	j;

	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			if (y + i != 0 && x + j != 0)
			{
				if (y + i >= info->map.size[Y] || y + i < 0
					|| x + j >= info->map.size[X] || x + j < 0
					|| grid[y + i][x + j] == ' ')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_border(t_data *info, char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->map.size[Y])
	{
		j = 0;
		while (j < info->map.size[X])
		{
			if (weatborder(info, grid, i, j))
			{
				if (grid[i][j] == '0')
					return (ft_err("Error: Map: Not Surrounded by Walls\n"), 1);
				if (ft_strchr("NSWE", grid[i][j]))
					return (ft_err("Error: Map: Invalid Player Spawn\n"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_char(char **scene, t_data *info)
{
	int	i;
	int	count;
	int	j;

	i = -1;
	j = 0;
	count = 0;
	while (scene[++i])
	{
		if (ft_strlen(scene[i]) > 1 && !ft_strisspace(scene[i]))
		{
			if (count > 5)
			{
				if (info->map.grid_pos == -1)
				{
					if (check_grid(scene[i], i, info))
						return (1);
				}
				else if (check_grid(scene[i], ++j, info))
					return (1);
			}
			count++;
		}
	}
	return (0);
}
