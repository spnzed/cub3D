/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:43:32 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/31 17:33:47 by aaespino         ###   ########.fr       */
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
	//				BORRAR
	// int i = 0;
	// while (info->map.grid[i])
	// {
	// 	printf("X[%d] Y[%d]\t%s\n", ft_strlen(info->map.grid[i]), i, info->map.grid[i]);
	// 	i++;
	// }
	// printf ("ANCHO\t[%d]\n", info->map.size[X]);
	// printf ("ALTO\t[%d]\n", info->map.size[Y]);
}

int	handle_map(char *file, t_data *info)
{
	get_file(file, info);
	check_map(info);
	parse_map(info, info->scene);
	return (0);
}
