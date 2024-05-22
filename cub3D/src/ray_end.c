/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:34:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/22 17:25:28 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	deg0(int *scr, t_point *pts)
{
	pts[1].x = pts[0].x + 1;
	pts[1].y = pts[0].y;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].x >= 0
		&& WIDTH * pts[1].y + pts[1].x < WIDTH * HEIGHT)
		pts[1].x++;
	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF)
		pts[1].x--;
}

static void	deg180(int *scr, t_point *pts)
{
	pts[1].x = pts[0].x - 1;
	pts[1].y = pts[0].y;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].x >= 0
		&& WIDTH * pts[1].y + pts[1].x < WIDTH * HEIGHT)
		pts[1].x--;
	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF)
		pts[1].x++;
}

static void	deg90(int *scr, t_point *pts)
{
	pts[1].x = pts[0].x;
	pts[1].y = pts[0].y - 1;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].x >= 0
		&& WIDTH * pts[1].y + pts[1].x < WIDTH * HEIGHT)
		pts[1].y--;
	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF)
		pts[1].y++;
}

static void	deg270(int *scr, t_point *pts)
{
	pts[1].x = pts[0].x;
	pts[1].y = pts[0].y + 1;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].x >= 0
		&& WIDTH * pts[1].y + pts[1].x < WIDTH * HEIGHT)
		pts[1].y++;
	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF)
		pts[1].y--;
}

void	ray_end(int *scr, t_point *pts, float ang)
{
	if (ang == 90)
		deg90(scr, pts);
	else if (ang == 270)
		deg270(scr, pts);
	else if (ang == 0)
		deg0(scr, pts);
	else if (ang == 180)
		deg180(scr, pts);
	else
		other_angles(scr, pts, ang);
}
