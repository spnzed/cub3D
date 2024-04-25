/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:46:35 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/24 18:35:58 by aaespino         ###   ########.fr       */
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
	if (info->mlx->keys->W)
		move_front(info);
	if (info->mlx->keys->A)
		move_left(info);
	if (info->mlx->keys->S)
		move_back(info);
	if (info->mlx->keys->D)
		move_right(info);
	if (info->mlx->keys->L_ARR)
		move_l_arrow(info);
	if (info->mlx->keys->R_ARR)
		move_r_arrow(info);
}

int	render(t_data *info)
{
	handle_key(info);
	// ray_casting(info);
	mlx_put_image_to_window(info->mlx->mlx,
		info->mlx->win, info->mlx->img.img, 0, 0);
}