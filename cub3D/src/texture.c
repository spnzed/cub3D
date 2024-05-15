/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:56:46 by aaronespino       #+#    #+#             */
/*   Updated: 2024/05/15 14:22:27 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	*get_texture(t_data *info)
{
	if (info->ray.side[X] == 0)
	{
		if (info->ray.side[Y] == 1)
			return (&info->mlx->south);
		else
			return (&info->mlx->north);
	}
	if (info->ray.side[X] == 1)
		return (&info->mlx->west);
	return (&info->mlx->east);
}

void	init_texture(t_data *info)
{
	t_img	*texture;

	texture = get_texture(info);
	// draw_vert_stripe(get_texture_add(info, texture), \
	// 	data->mlx.win_img->addr + x, texture->size, data);
}
