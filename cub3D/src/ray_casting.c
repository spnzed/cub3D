/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:21:29 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/31 20:48:17 by erosas-c         ###   ########.fr       */
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

static void	fill_ray(int *scr, t_data *info, float ang, int i)
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

static void	init_arr(t_data *info)
{
	info->ray = ft_calloc(sizeof(t_ray), 480); //1 > WIDTH
	if (!info->ray)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
}

void	cast_rays(t_data *info)
{
	float	ang;
	int		i;
	float	incr;

	i = 0;
	incr = 0.125; //(float)60 / (float)(1); //1 > WIDTH
	ang = info->player.dir + 30.0;
	init_arr(info);
	while (i < 480) //1 > WIDTH
	{
		//fill_ray(info->map2d, info, angle_correction(ang), i);
		//printf("i: %i, ang: %f\n", i, ang);
		fill_ray(info->mlx->img.img_adr, info, angle_correction(ang), i);
		i++;
		ang = ang - incr;
	}
	/*i = -1;
	while(++i < WIDTH)
		printf("ray[%i].wall_or: %c\n", i, (info->ray)[i].wall_or);*/
}
