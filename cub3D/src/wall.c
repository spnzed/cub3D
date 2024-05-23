/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:04:07 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/23 19:34:47 by aaespino         ###   ########.fr       */
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

void	draw_wall(t_data *info, int *scr, int ang, int i)
{
	float distance;
	int height;
	int offset;

	distance = remove_fish(info->player.dir, ang, info->ray[i].len);
	height = (SCALE * 320) / (distance); // Calcula la altura de la línea
	if (height > 320) 
    	height = 320;
	offset = 160 - (height / 2); // Calcula el offset de la línea

	// t_point wall_pts[2] = {{i * 8 + 530, offset}, {i * 8 + 530, offset + height}};
    // draw_line(scr, wall_pts, 0xff0000, 8); // Blanco para las paredes  

	// Calcula las coordenadas de textura
	float tex_x = (float)i / (float)WIDTH * info->mlx->north.width;
	// int tex_y = 0; // Puedes calcular la coordenada y de textura basándote en el ángulo o la distancia si es necesario

	// Dibuja la pared vertical correspondiente en la pantalla usando la textura
	for (int y = offset; y < offset + height; y++) // Itera sobre la altura completa de la pared
	{
		// Ajusta las coordenadas de textura para que se mapeen correctamente a la altura de la pared
		float tex_y = ((float)(y - offset) / (float)height) * info->mlx->north.width;

		// Itera sobre el grosor de la línea de textura
		for (int dy = 0; dy < 8; dy++)
		{
			// Calcula la coordenada y de textura correspondiente a este píxel
			int tex_pixel = ((int)tex_y + dy) * info->mlx->north.width + (int)tex_x;

			// Copia el color del píxel de la textura al buffer de pantalla
			if (tex_x >= 0 && tex_x < info->mlx->north.width && tex_y >= 0 && tex_y < info->mlx->north.width)
			{
				// Dibuja la textura con el mismo grosor que la línea roja
				for (int dx = 0; dx < 8; dx++) // Itera sobre el grosor deseado
				{
					scr[(y + dy) * WIDTH + (i * 8 + 530) + dx] = info->mlx->north.img_adr[tex_pixel];
				}
			}
		}
	}
}