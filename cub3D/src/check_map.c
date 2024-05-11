/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:59:47 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/11 19:11:44 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	player_direction(char c, t_data *info)
{
	if (c == 'N')
		info->player.dir = 90;
	if (c == 'S')
		info->player.dir = 270;
	if (c == 'W')
		info->player.dir = 180;
	if (c == 'E')
		info->player.dir = 0;
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
		if (!ft_strchr("10NSWE ", line[x]))
			return (ft_err("Error: Map: Invalid Characters\n"), 1);
	}
	return (0);
}

static int	weatborder(char **grid, int x, int y, int size_x, int size_y)
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
			if (weatborder(scene, i, j, ft_arrlen(scene), ft_strlen(scene[i])))
			{
				if (scene[i][j] == '0')
					return (ft_err("Error: Map: Not Surrounded by Walls\n"), 1);
				if (ft_strchr("NSWE", scene[i][j]))
					return (ft_err("Error: Map: Invalid Player Spawn\n"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_border(char **scene)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
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
	int	i;
	int	count;
	int	j;

	i = -1;
	j = 0;
	count = 0;
	while (scene[++i])
	{
		if (ft_strlen(scene[i]) > 1)
		{
			if (count > 5)
			{
				if (info->map.grid_pos == -1)
				{
					if (check_grid(scene[i], i, info))
						return (1);
				}
				else
				{
					if (check_grid(scene[i], ++j, info))
						return (1);
				}
			}
			count++;
		}
	}
	return (0);
}
