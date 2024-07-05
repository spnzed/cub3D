/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:43:32 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/21 22:38:18 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	*grid2intarr(t_map map)
{
	int	i;
	int	j;
	int	*arr;

	i = -1;
	j = -1;
	arr = (int *)ft_calloc(sizeof(int), map.size[X] * map.size[Y]);
	if (!arr)
		ft_err("Error: Malloc\n");
	while (++i < map.size[Y])
	{
		while (++j < map.size[X])
		{
			if ((map.grid)[i][j] == '1' || (map.grid)[i][j] == ' ')
				arr[i * map.size[X] + j] = 1;
			else
				arr[i * map.size[X] + j] = 0;
		}
		j = -1;
	}
	return (arr);
}

static void	check_map(t_data *info)
{
	if (check_textures(info->scene, info))
		exit(1);
	if (check_map_char(info->scene, info))
		exit(1);
	if (info->map.spawn[X] == 0 && info->map.spawn[Y] == 0)
		ft_err("Error: Map: Player Not Found\n");
}

void	parse_map(t_data *info, char **grid)
{
	info->map.grid = map_to_file(info, &info->map, grid);
	info->map.arr = grid2intarr(info->map);
	if (check_map_border(info, info->map.grid))
		exit(1);
}

int	handle_map(char *file, t_data *info)
{
	get_file(file, info);
	check_map(info);
	parse_map(info, info->scene);
	return (0);
}
