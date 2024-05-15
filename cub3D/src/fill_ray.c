/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:09:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/14 17:37:03 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	horiz_ray(int *scr, t_point *pts, t_player *pl)
{
	if (pl->dir == 0)
	{
		pts[1].x = pts[0].x + 1;
		pts[1].y = pts[0].y;
		while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
			&& WIDTH * pts[1].y + pts[1].y >= 0
			&& WIDTH * pts[1].y + pts[1].y < WIDTH * HEIGHT)
				pts[1].x++;
		if (scr[WIDTH * pts[1].y + pts[1].y] != 0xFFFFFF)
			pts[1].x--;
	}
	else if (pl->dir == 180)
	{
		pts[1].x = pts[0].x - 1;
		pts[1].y = pts[0].y;
		while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
			&& WIDTH * pts[1].y + pts[1].y >= 0
			&& WIDTH * pts[1].y + pts[1].y < WIDTH * HEIGHT)
				pts[1].x--;
		if (scr[WIDTH * pts[1].y + pts[1].y] != 0xFFFFFF)
			pts[1].x++;
	}

}

static void	vert_ray(int *scr, t_point *pts, t_player *pl)
{
	if (pl->dir == 90)
	{
		pts[1].x = pts[0].x;
		pts[1].y = pts[0].y - 1;
		while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
			&& WIDTH * pts[1].y + pts[1].y >= 0
			&& WIDTH * pts[1].y + pts[1].y < WIDTH * HEIGHT)
				pts[1].y--;
		if (scr[WIDTH * pts[1].y + pts[1].y] != 0xFFFFFF)
			pts[1].y++;
	}
	else if (pl->dir == 270)
	{
		pts[1].x = pts[0].x;
		pts[1].y = pts[0].y + 1;
		while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
			&& WIDTH * pts[1].y + pts[1].y >= 0
			&& WIDTH * pts[1].y + pts[1].y < WIDTH * HEIGHT)
				pts[1].y++;
		if (scr[WIDTH * pts[1].y + pts[1].y] != 0xFFFFFF)
			pts[1].y--;
	}

}
static void	other_angles(int *scr, t_point *pts, t_player *pl)
{
	int	i;

	i = 0;
	pts[1].x = pts[0].x + cos(deg_to_rad(pl->dir)) * i;
	pts[1].y = pts[0].y - sin(deg_to_rad(pl->dir)) * i;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].y >= 0
		&& WIDTH * pts[1].y + pts[1].y < WIDTH * HEIGHT)
	{
		i++;
		pts[1].x = pts[0].x + cos(deg_to_rad(pl->dir)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(pl->dir)) * i;
	}
	if (scr[WIDTH * pts[1].y + pts[1].y] != 0xFFFFFF)
	{
		i--;
		pts[1].x = pts[0].x + cos(deg_to_rad(pl->dir)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(pl->dir)) * i;
	}
}

static void	ray_end(int *scr, t_point *pts, t_player *pl)
{
	if (pl->dir == 90 || pl->dir == 270)
		vert_ray(scr, pts, pl);
	else if (pl->dir == 0 || pl->dir == 180)
		horiz_ray(scr, pts, pl);
	else
		other_angles(scr, pts, pl);
}

void	fill_ray(int *scr, t_player *pl)
{
	t_point	*pts;

	pts = ft_calloc(sizeof(pts), 2);
	if (!pts)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	pts[0].x = pl->x;
	pts[0].y = pl->y;
	pts[1].x = 0;
	pts[1].y = 0;
	ray_end(scr, pts, pl);
	draw_line(scr, pts, 0xFFFF00);
	
}
