/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:58:59 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/15 15:29:50 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_img_scale(t_img *img)
{
	if (img->width == SCALE && img->height == SCALE)
		return ;
	ft_err("Error: Insert Only Textures of 64 x 64 Pixels\n");
	exit(1);
}

static void	paint_walls(t_data *info, char *file, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx->mlx,
			file, &img->width, &img->height);
	if (!img->img)
	{
		ft_err("Error: Couldn't Convert File .xpm to Image\n");
		exit(1);
	}
	img->img_adr = (int *)mlx_get_data_addr(
			img->img, &img->bpp, &img->str_len, &img->endian);
	if (!img->img_adr)
	{
		ft_err("Error: Not Able to get MLX_IMG_ADR\n");
		exit(1);
	}
	check_img_scale(img);
}

static void	create_textures(t_data *info)
{
	paint_walls(info, info->parameters.north, &info->mlx->north);
	paint_walls(info, info->parameters.south, &info->mlx->south);
	paint_walls(info, info->parameters.east, &info->mlx->east);
	paint_walls(info, info->parameters.west, &info->mlx->west);
}

void	put_images(t_data *info)
{
	create_image(info);
	create_textures(info);
	// new_scene(info);
}
