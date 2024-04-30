/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:58:37 by aaronespino       #+#    #+#             */
/*   Updated: 2024/04/30 17:36:09 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calc_positions(t_data *info, int i)
{
	info->ray.camera = 2 * i / (double)WIDTH - 1;
	info->ray.rayDir[X] = info->ray.dir[X] + \
		info->ray.plane[X] * info->ray.camera;
	info->ray.rayDir[Y] = info->ray.dir[Y] + \
		info->ray.plane[Y] * info->ray.camera;
	info->ray.deltaDist[X] = sqrt(1 + (info->ray.rayDir[Y] \
		 * info->ray.rayDir[Y]) / (info->ray.rayDir[X] * info->ray.rayDir[X]));
	info->ray.deltaDist[Y] = sqrt(1 + (info->ray.rayDir[X] \
		 * info->ray.rayDir[X]) / (info->ray.rayDir[Y] * info->ray.rayDir[Y]));
}

void	calc_step(t_data *info)
{
	if (info->ray.rayDir[X] < 0)
	{
		info->ray.step[X] = -1;
		info->ray.sideDist[X] = (info->player.x - info->ray.pos[X]) \
			* info->ray.deltaDist[X];
	}
	else
	{
		info->ray.step[X] = 1;
		info->ray.sideDist[X] = (info->ray.pos[X] + 1.0 - info->player.x) \
			* info->ray.deltaDist[X];
	}
	if (info->ray.rayDir[Y] < 0)
	{
		info->ray.step[Y] = -1;
		info->ray.sideDist[Y] = (info->player.y - info->ray.pos[Y]) \
			* info->ray.deltaDist[Y];
	}
	else
	{
		info->ray.step[Y] = 1;
		info->ray.sideDist[Y] = (info->ray.pos[Y] + 1.0 - info->player.y) \
			* info->ray.deltaDist[Y];
	}
}

void	calc_hit(t_data *info)
{
	int hit = 0;
	while (!hit)
	{
		if (info->ray.sideDist[X] < info->ray.sideDist[Y])
		{
			info->ray.sideDist[X] += info->ray.deltaDist[X];
			info->ray.pos[X] += info->ray.step[X];
			info->ray.side[X] = 1;
			info->ray.side[Y] = 0;
			if (info->ray.step[X] < 0)
				info->ray.side[X] = -1;
		}
		else
		{
			info->ray.sideDist[Y] += info->ray.deltaDist[Y];
			info->ray.pos[Y] += info->ray.step[Y];
			info->ray.side[X] = 0;
			info->ray.side[Y] = 1;
			if (info->ray.step[Y] < 0)
				info->ray.side[Y] = -1;
		}
		if (info->map.grid[(int)info->ray.pos[X]][(int)info->ray.pos[Y]] > 0)
			hit = 1;
	}
}

void	calc_perp(t_data *info)
{
	if (info->ray.side == 0)
		info->ray.perpWallDist = fabs((info->ray.pos[X] - info->ray.pos[X] + \
			(1 - info->ray.step[X]) / 2) / info->ray.rayDir[X]);
	else
		info->ray.perpWallDist = fabs((info->ray.pos[Y] - info->ray.pos[Y] + \
			(1 - info->ray.step[Y]) / 2) / info->ray.rayDir[Y]);
	info->ray.lineHeight = abs((int)(HEIGHT / info->ray.perpWallDist));
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
static void ray_casting(t_data *info)
{
	int		 i;

	i = 0;
	info->ray.plane[X] = 0;
	info->ray.plane[Y] = 0.66;
	info->ray.pos[X] = info->player.x;
	info->ray.pos[Y] = info->player.y;
	info->ray.dir[X] = info->player.dir_cor[X];
	info->ray.dir[Y] = info->player.dir_cor[Y];
	while (i < WIDTH)
	{
		calc_positions(info, i);
		calc_step(info);
		calc_hit(info);
		calc_perp(info);
		init_texture(info);
	}
}
