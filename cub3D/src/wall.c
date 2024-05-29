/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:04:07 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/29 19:37:02 by aaronespino      ###   ########.fr       */
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

// void	draw_wall(t_data *info, int *scr, int ang, int i)
// {
// 	float distance;
// 	int height;
// 	int offset;

// 	(void)scr;
// 	distance = remove_fish(info->player.dir, ang, info->ray[i].len);
// 	height = (SCALE * HEIGHT) / (distance); // Calcula la altura de la línea
// 	if (height > HEIGHT) 
//     	height = HEIGHT;
// 	offset = (HEIGHT / 2) - (height / 2); // Calcula el offset de la línea

// 	int x_position = (i * WIDTH) / (WIDTH / 2); // Distribuye las líneas uniformemente a lo largo del ancho de la pantalla
// 	t_point wall_pts[2] = {{x_position, offset}, {x_position, offset + height}};

// 	if (info->ray[i].wall_or == 'N')
//     	draw_line(info->mlx->img.img_adr, wall_pts, 0xff0000, 2); // Red
// 	else if (info->ray[i].wall_or == 'S')
//     	draw_line(info->mlx->img.img_adr, wall_pts, 0x00ff00, 2); // Green  
// 	else if (info->ray[i].wall_or == 'W')
//     	draw_line(info->mlx->img.img_adr, wall_pts, 0x0000ff, 2); // Blue	  
// 	else if (info->ray[i].wall_or == 'E')
//     	draw_line(info->mlx->img.img_adr, wall_pts, 0xffff00, 2); // Yellow  
// }

void draw_wall(t_data *info, int *scr, int ang, int i) {
    float distance;
    int height;
    int offset;
    t_img *texture;

    (void)scr;
    distance = remove_fish(info->player.dir, ang, info->ray[i].len);
    height = (SCALE * HEIGHT) / (distance); // Calcula la altura de la línea
    if (height > HEIGHT)
        height = HEIGHT;
    offset = (HEIGHT / 2) - (height / 2); // Calcula el offset de la línea

    int x_position = (i * WIDTH) / (WIDTH / 2); // Distribuye las líneas uniformemente a lo largo del ancho de la pantalla

    // Selecciona la textura correcta basada en la orientación de la pared
    if (info->ray[i].wall_or == 'N')
        texture = &info->mlx->north;
    else if (info->ray[i].wall_or == 'S')
        texture = &info->mlx->south;
    else if (info->ray[i].wall_or == 'W')
        texture = &info->mlx->west;
    else if (info->ray[i].wall_or == 'E')
        texture = &info->mlx->east;
    else
        return; // No hay orientación válida, sal de la función

    // Calcula la coordenada x de la textura
    int texture_x = (int)(info->ray[i].map_p * texture->width);

    // Dibuja cada par de píxeles de la línea vertical de la pared
    for (int y = 0; y < height; y++) {
        // Repite dos veces para imprimir dos píxeles por iteración
        for (int k = 0; k < 2; k++) {
            int texture_y = (int)((float)y / height * texture->height);
            int color = texture->img_adr[texture_y * texture->width + texture_x];
            if (offset + y >= 0 && offset + y < HEIGHT) {
                // Calcula la posición del píxel a imprimir
                int pixel_position = (offset + y) * WIDTH + x_position + k;
                // Asigna el color a los píxeles correspondientes
                info->mlx->img.img_adr[pixel_position] = color;
            }
        }
    }
}