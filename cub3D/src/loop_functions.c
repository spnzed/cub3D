/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:43:39 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/27 00:04:45 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_esc(t_data *info)
{
	if (info->mlx->img.img)
		mlx_destroy_image(info->mlx->mlx, info->mlx->img.img);
	if (info->mlx->win)
		mlx_destroy_window(info->mlx->mlx, info->mlx->win);
	exit(1);
}

int	ft_press(int keycode, t_data *info)
{
	if (!info->mlx->keys)
		ft_err("Error: key struct is not initialized\n");
	if (keycode == KEY_W)
		info->mlx->keys->w = 1;
	if (keycode == KEY_A)
		info->mlx->keys->a = 1;
	if (keycode == KEY_S)
		info->mlx->keys->s = 1;
	if (keycode == KEY_D)
		info->mlx->keys->d = 1;
	if (keycode == KEY_LEFT)
		info->mlx->keys->l_arr = 1;
	if (keycode == KEY_RIGHT)
		info->mlx->keys->r_arr = 1;
	if (keycode == KEY_ESC)
		ft_esc(info);
	return (0);
}

int	ft_release(int keycode, t_mlx *mlx)
{
	if (!mlx->keys)
	{
		ft_err("Error: key struct is not initialized\n");
		exit(1);
	}
	if (keycode == KEY_W)
		mlx->keys->w = 0;
	if (keycode == KEY_A)
		mlx->keys->a = 0;
	if (keycode == KEY_S)
		mlx->keys->s = 0;
	if (keycode == KEY_D)
		mlx->keys->d = 0;
	if (keycode == KEY_LEFT)
		mlx->keys->l_arr = 0;
	if (keycode == KEY_RIGHT)
		mlx->keys->r_arr = 0;
	return (0);
}

int	ft_cross(t_data *info)
{
	if (info->mlx->img.img)
		mlx_destroy_image(info->mlx->mlx, info->mlx->img.img);
	if (info->mlx->win)
		mlx_destroy_window(info->mlx->mlx, info->mlx->win);
	exit(1);
}
