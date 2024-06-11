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
	while (i < WIDTH - 1) // haura de ser WIDTH - 1
	{
		if ((int)r[i].ang % 45 == 0 && (int)r[i].ang % 90 != 0
			&& r[i].wall_or != r[i - 1].wall_or
			&& r[i].wall_or != r[i + 1].wall_or)
		{
			// printf("BEFORE r[i + 1].or: %c, r[%i].ang: %f, r[%i].wall_or: %c\n", r[i + 1].wall_or, i, r[i].ang, i, r[i].wall_or);
			// printf("r[%i].ang (i - 1): %f, r[%i].wall_or (i - 1): %c\n", i - 1, r[i - 1].ang, i - 1, r[i].wall_or);
			r[i].wall_or = r[i - 1].wall_or;
			//printf("AFTER r[%i].ang: %f, r[%i].wall_or: %c\n", i, r[i].ang, i, r[i].wall_or);
		}
		i++;
	}
}

static void	feed_ray(t_data *info, t_point *ends, int i)
{
	int	a;
	int	b;

	a = abs(ends[0].x - ends[1].x);
	b = abs(ends[0].y - ends[1].y);
	(info->ray)[i].len = sqrt((a * a + b * b));
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
	(info->ray)[i].ang = ang;
	
	ray_end_or(&(info->map), &(info->player), ang, &((info->ray)[i]));
	pts[1].x = (int)((info->ray)[i].end[X]);
	pts[1].y = (int)((info->ray)[i].end[Y]);
	draw_line(scr, pts, 0xFF0000, 1);
	feed_ray(info, pts, i);
}

static void	init_arr(t_data *info)
{
	info->ray = ft_calloc(sizeof(t_ray), WIDTH); //1 > WIDTH
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
	incr = (float)60 / (float)(WIDTH); //1 > WIDTH
	ang = info->player.dir + 30.0;
	init_arr(info);
	while (i < WIDTH) //1 > WIDTH
	{
		fill_ray(info->mlx->img.img_adr, info, angle_correction(ang), i);
		printf("i: %i, ang: %f\n", i, ang);
		i++;
		ang = ang - incr;
	}
	fix_or(info->ray);
// 	i = -1;
// 	while(++i < 100)
// 		printf("ray[%i].wall_or: %c, ray[%i].map_p: %i, ray->len: %f\n", i, (info->ray)[i].wall_or, i, (info->ray)[i].map_p, (info->ray)[i].len);
}
