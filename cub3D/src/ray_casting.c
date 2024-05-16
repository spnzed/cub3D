/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:58:37 by aaronespino       #+#    #+#             */
/*   Updated: 2024/05/15 19:46:18 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_ray(t_data *info)
{
	info->ray.pos[X] = info->player.x;
	info->ray.pos[Y] = info->player.y;
	info->ray.dir[X] = info->player.dir[X];
	info->ray.dir[Y] = info->player.dir[Y];
}

/*
calc_positions();

	Calculamos la posición de la cámara en el plano de la proyección (-1 a 1)
	Inicializamos la posición y dirección del rayo
	Calculamos la posición de la celda del mapa en la que se encuentra el jugador
	Longitudes de los rayos en X e Y hasta la próxima celda del mapa

step();

	Detección de la dirección del rayo en X

calc_hit();

	Bucle para lanzar el rayo y determinar la intersección con el mapa

calc_perp(info, i);		

	Calculamos: 
	- Distancia perpendicular al muro y la altura de la línea a dibujar
	- Altura de la línea a dibujar en función de la distancia perpendicular al muro
	- Coordenadas de inicio y fin de la línea a dibujar en la pantalla

verLine();

	Dibujamos la línea vertical correspondiente al rayo en la pantalla

	info->ray.draw[START] = -info->ray.lineHeight / 2 + HEIGHT / 2;
	if (info->ray.draw[START] < 0)
		info->ray.draw[START] = 0;
	info->ray.draw[END] = info->ray.lineHeight / 2 + HEIGHT / 2;
	if (info->ray.draw[END] >= HEIGHT)
		info->ray.draw[END] = HEIGHT - 1;
*/
void	calculations(t_data *info, int i)
{
	calc_positions(info, i);
	calc_step(info);
	calc_hit(info);
	calc_perp(info);
}

void	ray_casting(t_data *info)
{
	int		 i;

	i = 0;
	info->ray.plane[X] = 0;
	info->ray.plane[Y] = 0.66;
	while (i < WIDTH)
	{
		init_ray(info);
		calculations(info, i);
		// init_texture(info, i);
	}
}
