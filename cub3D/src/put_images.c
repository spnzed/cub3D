/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:58:59 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/23 17:39:52 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	create_image(t_data *info)
{
	info->mlx.img.img = mlx_new_image(info->mlx.mlx, WIDTH, HEIGHT);
	if (!info->mlx.img.img)
	{
		printf(RED"Error: Not Able to get MLX_IMG\n"RESET);
		exit(1);
	}
	info->mlx.img.img_adr = mlx_get_data_addr(
			info->mlx.img.img,
			&info->mlx.img.bpp, 
			&info->mlx.img.str_len,
			&info->mlx.img.endian);
	if (!info->mlx.img.img_adr)
	{
		printf(RED"Error: Not Able to get MLX_IMG_ADR\n"RESET);
		exit(1);
	}
}

static void	check_64(t_img *img)
{
	if (img->width == 64 && img->height == 64)
		return ;
	printf(RED"Error: Insert Only Textures of 64 x 64 Pixels\n"RESET);
	exit(1);
}

static void	paint_walls(t_data *info, char *file, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx.mlx,
			file, &img->width, &img->height);
	if (!img->img)
	{
		printf(RED"Error: Couldn't Convert File .xpm to Image\n"RESET);
		exit(1);
	}
	img->img_adr = mlx_get_data_addr(
			img->img, &img->bpp, &img->str_len, &img->endian);
	if (!img->img_adr)
	{
		printf(RED"Error: Not Able to get MLX_IMG_ADR\n"RESET);
		exit(1);
	}
	check_64(img);
}

static void	create_textures(t_data *info)
{
	paint_walls(info, info->parameters.north, &info->mlx.north);
	paint_walls(info, info->parameters.south, &info->mlx.south);
	paint_walls(info, info->parameters.east, &info->mlx.east);
	paint_walls(info, info->parameters.west, &info->mlx.west);
}

void	put_images(t_data *info)
{
	create_image(info);
	create_textures(info);
}
