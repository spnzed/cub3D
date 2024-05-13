/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:02:21 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/13 20:25:57 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_position(t_data *info)
{
	int		cell_w;
	int		col_w;

	col_w = SCALE / 8 * 6; //amplada cel.la/columna mapa gros
	cell_w = 8; //amplada cel.la/columna minimap
	info->player.len = SCALE / 2;
	info->player.w = SCALE / 8;
	info->player.h = SCALE / 8;
	info->player.x = WIDTH / 2 - (info->map.size[0] * col_w) / 2
		+ info->map.spawn[0] * col_w + col_w / 2 - info->player.w / 2;
	info->player.y = HEIGHT / 2 - (info->map.size[1] * col_w) / 2
		+ info->map.spawn[1] * col_w + col_w / 2 - info->player.h / 2;
	info->minipl.dx = cos(deg_to_rad(info->player.dir));
	info->minipl.dy = -sin(deg_to_rad(info->player.dir));
	info->map.map_size = info->map.size[0] * info->map.size[1];
	info->minipl.h = 4;
	info->minipl.w = 4;
//	printf("INI PL POS x: %f, y: %f\n", info->player.x, info->player.y);
	info->minipl.x = cell_w + info->map.spawn[0] * cell_w
		+ cell_w / 2 - info->minipl.w / 2;
	info->minipl.y = cell_w + info->map.spawn[1] * cell_w
		+ cell_w / 2 - info->minipl.h / 2;
//	printf("INI MINIPL POS x: %f, y: %f\n", info->minipl.x, info->minipl.y);
	info->player.dx = info->minipl.dx * 6;
	info->player.dy = info->minipl.dy * 6;
}
