/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:59:47 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/26 14:30:03 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	player_direction(char c, t_data *info)
{
	if (c == 'N')
		info->map.player_dir = 90;
	if (c == 'S')
		info->map.player_dir = 270;
	if (c == 'W')
		info->map.player_dir = 180;
	if (c == 'E')
		info->map.player_dir = 0;
}

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
				info->map.grid_pos = y + 1;
		}
		if (ft_strchr("NSWE", line[x]))
		{
			if (spawn > 0)
				return (printf(RED"Error: Map: Multiple Spawn Points\n"RESET), 1);
			player_direction(line[x], info);
			info->map.spawn[0] = x;
			info->map.spawn[1] = y;
			spawn++;
		}
		if (!ft_strchr("10NSWE ", line[x]))
			return (printf(RED"Error: Map: Invalid Characters\n"RESET), 1);
	}
	return (0);
}

static int	we_at_border(char **grid, int x, int y, int size_x, int size_y)
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
				if (x + i >= size_x || x + i < 0
					|| y + j >= size_y || y + j < 0
					|| grid[x + i][y + j] == ' ')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_border(char **scene, int i)
{
	int	j;

	while (scene[i])
	{
		j = 0;
		while (scene[i][j])
		{
			//					SIZE 0 
			if (we_at_border(scene, i, j, ft_arrlen(scene), ft_strlen(scene[i])))
			{
				if (scene[i][j] == '0')
					return (printf(RED"Error: Map: Not Surrounded by Walls\n"RESET), 1);
				if (ft_strchr("NSWE", scene[i][j]))
					return (printf(RED"Error: Map: Invalid Player Spawn\n"RESET), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_border(char **scene)
{
	int i = -1;
	int count = 0;

	while (scene[++i])
	{
		if (ft_strlen(scene[i]) > 1)
		{
			if (count > 5)
			{
				if (check_border(scene, i))
					return (1);
			}
			count++;
		}
	}
	return (0);
}

int	check_map_char(char **scene, t_data *info)
{
	int i = -1;
	int count = 0;

	while (scene[++i])
	{
		if (ft_strlen(scene[i]) > 1)
		{
			if (count > 5)
			{
				if (check_grid(scene[i], i, info))
					return (1);
			}
			count++;
		}
	}
	return (0);
}
