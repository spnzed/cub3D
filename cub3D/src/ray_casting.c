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

static void feedtext_p(t_ray *r)
{
	int	i;

	i = 1;
	while (i < WIDTH - 1)
	{
		if (r[i].wall_or == 'N' || r[i].wall_or == 'S')
			r[i].text_p = ((int)(r[i].end)[X] % SCALE); //RESIZING
		else if (r[i].wall_or == 'E' || r[i].wall_or == 'W')
			r[i].text_p = ((int)(r[i].end)[Y] % SCALE); //RESIZING
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
		// if (r[i].wall_or == r[i - 1].wall_or && r[i].map_p == r[i - 1].map_p
		// 	&& fabs(r[i].len - r[i - 1].len) > 5.0)
		// 	r[i].len = r[i - 1].len;
		i++;
	}
}

// static void	feed_ray(t_data *info, t_point *ends, int i)
// {
// 	int	a;
// 	int	b;

// 	a = abs(ends[0].x - ends[1].x);
// 	b = abs(ends[0].y - ends[1].y);
// 	(info->ray)[i].len = sqrt((a * a + b * b));
// }

static void	fill_ray(int *scr, t_data *info, float ang, int i)
{
	t_point	*pts;

	(void)scr; // esborrar aixo abans d'entregar
	pts = ft_calloc(sizeof(t_point), 2);
	if (!pts)
		ft_err("Error: Malloc\n");
	pts[0].x = (int)(info->player.x);
	pts[0].y = (int)(info->player.y);
	pts[1].x = 0;
	pts[1].y = 0;
	(info->ray)[i].ang = ang;
	ray_end_or(&(info->map), &(info->player), ang, &((info->ray)[i]));
	// if (i == WIDTH / 2)
	// 	printf("ang: %f, ray len fill_ray: %f\n", ang, (info->ray[i]).len);
	pts[1].x = (int)((info->ray)[i].end[X]);
	pts[1].y = (int)((info->ray)[i].end[Y]);

//	feed_ray(info, pts, i);
//	draw_line(info->mlx->img.img_adr, pts, 0x00FFFF, 1);
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
		fill_ray(info->mlx->img.img_adr, info, angle_correction(ang), i);
		i++;
		ang = ang - incr;
	}
	i = -1;
	while (++i < WIDTH)
		fix_or(info->ray);
	feedtext_p(info->ray);
}
