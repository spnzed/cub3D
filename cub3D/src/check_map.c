/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:59:47 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/19 18:48:11 by aaespino         ###   ########.fr       */
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
				if (x + i >= size_x || x + i < 0 ||
					y + j >= size_y || y + j < 0 ||
					grid[x + i][y + j] == ' ')
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
			// printf ("%c", scene[i][j]);
			if (we_at_border(scene, i, j, ft_arrlen(scene), ft_strlen(scene[i])))
			{
				if (scene[i][j] == '0')
					return (printf(RED"Error: Map: Not Surrounded by Walls\n"RESET), 1);
				if (ft_strchr("NSWE", scene[i][j]))
					return (printf(RED"Error: Map: Invalid Player Spawn\n"RESET), 1);
			}
			j++;
		}
		// printf("\n");
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
