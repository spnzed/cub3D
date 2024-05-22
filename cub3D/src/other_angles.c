/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_angles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:43:13 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/22 17:56:53 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fourth_quadr(int *scr, t_point *pts, int ang)
{
	int		i;

	i = 0;
	pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
	pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].x >= 0
		&& WIDTH * pts[1].y + pts[1].x < WIDTH * HEIGHT
		&& scr[WIDTH * pts[1].y + pts[1].x - 1] != 0xFFFFFF
		&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] != 0xFFFFFF)
	{
		i++;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}
	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF
		|| (scr[WIDTH * pts[1].y + pts[1].x - 1] == 0xFFFFFF
			&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] == 0xFFFFFF))
	{
		i--;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}
}

static void	third_quadr(int *scr, t_point *pts, int ang)
{
	int		i;

	i = 0;
	pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
	pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].x >= 0
		&& WIDTH * pts[1].y + pts[1].x < WIDTH * HEIGHT
		&& scr[WIDTH * pts[1].y + pts[1].x + 1] != 0xFFFFFF
		&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] != 0xFFFFFF)
	{
		i++;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}
	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF
		|| (scr[WIDTH * pts[1].y + pts[1].x + 1] == 0xFFFFFF
			&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] == 0xFFFFFF))
	{
		i--;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}
}

static void	second_quadr(int *scr, t_point *pts, int ang)
{
	int		i;

	i = 0;
	pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
	pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].x >= 0
		&& WIDTH * pts[1].y + pts[1].x < WIDTH * HEIGHT
		&& scr[WIDTH * pts[1].y + pts[1].x + 1] != 0xFFFFFF
		&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH] != 0xFFFFFF)
	{
		i++;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}
	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF
		|| (scr[WIDTH * pts[1].y + pts[1].x + 1] == 0xFFFFFF
			&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH] == 0xFFFFFF))
	{
		i--;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}
}

static void	first_quadr(int *scr, t_point *pts, int ang)
{
	int		i;

	i = 0;
	pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
	pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].x >= 0
		&& WIDTH * pts[1].y + pts[1].x < WIDTH * HEIGHT
		&& scr[WIDTH * pts[1].y + pts[1].x - 1] != 0xFFFFFF
		&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH] != 0xFFFFFF)
	{
		i++;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}
	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF
		|| (scr[WIDTH * pts[1].y + pts[1].x - 1] == 0xFFFFFF
			&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH] == 0xFFFFFF))
	{
		i--;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}
}

void	other_angles(int *scr, t_point *pts, int ang)
{
	if (ang > 0 && ang < 90)
		first_quadr(scr, pts, ang);
	else if (ang > 90 && ang < 180)
		second_quadr(scr, pts, ang);
	else if (ang > 180 && ang < 270)
		third_quadr(scr, pts, ang);
	else if (ang > 270 && ang < 360)
		fourth_quadr(scr, pts, ang);
}
