/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:43:32 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/22 18:12:49 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_map (t_data *info)
{
	if (check_textures(info->scene, info))
		exit(1);
	if (check_map_char(info->scene))
		exit(1);
}

void	parse_map (t_data *info, char **grid)
{
	info->map.grid = map_to_file(&info->map, grid);
	if (check_map_border(info->map.grid))
		exit(1);
}

int	handle_map(char *file, t_data *info)
{
	get_file(file, info);
	check_map(info);
	//init_map(info->map);
	parse_map(info, info->scene);
	return (0);
}
