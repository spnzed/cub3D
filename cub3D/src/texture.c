/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:56:46 by aaronespino       #+#    #+#             */
/*   Updated: 2024/04/30 17:13:20 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	*get_texture(t_data *info)
{
	if (info->ray.side[X] == 0)
	{
		if (info->ray.side[Y] == 1)
			return (info->parameters.south);
		else
			return (info->parameters.north);
	}
	if (info->ray.side[X] == 1)
		return (info->parameters.west);
	return (info->parameters.east);
}

void    init_texture(t_data *info)
{
	t_img	*texture;

    texture = get_texture(info);
    draw_vert_stripe(get_texture_add(data, texture), \
		data->mlx.win_img->addr + x, texture->size, data);
}
