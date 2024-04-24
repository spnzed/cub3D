/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:43:39 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/24 15:33:43 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_press(int keycode, t_mlx *mlx)
{
	mlx->keys = malloc(sizeof(t_keys *));
	if (!mlx->mlx)
	{
		printf(RED"Error: MLX\n"RESET);
		exit(1);
	}
	if (keycode == KEY_W)
		mlx->keys->W = 1;
	else if (keycode == KEY_A)
		mlx->keys->A = 1;
	else if (keycode == KEY_S)
		mlx->keys->S = 1;
	else if (keycode == KEY_D)
		mlx->keys->D = 1;
	else if (keycode == KEY_LEFT)
		mlx->keys->L_ARR = 1;
	else if (keycode == KEY_RIGHT)
		mlx->keys->R_ARR = 1;
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
		mlx->keys->W = 0;
	else if (keycode == KEY_A)
		mlx->keys->A = 0;
	else if (keycode == KEY_S)
		mlx->keys->S = 0;
	else if (keycode == KEY_D)
		mlx->keys->D = 0;
	else if (keycode == KEY_LEFT)
		mlx->keys->L_ARR = 0;
	else if (keycode == KEY_RIGHT)
		mlx->keys->R_ARR = 0;
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