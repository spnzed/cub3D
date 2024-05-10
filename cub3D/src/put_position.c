/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:02:21 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/10 18:56:35 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_position(t_data *info)
{
	int	t = 64;
//	t = t / 2; //MacBook erosas

	info->player.x = (info->map.spawn[0] * SCALE) + SCALE / 2;
	info->player.y = (info->map.spawn[1] * SCALE) + SCALE / 2;
	//info->player.p_dir = info->map.player_dir; //no ens hauria de caldre, ens quedem nomes amb la del player
	printf("info->player.dir: %i\n", info->player.dir);
	printf("deg_to_rad(info->player.dir): %f\n", deg_to_rad(info->player.dir));
	printf("sin(deg_to_rad(info->player.dir)): %f\n", -sin(deg_to_rad(info->player.dir)));
	info->player.p_dir_x_cos = cos(deg_to_rad(info->player.dir));
	info->player.p_dir_y_sin = -sin(deg_to_rad(info->player.dir));
	info->map.map_size = info->map.size[0] * info->map.size[1];
	info->player.len = t / 2;
	info->player.w = t / 8;
	info->player.h = t / 8;
//	info->player.x = WIDTH / 2 + (t * 3 / 2) - (info->player.w / 2); //6 NOMBRE COLUMNES MAP, 64 (t) = mida passadissos d'una unitat (utilitzada a fill_map)
//	info->player.y = HEIGHT / 2 + t - (info->player.h / 2);
	//info->map.scale = SCALE;
	//info->map.floor = info->parameters.floor;
	//info->map.ceiling = info->parameters.ceiling;
}
