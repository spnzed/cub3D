/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:58:37 by aaronespino       #+#    #+#             */
/*   Updated: 2024/05/15 14:38:33 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calc_positions(t_data *info, int i)
{
	info->ray.camera = 2 * i / (double)WIDTH - 1;
	info->ray.raydir[X] = info->ray.dir[X] + \
		info->ray.plane[X] * info->ray.camera;
	info->ray.raydir[Y] = info->ray.dir[Y] + \
		info->ray.plane[Y] * info->ray.camera;
	info->ray.deltadist[X] = sqrt(1 + (info->ray.raydir[Y] \
		* info->ray.raydir[Y]) / (info->ray.raydir[X] * info->ray.raydir[X]));
	info->ray.deltadist[Y] = sqrt(1 + (info->ray.raydir[X] \
		* info->ray.raydir[X]) / (info->ray.raydir[Y] * info->ray.raydir[Y]));
}

void	calc_step(t_data *info)
{
	if (info->ray.raydir[X] < 0)
	{
		info->ray.step[X] = -1;
		info->ray.sidedist[X] = (info->player.x - info->ray.pos[X]) \
			* info->ray.deltadist[X];
	}
	else
	{
		info->ray.step[X] = 1;
		info->ray.sidedist[X] = (info->ray.pos[X] + 1.0 - info->player.x) \
			* info->ray.deltadist[X];
	}
	if (info->ray.raydir[Y] < 0)
	{
		info->ray.step[Y] = -1;
		info->ray.sidedist[Y] = (info->player.y - info->ray.pos[Y]) \
			* info->ray.deltadist[Y];
	}
	else
	{
		info->ray.step[Y] = 1;
		info->ray.sidedist[Y] = (info->ray.pos[Y] + 1.0 - info->player.y) \
			* info->ray.deltadist[Y];
	}
}

void	calc_hit(t_data *info)
{
	while (1)
	{
		if (info->ray.sidedist[X] < info->ray.sidedist[Y])
		{
			info->ray.sidedist[X] += info->ray.deltadist[X];
			info->ray.pos[X] += info->ray.step[X];
			info->ray.side[X] = 1;
			info->ray.side[Y] = 0;
			if (info->ray.step[X] < 0)
				info->ray.side[X] = -1;
		}
		else
		{
			info->ray.sidedist[Y] += info->ray.deltadist[Y];
			info->ray.pos[Y] += info->ray.step[Y];
			info->ray.side[X] = 0;
			info->ray.side[Y] = 1;
			if (info->ray.step[Y] < 0)
				info->ray.side[Y] = -1;
		}
		if (info->map.grid[info->ray.pos[X]][info->ray.pos[Y]] > 0)
			break ;
	}
}

void	calc_perp(t_data *info)
{
	if (info->ray.side[X] != 0)
		info->ray.perpwalldist = fabs((info->ray.pos[X] - info->ray.pos[X] + \
			(1 - info->ray.step[X]) / 2) / info->ray.dir[X]);
	else
		info->ray.perpwalldist = fabs((info->ray.pos[Y] - info->ray.pos[Y] + \
			(1 - info->ray.step[Y]) / 2) / info->ray.dir[Y]);
	info->ray.lineh = abs((int)(HEIGHT / info->ray.perpwalldist));
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
void ray_casting(t_data *info)
{
	int		 i;

	i = 0;
	info->ray.plane[X] = 0;
	info->ray.plane[Y] = 0.66;
	info->ray.pos[X] = info->player.x;
	info->ray.pos[Y] = info->player.y;
	info->ray.dir[X] = info->player.dir[X];
	info->ray.dir[Y] = info->player.dir[Y];
	while (i < WIDTH)
	{
		calc_positions(info, i);
		calc_step(info);
		calc_hit(info);
		calc_perp(info);
		init_texture(info);
	}
}
