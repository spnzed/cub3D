/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:21:29 by erosas-c          #+#    #+#             */
/*   Updated: 2024/06/13 10:26:27 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	feedtext_p(t_ray *r)
{
	int	i;

	i = 1;
	while (i < WIDTH - 1)
	{
		if (r[i].wall_or == 'N' || r[i].wall_or == 'S')
			r[i].text_p = ((int)(r[i].end)[X] % SCALE);
		else if (r[i].wall_or == 'E' || r[i].wall_or == 'W')
			r[i].text_p = ((int)(r[i].end)[Y] % SCALE);
		i++;
	}
}

static void	fix_or(t_ray *r)
{
	int	i;

	i = 1;
	while (i < WIDTH - 1)
	{
		if ((int)r[i].ang % 45 == 0 && (int)r[i].ang % 90 != 0
			&& r[i].wall_or != r[i - 1].wall_or
			&& r[i].wall_or != r[i + 1].wall_or)
			r[i].wall_or = r[i - 1].wall_or;
		if (r[i].len < 1.0)
			r[i].len = 1.0;
		i++;
	}
}

static void	fill_ray(t_data *info, float ang, int i)
{
	t_point	*pts;

	pts = ft_calloc(sizeof(t_point), 2);
	if (!pts)
		ft_err("Error: Malloc\n");
	pts[0].x = (int)(info->player.x);
	pts[0].y = (int)(info->player.y);
	pts[1].x = 0;
	pts[1].y = 0;
	(info->ray)[i].ang = ang;
	ray_end_or(&(info->map), &(info->player), ang, &((info->ray)[i]));
	pts[1].x = (int)((info->ray)[i].end[X]);
	pts[1].y = (int)((info->ray)[i].end[Y]);
	free(pts);
}

static void	init_rays_arr(t_data *info)
{
	info->ray = ft_calloc(sizeof(t_ray), WIDTH);
	if (!info->ray)
		ft_err("Error: Malloc\n");
}

void	cast_rays(t_data *info)
{
	float	ang;
	int		i;
	float	incr;

	i = 0;
	incr = (float)60 / (float)(WIDTH);
	ang = info->player.dir + 30.0;
	init_rays_arr(info);
	while (i < WIDTH)
	{
		fill_ray(info, angle_correction(ang), i);
		i++;
		ang = ang - incr;
	}
	i = -1;
	while (++i < WIDTH)
		fix_or(info->ray);
	feedtext_p(info->ray);
}