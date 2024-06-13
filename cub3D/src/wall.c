/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:04:07 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/12 00:11:08 by aaronespino      ###   ########.fr       */
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

void draw_text(t_img texture, int *scr, int offset, int height, int i)
{
	// Calcula las coordenadas de textura
    float tex_x = (float)i / (float)WIDTH * texture.width;

	for (int y = offset; y < offset + height; y++) // Itera sobre la altura completa de la pared
    {
        // Ajusta las coordenadas de textura para que se mapeen correctamente a la altura de la pared
        float tex_y = ((float)(y - offset) / (float)height) * texture.width;

        // Itera sobre el grosor de la línea de textura
        for (int dy = 0; dy < 8; dy++)
        {
            // Calcula la coordenada y de textura correspondiente a este píxel
            int tex_pixel = ((int)tex_y + dy) * texture.width + (int)tex_x;

            // Copia el color del píxel de la textura al buffer de pantalla
            if (tex_x >= 0 && tex_x < texture.width && tex_y >= 0 && tex_y < texture.width)
            {
                // Dibuja la textura con el mismo grosor que la línea roja
                for (int dx = 0; dx < 8; dx++) // Itera sobre el grosor deseado
                    scr[(y + dy) * WIDTH + i + dx] = texture.img_adr[tex_pixel];
            }
        }
    }

}

void static draw_wallcol(t_data *info, int *scr, int ang, int i)
{
    float distance;
    int height;
    int offset;

    (void)scr;
    distance = remove_fish(info->player.dir, ang, info->ray[i].len);
    height = (SCALE * HEIGHT) / (distance); // Calcula la altura de la línea
    if (height > HEIGHT)
        height = HEIGHT;
    offset = (HEIGHT / 2) - (height / 2); // Calcula el offset de la línea
	if (info->ray[i].wall_or == 'N')
		draw_text(info->mlx->north, scr, offset, height, i);
	else if (info->ray[i].wall_or == 'S')
		draw_text(info->mlx->south, scr, offset, height, i);
	else if (info->ray[i].wall_or == 'W')
		draw_text(info->mlx->west, scr, offset, height, i);
	else if (info->ray[i].wall_or == 'E')
		draw_text(info->mlx->east, scr, offset, height, i);
}

void draw_walls(t_data *info)
{
	int i;

	i = 0;
	while (i < WIDTH) //haura de ser WIDTH
	{
		draw_wallcol(info, info->mlx->img.img_adr, info->ray[i].ang, i);
		i++;
	}

}