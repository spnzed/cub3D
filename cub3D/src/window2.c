/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:45:33 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/27 18:11:09 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*static int	render2(t_data *info)
{
	handle_key(info);
    get_bigmap2d(info);
	cast_rays(info);
	mlx_put_image_to_window(info->mlx->mlx,
		info->mlx->win, info->mlx->img.img, 0, 0);
	return (0);
}

int	init_window2(t_data *info)
{
	info->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!info->mlx)
		exit (1);
	info->mlx->mlx = mlx_init();
	info->mlx->win = mlx_new_window(info->mlx->mlx, WIDTH, HEIGHT, "map2D");
	init_keys(info->mlx);
	put_images(info);
	put_position(info);
	return (0);
}

void	init_loop2(t_data *info)
{
	mlx_hook(info->mlx->win, 2, 1L << 0, &ft_press, info->mlx);
	mlx_hook(info->mlx->win, 3, 1L << 1, &ft_release, info->mlx);
	mlx_hook(info->mlx->win, 17, 0, &ft_cross, info->mlx);
	mlx_loop_hook(info->mlx->mlx, &render2, info);
	mlx_loop(info->mlx->mlx);
}*/