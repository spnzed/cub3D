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
	else
		return;
}

int	render(t_data *info)
{
	// ray_casting(info);
	mlx_put_image_to_window(info->mlx->mlx,
		info->mlx->win, info->mlx->img.img, 0, 0);
	mlx_put_image_to_window(info->mlx->mlx, info->mlx->win, info->minipl->ptr,
		info->minipl->x, info->minipl->y);
	handle_key(info);
	return (0);
}
