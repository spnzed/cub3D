/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:46:35 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/11 13:24:42 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	paint_ceil_floor(int *p, int floor, int ceiling)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < HEIGHT / 2)
	{
		while (x < WIDTH)
		{
			p[(y * WIDTH) + x] = ceiling;
			x++;
		}
		x = 0;
		y++;
	}
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			p[(y * WIDTH) + x] = floor;
			x++;
		}
		x = 0;
		y++;
	}
}

void	handle_key(t_data *info)
{
	if (!info->mlx->mlx)
	{
		printf(RED"Error: MLX\n"RESET);
		exit(1);
	}
	if (info->mlx->keys->w)
		move_front(info);
	else if (info->mlx->keys->a)
		move_left(info);
	else if (info->mlx->keys->s)
		move_back(info);
	else if (info->mlx->keys->d)
		move_right(info);
	else if (info->mlx->keys->left)
		move_l_arrow(info);
	else if (info->mlx->keys->right)
		move_r_arrow(info);
}

void	new_scene(t_data *info)
{
	paint_ceil_floor(info->mlx->img.img_adr, info->parameters.floor,
		info->parameters.ceiling);
	get_bigmap2d(info);
	mini_map(info);
	mlx_put_image_to_window(info->mlx->mlx,
		info->mlx->win, info->mlx->img.img, 0, 0);
	handle_key(info);
}

int	render(t_data *info)
{
	// ray_casting(info);
	new_scene(info);
	return (0);
}
