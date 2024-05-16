/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:09:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/15 15:38:43 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	other_angles(t_point *pts, t_player *pl)
{
	if (pl->angle == 0)
	{
		pts[1].x = pts[0].x + pl->len;
		pts[1].y = pts[0].y;
	}
	else if (pl->angle == 180)
	{
		pts[1].x = pts[0].x - pl->len;
		pts[1].y = pts[0].y;
	}
	else
	{
		pts[1].x = pts[0].x + cos(deg_to_rad(pl->angle)) * pl->len;
		pts[1].y = pts[0].y - sin(deg_to_rad(pl->angle)) * pl->len;
	}
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
	pts[0].x = pl->x + pl->w / 2;
	pts[0].y = pl->y + pl->h / 2;
	pts[1].x = 0;
	pts[1].y = 0;
	if (pl->angle == 90)
	{
		pts[1].x = pts[0].x;
		pts[1].y = pts[0].y - pl->len;
	}
	else if (pl->angle == 270)
	{
		pts[1].x = pts[0].x;
		pts[1].y = pts[0].y + pl->len;
	}
	else
		other_angles(pts, pl);
	draw_line(scr, pts, 0xFFFF00);
}
