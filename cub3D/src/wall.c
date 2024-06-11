/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:04:07 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/07 20:18:36 by aaronespino      ###   ########.fr       */
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

void static	draw_wallcol(t_data *info, int *scr, int ang, int i)
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

	int x_position = (i * WIDTH) / 240; // NUM_RAYS es el número total de rayos

	t_point wall_pts[2] = {{x_position, offset}, {x_position, offset + height}};

	if (info->ray[i].wall_or == 'N')
    	draw_line(info->mlx->img.img_adr, wall_pts, 0xff0000, 1); // Red
	else if (info->ray[i].wall_or == 'S')
    	draw_line(info->mlx->img.img_adr, wall_pts, 0x00ff00, 1); // Green  
	else if (info->ray[i].wall_or == 'W')
    	draw_line(info->mlx->img.img_adr, wall_pts, 0x0000ff, 1); // Blue	  
	else if (info->ray[i].wall_or == 'E')
    	draw_line(info->mlx->img.img_adr, wall_pts, 0xffff00, 1); // Yellow  
	// Calcula las coordenadas de textura
	// float tex_x = (float)i / (float)WIDTH * info->mlx->north.width;
	// int tex_y = 0; // Puedes calcular la coordenada y de textura basándote en el ángulo o la distancia si es necesario

	// // Dibuja la pared vertical correspondiente en la pantalla usando la textura
	// for (int y = offset; y < offset + height; y++) // Itera sobre la altura completa de la pared
	// {
	// 	// Ajusta las coordenadas de textura para que se mapeen correctamente a la altura de la pared
	// 	float tex_y = ((float)(y - offset) / (float)height) * info->mlx->north.width;

	// 	// Itera sobre el grosor de la línea de textura
	// 	for (int dy = 0; dy < 8; dy++)
	// 	{
	// 		// Calcula la coordenada y de textura correspondiente a este píxel
	// 		int tex_pixel = ((int)tex_y + dy) * info->mlx->north.width + (int)tex_x;

	// 		// Copia el color del píxel de la textura al buffer de pantalla
	// 		if (tex_x >= 0 && tex_x < info->mlx->north.width && tex_y >= 0 && tex_y < info->mlx->north.width)
	// 		{
	// 			// Dibuja la textura con el mismo grosor que la línea roja
	// 			for (int dx = 0; dx < 8; dx++) // Itera sobre el grosor deseado
	// 			{
	// 				scr[(y + dy) * WIDTH + (i * 8 + 530) + dx] = info->mlx->north.img_adr[tex_pixel];
	// 			}
	// 		}
	// 	}
	// }
}

void draw_walls(t_data *info)
{
	int i;

	i = 0;
	while (i < 480) //haura de ser WIDTH
	{
		draw_wallcol(info, info->mlx->img.img_adr, info->ray[i].ang, i);
		i++;
	}

}