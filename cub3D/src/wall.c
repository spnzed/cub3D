/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:29:32 by aaronespino       #+#    #+#             */
/*   Updated: 2024/06/25 19:55:14 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	remove_fish(int player_dir, int ray_ang, int ray_len)
{
	int		rem_fish;
	float	distance;

	rem_fish = player_dir - ray_ang;
	distance = ray_len * cos(deg_to_rad(rem_fish));
	return (distance);
}

void	draw_text(t_img texture, int *scr, int offset, int height, int tex_x, int i)
{
	float	tex_y;
	int		tex_pixel;
	int		y_end;
	int		j;

	y_end = offset + height >= HEIGHT ? HEIGHT : offset + height;
	j = 0;
	while (j < y_end)
	{
		tex_y = ((float)(j - offset) / (float)height) * texture.height;
		tex_pixel = ((int)tex_y * texture.width + (int)tex_x);
		if (tex_x >= 0 && tex_x < texture.width && tex_y >= 0 \
			&& tex_y < texture.height)
			scr[j * WIDTH + i] = texture.img_adr[tex_pixel];
		j++;
	}
}

static void	draw_wallcol(t_data *info, int *scr, int ang, int i)
{
	float	distance;
	int		height;
	int		off;

	distance = remove_fish(info->player.dir, ang, info->ray[i].len);
	height = (SCALE * HEIGHT) / (distance);
	off = (HEIGHT / 2) - (height / 2);
	if (info->ray[i].wall_or == 'N')
		draw_text(info->mlx->north, scr, off, height, info->ray[i].text_p, i);
	else if (info->ray[i].wall_or == 'S')
		draw_text(info->mlx->south, scr, off, height, info->ray[i].text_p, i);
	else if (info->ray[i].wall_or == 'W')
		draw_text(info->mlx->west, scr, off, height, info->ray[i].text_p, i);
	else if (info->ray[i].wall_or == 'E')
		draw_text(info->mlx->east, scr, off, height, info->ray[i].text_p, i);
}

void	draw_walls(t_data *info)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		draw_wallcol(info, info->mlx->img.img_adr, info->ray[i].ang, i);
		i++;
	}
}
