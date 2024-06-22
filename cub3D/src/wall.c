/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:04:07 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/22 14:58:19 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float degToRad(int a) { return a*M_PI/180.0;}

float	remove_fish(int player_dir, int ray_ang, int ray_len)
{
	int rem_fish;
	float distance;

	rem_fish = player_dir - ray_ang;
	distance = ray_len * cos(degToRad(rem_fish)); // Corrige "fisheye"
	return (distance);
}

void draw_text(t_img texture, int *scr, int offset, int height, int tex_x, int i)
{
	float tex_y;
    int tex_pixel;
    int texture_height = texture.height;
    int texture_width = texture.width;

    int y_start = offset < 0 ? 0 : offset;
    int y_end = offset + height >= HEIGHT ? HEIGHT : offset + height;

    for (int y = y_start; y < y_end; y++) {
        tex_y = ((float)(y - offset) / (float)height) * texture_height;
        tex_pixel = ((int)tex_y * texture_width + (int)tex_x);

        if (tex_x >= 0 && tex_x < texture_width && tex_y >= 0 && tex_y < texture_height) {
            scr[y * WIDTH + i] = texture.img_adr[tex_pixel];
        }
    }
}

static void draw_wallcol(t_data *info, int *scr, int ang, int i)
{
    float distance;
    int height;
    int offset;

    distance = remove_fish(info->player.dir, ang, info->ray[i].len);
    height = (SCALE * HEIGHT) / (distance); // Calcula la altura de la línea
    offset = (HEIGHT / 2) - (height / 2);   // Calcula el offset de la línea

	if (info->ray[i].wall_or == 'N')
		draw_text(info->mlx->north, scr, offset, height, info->ray[i].text_p, i);
	else if (info->ray[i].wall_or == 'S')
		draw_text(info->mlx->south, scr, offset, height, info->ray[i].text_p, i);
	else if (info->ray[i].wall_or == 'W')
		draw_text(info->mlx->west, scr, offset, height, info->ray[i].text_p, i);
	else if (info->ray[i].wall_or == 'E')
		draw_text(info->mlx->east, scr, offset, height, info->ray[i].text_p, i);
}

void draw_walls(t_data *info)
{
	int i;

	i = 0;
	while (i < WIDTH)
	{
		draw_wallcol(info, info->mlx->img.img_adr, info->ray[i].ang, i);
		i++;
	}
}