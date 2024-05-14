/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:43:39 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/14 18:23:41 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_esc(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
	exit(1);
}

int	ft_press(int keycode, t_mlx *mlx)
{
	if (!mlx->keys)
	{
		ft_err("Error: key struct is not initialized\n");
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
		mlx->keys->left = 1;
	else if (keycode == KEY_RIGHT)
		mlx->keys->right = 1;
	else if (keycode == KEY_ESC)
		ft_esc(mlx);
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
	else if (keycode == KEY_A)
		mlx->keys->a = 0;
	else if (keycode == KEY_S)
		mlx->keys->s = 0;
	else if (keycode == KEY_D)
		mlx->keys->d = 0;
	else if (keycode == KEY_LEFT)
		mlx->keys->left = 0;
	else if (keycode == KEY_RIGHT)
		mlx->keys->right = 0;
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
