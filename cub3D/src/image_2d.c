/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:03:48 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/24 15:10:10 by erosas-c         ###   ########.fr       */
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
	fill_black(info->mlx->img.img);
	mlx_put_image_to_window(info->mlx->mlx, info->mlx->win, info->mlx->img.img, 0, 0);
}
