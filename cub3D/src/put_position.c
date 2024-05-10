/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:02:21 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/10 13:39:03 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_position(t_data *info)
{
	info->player.x = (info->map.spawn[0] * SCALE) + SCALE / 2;
	info->player.y = (info->map.spawn[1] * SCALE) + SCALE / 2;
	info->player.p_dir = info->map.player_dir;
	printf("info->player.p_dir: %i\n", info->player.p_dir);
	printf("deg_to_rad(info->map.player_dir): %f\n", deg_to_rad(info->map.player_dir));
	printf("sin(deg_to_rad(info->map.player_dir)): %f\n", sin(deg_to_rad(info->map.player_dir)));
	info->player.p_dir_x_cos = cos(deg_to_rad(info->map.player_dir));
	info->player.p_dir_y_sin = -sin(deg_to_rad(info->map.player_dir));
	info->map.map_size = info->map.size[0] * info->map.size[1];
	info->map.scale = SCALE;
	info->map.floor = info->parameters.floor;
	info->map.ceiling = info->parameters.ceiling;
}
