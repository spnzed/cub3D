/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:10:24 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/04 18:27:41 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	add_line_item(int *buff, int x, int y, int color)
{
	if (y - x >= INT_MIN / WIDTH && y - x <= INT_MAX / WIDTH)
	{
		if (((y * WIDTH) + x) < (HEIGHT * WIDTH) && (y * WIDTH + x) >= 0)
		{
			buff[(y * WIDTH) + x] = color;
		}
	}
}

void	fill_lo(int *buffer, t_point pt0, t_point pt1, int color)
{
	int	dy;
	int	dist;
	int	x;
	int	y;
	int	yi;

	dy = abs(pt1.y - pt0.y);
	yi = 1;
	x = pt0.x;
	y = pt0.y;
	if ((pt1.y - pt0.y) < 0)
		yi = -1;
	dist = (2 * dy) - (pt1.x - pt0.x);
	while (x <= pt1.x)
	{
		add_line_item(buffer, x, y, color);
		if (dist > 0)
		{
			y = y + yi;
			dist = dist + (2 * (dy - (pt1.x - pt0.x)));
		}
		else
			dist = dist + 2 * dy;
		x++;
	}
}

void	fill_hi(int *scr, t_point pt0, t_point pt1, int color)
{
	int	dx;
	int	dist;
	int	x;
	int	y;
	int	xi;

	dx = abs(pt1.x - pt0.x);
	xi = 1;
	x = pt0.x;
	y = pt0.y;
	if ((pt1.x - pt0.x) < 0)
		xi = -1;
	dist = (2 * dx) - (pt1.y - pt0.y);
	while (y <= pt1.y)
	{
		add_line_item(scr, x, y, color);
		if (dist > 0)
		{
			x = x + xi;
			dist = dist + (2 * (dx - (pt1.y - pt0.y)));
		}
		else
			dist = dist + 2 * dx;
		y++;
	}
}

void	draw_line(int *scr, t_point *pts, int color)
{
	if (abs(pts[1].y - pts[0].y) <= abs(pts[1].x - pts[0].x))
	{
		if (pts[0].x > pts[1].x)
			fill_lo(scr, pts[1], pts[0], color);
		else
			fill_lo(scr, pts[0], pts[1], color);
	}
	else
	{
		if (pts[0].y > pts[1].y)
			fill_hi(scr, pts[1], pts[0], color);
		else
			fill_hi(scr, pts[0], pts[1], color);
	}
}