/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:46:35 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/13 10:27:15 by aaronespino      ###   ########.fr       */
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

static void	handle_key(t_data *info)
{
	if (!info->mlx->mlx)
		ft_err("Error: MLX\n");
	if (info->mlx->keys->w)
		move_front(&(info->player), &(info->minipl), &(info->map));
	if (info->mlx->keys->a)
		move_left(&(info->player), &(info->minipl), &(info->map));
	if (info->mlx->keys->s)
		move_back(&(info->player), &(info->minipl), &(info->map));
	if (info->mlx->keys->d)
		move_right(&(info->player), &(info->minipl), &(info->map));
	if (info->mlx->keys->l_arr)
		move_l_arrow(info);
	if (info->mlx->keys->r_arr)
		move_r_arrow(info);
}

static void	new_scene(t_data *info)
{
	cast_rays(info);
	draw_walls(info);
}

int	render(t_data *info)
{
	handle_key(info);
	paint_ceil_floor(info->mlx->img.img_adr, info->parameters.floor,
		info->parameters.ceiling);
	new_scene(info);
	mlx_put_image_to_window(info->mlx->mlx,
		info->mlx->win, info->mlx->img.img, 0, 0);
	free(info->ray);
	return (0);
}
