/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_orient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:01:53 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/30 20:59:40 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static char	fourth(t_ray *ray)
// {
// 	int	i;

// 	i = 0;
// 	pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 	pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
// 		&& pts[1].y >= 0 && pts[1].x >= 0
// 		&& pts[1].x < WIDTH && pts[1].y < HEIGHT
// 		&& scr[WIDTH * pts[1].y + pts[1].x + 1] != 0xFFFFFF
// 		&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH] != 0xFFFFFF)
// 	{
// 		i++;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// 	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF
// 		|| (scr[WIDTH * pts[1].y + pts[1].x - 1] == 0xFFFFFF
// 			&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] == 0xFFFFFF))
// 	{
// 		i -= 1;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// }

// static char	third(t_ray *ray)
// {
// 	int	i;

// 	i = 0;
// 	pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 	pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
// 		&& pts[1].y >= 0 && pts[1].x >= 0
// 		&& pts[1].x < WIDTH && pts[1].y < HEIGHT
// 		&& scr[WIDTH * pts[1].y + pts[1].x - 1] != 0xFFFFFF
// 		&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH] != 0xFFFFFF)
// 	{
// 		i++;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// 	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF
// 		|| (scr[WIDTH * pts[1].y + pts[1].x + 1] == 0xFFFFFF
// 			&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] == 0xFFFFFF))
// 	{
// 		i -= 1;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// }

// static char	second(t_ray *ray)
// {
// 	int	i;

// 	i = 0;
// 	pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 	pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
// 		&& pts[1].y >= 0 && pts[1].x >= 0
// 		&& pts[1].x < WIDTH && pts[1].y < HEIGHT
// 		&& scr[WIDTH * pts[1].y + pts[1].x - 1] != 0xFFFFFF
// 		&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] != 0xFFFFFF)
// 	{
// 		i++;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// 	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF
// 		|| (scr[WIDTH * pts[1].y + pts[1].x + 1] == 0xFFFFFF
// 			&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH] == 0xFFFFFF))
// 	{
// 		i -= 1;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// }

static char	first(t_data *info,t_ray *ray)
{
	int	i;
	int	x;
	int y;

	i = 0;
	x = pts[0].x + cos(deg_to_rad(ang)) * i;
	y = pts[0].y - sin(deg_to_rad(ang)) * i;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& pts[1].y >= 0 && pts[1].x >= 0
		&& pts[1].x < WIDTH && pts[1].y < HEIGHT
		&& scr[WIDTH * pts[1].y + pts[1].x + 1] != 0xFFFFFF
		&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] != 0xFFFFFF)
	{
		i++;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}
	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF
		|| (scr[WIDTH * pts[1].y + pts[1].x - 1] == 0xFFFFFF
			&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH] == 0xFFFFFF))
	{
		i -= 1;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}
}


char	get_wall_or(t_data *info, t_ray *ray)
{
	char	res;

	res = 0;
	if (ray->ang > 0 && ray->ang < 90)
		res = first(info, ray);
	/*else if (ray->ang > 90 && ray->ang < 180)
		res = second(scr, ray->end[X], ray->end[Y], ray->ang);
	else if (ray->ang > 180 && ray->ang < 270)
		third(scr, ray->end[X], ray->end[Y], ray->ang);
	else if (ray->ang > 270 && ray->ang < 360)
		fourth(scr, ray->end[X], ray->end[Y], ray->ang);*/
	return (res);
}
