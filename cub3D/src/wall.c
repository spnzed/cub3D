/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:04:07 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/23 16:01:20 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float degToRad(int a) { return a*M_PI/180.0;}

int	remove_fish(int player_dir, int ray_ang, int ray_len)
{
	int rem_fish;
	int distance;

	printf("%d %d %d\n", player_dir, ray_ang, ray_len);
	rem_fish = angle_correction(player_dir - ray_ang);
	printf("%f\n", cos(degToRad(rem_fish)));
	distance = ray_len * cos(degToRad(rem_fish)); // Corrige "fisheye"
	return (distance);
}

void	draw_wall(t_data *info, int *scr, int ang, int i)
{
	int distance;
	int height;
	int offset;
	
	(void)ang;
	printf("HOLA\n");
	distance = remove_fish(info->player.dir, info->ray[i].draw_end,
					info->ray[i].len);
	printf("%d\n", distance);
	height = (SCALE * 320) / (distance); // Calcula la altura de la línea
	if (height > 320) 
    	height = 320;
	printf("HOLA\n");
	// Limita la altura de la línea
	printf("HOLA\n");
	offset = 160 - (height >> 1); // Calcula el offset de la línea

	// Dibuja la pared vertical correspondiente en la pantalla
	 t_point wall_pts[2] = {{i * 8 + 530, offset}, {i * 8 + 530, offset + height}};
    draw_line(scr, wall_pts, 0xFFFFFF); // Blanco para las paredes  
}