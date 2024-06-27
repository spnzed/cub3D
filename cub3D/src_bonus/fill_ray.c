/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:09:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/06/07 20:44:52 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		ft_err("Error: Malloc\n");
	pts[0].x = (int)(info->player.x);
	pts[0].y = (int)(info->player.y);
	pts[1].x = 0;
	pts[1].y = 0;
	ray_end_or(&(info->map), &(info->player), ang, &((info->ray)[i]));
	pts[1].x = (int)((info->ray)[i].end[X]);
	pts[1].y = (int)((info->ray)[i].end[Y]);
	feed_ray(info, pts, i, ang);
	draw_wall(info, scr, ang, i);
}
