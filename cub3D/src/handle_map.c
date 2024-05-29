/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:43:32 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/29 19:29:32 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_map(t_data *info)
{
	if (check_textures(info->scene, info))
		exit(1);
	if (check_map_char(info->scene, info))
		exit(1);
	if (info->map.spawn[0] == -1 && info->map.spawn[1] == -1)
	{
		ft_err("Error: Map: No Player Found\n");
		exit(1);
	}
}

void	parse_map(t_data *info, char **grid)
{
	info->map.grid = map_to_file(info, &info->map, grid);
	if (check_map_border(grid))
		exit(1);
}

int	handle_map(char *file, t_data *info)
{
	get_file(file, info);
	check_map(info);
	parse_map(info, info->scene);
	return (0);
}
