/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:57:22 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/14 18:23:08 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_image(t_img *img)
{
	img->str_len = WIDTH;
	img->bpp = 32;
	img->endian = 0;
}

void	create_image(t_data *info)
{
	init_image(&info->mlx->img);
	info->mlx->img.img = mlx_new_image(info->mlx->mlx, WIDTH, HEIGHT);
	if (!info->mlx->img.img)
	{
		ft_err("Error: Not Able to get MLX_IMG\n");
		exit(1);
	}
	info->mlx->img.img_adr = (int *)mlx_get_data_addr(
			info->mlx->img.img,
			&info->mlx->img.bpp,
			&info->mlx->img.str_len,
			&info->mlx->img.endian);
	if (!info->mlx->img.img_adr)
	{
		ft_err("Error: Not Able to get MLX_IMG_ADR\n");
		exit(1);
	}
}
