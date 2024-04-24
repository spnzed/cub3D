/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:02:21 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/24 18:36:37 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	deg_to_rad(float d)
{
	return (d * M_PI / 180.0);
}

void	put_position(t_data *info)
{
	info->player.x = (info->map.spawn[0] * SCALE) + SCALE / 2;
	info->player.y = (info->map.spawn[1] * SCALE) + SCALE / 2;
	info->player.p_dir = info->map.player_dir;
	info->player.p_dir_cos = cos(deg_to_rad(info->map.player_dir));
	info->player.p_dir_sin = -sin(deg_to_rad(info->map.player_dir));
	info->map.map_size = info->map.size[0] * info->map.size[1];
	info->map.scale = SCALE;
	info->map.floor = info->parameters.floor;
	info->map.ceiling = info->parameters.ceiling;
}
