/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:03:48 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/25 18:31:32 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_black(int *p)
{
	int	y;
	int	x;
	int	color;

	x = 0;
	y = 0;
	color = 0x000000;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			p[(y * WIDTH) + x] = color;
			x++;
		}
		x = 0;
		y++;
	}
}

void	mini_map(t_data *info)
{
	printf("info.map->size[0] llargada (X coordinate): %i, info.map->size[1] altura mapa (Y coordinate): %i\n", info->map.size[0], info->map.size[1]);
	printf("info.map->size[0] area mapa: %i\n", info->map.map_size);
	//fill_black(info->mlx->img.img);
	mlx_put_image_to_window(info->mlx->mlx, info->mlx->win, info->mlx->img.img, 0, 0);
}
