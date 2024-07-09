/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:59:47 by aaespino          #+#    #+#             */
/*   Updated: 2024/07/09 19:30:35 by aaronespino      ###   ########.fr       */
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
				ft_err("Error: Map: Multiple Spawn Points\n");
			player_direction(line[x], info);
			info->map.spawn[0] = x;
			info->map.spawn[1] = y;
			spawn++;
		}
		if (!ft_strchr("10NSWE \t", line[x]))
			ft_err("Error: Map: Invalid Characters\n");
	}
	return (0);
}

static int weatborder(t_data *info, char **grid, int y, int x)
{
    int i;
    int j;

    i = -1;
    while (i <= 1)
    {
        j = -1;
        while (j <= 1)
        {
            // Se omite (0, 0) como posición válida
            if (y + i != y || x + j != x)
            {
                // Verifica si la posición (y + i, x + j) está fuera de los límites del mapa
                if (y + i >= info->map.size[Y] || y + i < 0
                    || x + j >= info->map.size[X] || x + j < 0)
                {
                    return 1;
                }

                // Verifica si la celda (y + i, x + j) no es una esquina y es vacía
                if ((i == 0 || j == 0) && grid[y + i][x + j] == ' ')
                {
                    return 1;
                }
            }
            j++;
        }
        i++;
    }
    return 0;
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
				{
					printf("[%s]\n", grid[i - 1]);
					printf("[%s]\t[%d]\n", grid[i], j);
					printf("[%s]\n", grid[i + 1]);
					ft_err("Error: Map: Not Surrounded by Walls\n");
				}
				if (ft_strchr("NSWE", grid[i][j]))
					ft_err("Error: Map: Invalid Player Spawn\n");
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void	compr_end_grid(char **scene, int i)
{
	while (scene[i])
	{
		if (ft_strlen(scene[i]) > 0 && !ft_strisspace(scene[i]))
			ft_err("Error: Parameters: Doesn't Follow Guidelines\n");
		i++;
	}
}

int	check_map_char(char **scene, t_data *info)
{
	int	i;
	int	count;
	int	j;

	i = -1;
	j = 0;
	count = -1;
	while (scene[++i])
	{
		if (ft_strlen(scene[i]) > 0 && !ft_strisspace(scene[i]))
		{
			if (++count > 5)
			{
				if (info->map.grid_pos == -1)
					check_grid(scene[i], i, info);
				else
					check_grid(scene[i], ++j, info);
			}
		}
		else if (info->map.grid_pos != -1 && ft_strlen(scene[i]) == 0
			&& count != 0 && scene[i + 1] != NULL)
			break ;
	}
	compr_end_grid(scene, i);
	return (0);
}
