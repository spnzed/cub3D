/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:09:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/31 20:51:09 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void fix_or(t_ray *r)
{
	int	i;

	i = 1;
	while (i < 479) // haura de ser WIDTH - 1
	{
		if ((int)r[i].ang % 45 == 0 && (int)r[i].ang % 90 != 0
			&& r[i].wall_or != r[i - 1].wall_or
			&& r[i].wall_or != r[i + 1].wall_or)
			r[i].wall_or = r[i - 1].wall_or;
		i++;
	}
}

static void	feed_ray(t_data *info, t_point *ends, int i, float ang)
{
	int	a;
	int	b;

	a = abs(ends[0].x - ends[1].x);
	b = abs(ends[0].y - ends[1].y);
	(info->ray)[i].len = sqrt((a * a + b * b));
	(info->ray)[i].ang = ang;
}

void	fill_ray(int *scr, t_data *info, float ang, int i)
{
	t_point	*pts;

	pts = ft_calloc(sizeof(t_point), 2);
	if (!pts)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	pts[0].x = (int)(info->player.x);
	pts[0].y = (int)(info->player.y);
	pts[1].x = 0;
	pts[1].y = 0;
	//ray_end(scr, pts, ang);
	//printf("fill_ray player X: %f, player Y: %f\n", info->player.x, info->player.y);
	ray_end_or(&(info->map), &(info->player), ang, &((info->ray)[i]));
	pts[1].x = (int)((info->ray)[i].end[X]);
	pts[1].y = (int)((info->ray)[i].end[Y]);
//	printf("ang: %f, pts[0].x: %i, pts[0].y: %i, pts[1].x: %i, pts[1].y: %i\n", ang, pts[0].x, pts[0].y, pts[1].x, pts[1].y);
	draw_line(scr, pts, 0xFF0000, 1);
	feed_ray(info, pts, i, ang);
	fix_or(info->ray);
	draw_wall(info, scr, ang, i);
}
