/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:58:59 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/03 19:51:45 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	paint_ceil_floor(int *p)
{
	int	y;
	int	x;
	int	floor;
	int	ceiling;

	x = 0;
	y = 0;
	floor = 0xd9a066;
	ceiling = 0x5fcde4;
	//color = 0x0000FF;
	while (y < HEIGHT / 2)
	{
		while (x < WIDTH)
		{
			p[(y * WIDTH) + x] = ceiling;
			x++;
		}
		x = 0;
		y++;
	}
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			p[(y * WIDTH) + x] = floor;
			x++;
		}
		x = 0;
		y++;
	}
}
static void	init_image(t_img *img)
{
	img->str_len = WIDTH;
	img->bpp = 32;
	img->endian = 0;
}

static void	create_image(t_data *info)
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
	printf("ceiling: %i, floor: %i\n", info->map.ceiling, info->map.floor);
	paint_ceil_floor(info->mlx->img.img_adr);
	//mlx_put_image_to_window(info->mlx->mlx, info->mlx->win, info->mlx->img.img, 0, 0);
	mini_map(info);
	get_bigmap2d(info);
}
