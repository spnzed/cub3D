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

t_point	*other_angles(int *scr, t_point *pts, t_player *pl, t_point *wall)
{
	int		i;

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
		wall->x = pts[1].x;
		wall->y = pts[1].y;
		i--;
		pts[1].x = pts[0].x + cos(deg_to_rad(pl->dir)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(pl->dir)) * i;
	}
	return (wall);
}

void	fill_ray(int *scr, t_player *pl/*, t_data *info*/)
{
	t_point	*pts;
	t_point	*wall;

	pts = ft_calloc(sizeof(pts), 2);
	if (!pts)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	wall = ft_calloc(sizeof(pts), 1);
	if (!wall)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	pts[0].x = pl->x;
	pts[0].y = pl->y;
	pts[1].x = 0;
	pts[1].y = 0;
	wall = ray_end(scr, pts, pl, wall);
	draw_line(scr, pts, 0xFFFF00);
	//draw_rays(info);
}
