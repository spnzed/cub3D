/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:02:21 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/21 19:51:18 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_position(t_data *info)
{
	int		cell_w;
	int		col_w;

	col_w = SCALE / 8 * 6; //amplada cel.la/columna mapa gros
	cell_w = SCALE / 4; //amplada cel.la/columna minimap
//	info->player.len = SCALE / 2;
	info->player.w = SCALE / 8;
	info->player.h = SCALE / 8;
	info->player.x = WIDTH / 2 - (info->map.size[0] * col_w) / 2
		+ info->map.spawn[0] * col_w + col_w / 2;
	info->player.y = HEIGHT / 2 - (info->map.size[1] * col_w) / 2
		+ info->map.spawn[1] * col_w + col_w / 2;
	info->minipl.dx = cos(deg_to_rad(info->player.dir));
	info->minipl.dy = -sin(deg_to_rad(info->player.dir));
	info->map.map_size = info->map.size[0] * info->map.size[1];
	info->minipl.x = 16 + info->map.spawn[X] * cell_w + cell_w / 2; //primer 8 es offset (marge/separacio amb el limit de la pantalla)
	info->minipl.y = 16 + info->map.spawn[Y] * cell_w + cell_w / 2; //els altres 2 8 son l'amplada de cel.la del minimap
	info->player.dx = info->minipl.dx * 3;
	info->player.dy = info->minipl.dy * 3;
/*	info->player.x = (info->map.spawn[0] * SCALE) + SCALE / 2;
	info->player.y = (info->map.spawn[1] * SCALE) + SCALE / 2;
	info->player.dir= info->map.player_dir;
	info->player.dir_cor[X] = cos(deg_to_rad(info->map.player_dir));
	info->player.dir_cor[Y] = -sin(deg_to_rad(info->map.player_dir));
	info->map.map_size = info->map.size[X] * info->map.size[Y];
	info->map.scale = SCALE;
	info->map.floor = info->parameters.floor;
	info->map.ceiling = info->parameters.ceiling;*/
}
