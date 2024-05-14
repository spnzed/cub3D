/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:43:39 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/30 15:50:46 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_key(t_data *info)
{
	if (!info->mlx->mlx)
	{
		printf(RED"Error: MLX\n"RESET);
		exit(1);
	}
	if (info->mlx->keys->w)
		move_front(info);
	if (info->mlx->keys->a)
		move_left(info);
	if (info->mlx->keys->s)
		move_back(info);
	if (info->mlx->keys->d)
		move_right(info);
	if (info->mlx->keys->l_arr)
		move_l_arrow(info);
	if (info->mlx->keys->r_arr)
		move_r_arrow(info);
}

int	ft_press(int keycode, t_mlx *mlx)
{
	mlx->keys = malloc(sizeof(t_keys *));
	if (!mlx->mlx)
	{
		printf(RED"Error: MLX\n"RESET);
		exit(1);
	}
	if (keycode == KEY_W)
		mlx->keys->w = 1;
	else if (keycode == KEY_A)
		mlx->keys->a = 1;
	else if (keycode == KEY_S)
		mlx->keys->s = 1;
	else if (keycode == KEY_D)
		mlx->keys->d = 1;
	else if (keycode == KEY_LEFT)
		mlx->keys->l_arr = 1;
	else if (keycode == KEY_RIGHT)
		mlx->keys->r_arr = 1;
	return (0);
}

int	ft_release(int keycode, t_mlx *mlx)
{
	if (!mlx->mlx)
	{
		printf(RED"Error: MLX\n"RESET);
		exit(1);
	}
	if (keycode == KEY_W)
		mlx->keys->w = 0;
	else if (keycode == KEY_A)
		mlx->keys->a = 0;
	else if (keycode == KEY_S)
		mlx->keys->s = 0;
	else if (keycode == KEY_D)
		mlx->keys->d = 0;
	else if (keycode == KEY_LEFT)
		mlx->keys->l_arr = 0;
	else if (keycode == KEY_RIGHT)
		mlx->keys->r_arr = 0;
	return (0);
}

int	ft_esc(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx);
		exit(1);
	}
	return (0);
}

int	ft_cross(t_mlx *mlx)
{
	if (mlx->img.img)
		mlx_destroy_image(mlx->mlx, mlx->img.img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx)
		free(mlx);
	exit(1);
	return (0);
}