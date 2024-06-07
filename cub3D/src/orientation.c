/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:43:13 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/31 21:02:31 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void v_shorter(float *hend, float *vend, t_ray *ray, float ang)
{
	free(hend);
	ray->end[X] = vend[X];
	ray->end[Y] = vend[Y];
	if (ang > 90 && ang < 270)
		ray->wall_or = 'E';
	if (ang < 90 || ang > 270)
		ray->wall_or = 'W';
}

static void	vertic_maplines(t_map *m, t_player *p, float ang, float *end)
{
	float	rd[2];
	float	ntan;
	int		dof;
	int		mpos[2];
	int		mp;

	ntan = tan(deg_to_rad(ang));
	dof = 0;
	if (ang > 90 && ang < 270) // looking left
	{
		end[X] = (((int)(p->x) / m->cell_w) * m->cell_w) - 0.0001;
		end[Y] = (p->x - end[X]) * ntan + p->y;
		rd[X] = -(m->cell_w);
		rd[Y] = rd[X] * -ntan;
	}
	if (ang < 90 || ang > 270) //looking right
	{
		end[X] = (((int)(p->x) / m->cell_w) * m->cell_w) + m->cell_w;
		end[Y] = (p->x - end[X]) * ntan + p->y;
		rd[X] = m->cell_w;
		rd[Y] = rd[X] * -ntan;
	}
	if (ang == 90 || ang == 270)
		dof = m->size[X];
	while (dof < m->size[X])
	{
		mpos[X] = (int)(end[X]) / m->cell_w;
		mpos[Y] = (int)(end[Y]) / m->cell_w;
		mp = mpos[Y] * m->size[X] + mpos[X];
		if (mp < m->size[X] * m->size[Y] && (m->arr)[mp] == 1) //we hit a wall
			dof = m->size[X]; //finish the loop
		else
		{
			end[X] += rd[X];
			end[Y] += rd[Y];
		}
		++dof;
	}
}

static void	horiz_maplines(t_map *m, t_player *p, float ang, float *end)
{
	float	rd[2];
	float	atan;
	int		dof;
	int		mpos[2];
	int		mp;

	atan = 0;
	dof = 0;
	if (ang < 180 && ang > 0)
	{
		atan = - 1 / tan(deg_to_rad(ang));
		end[Y] = (((int)(p->y) / m->cell_w) * m->cell_w) - 0.0001;
		end[X] = (p->y - end[Y]) * -atan + p->x;
		rd[Y] = -(m->cell_w);
		rd[X] = rd[Y] * atan;
	}
	if (ang > 180 && ang < 360)
	{
		atan = - 1 / tan(deg_to_rad(ang));
		end[Y] = (((int)(p->y) / m->cell_w) * m->cell_w) + m->cell_w;
		end[X] = (p->y - end[Y]) * -atan + p->x;
		rd[Y] = m->cell_w;
		rd[X] = rd[Y] * atan;
	}
	if (ang == 0 || ang == 180)
		dof = m->size[Y];
	while (dof < m->size[Y])
	{
		mpos[X] = (int)(end[X]) / m->cell_w;
		mpos[Y] = (int)(end[Y]) / m->cell_w;
		mp = mpos[Y] * m->size[X] + mpos[X];
		if (mp < m->size[X] * m->size[Y] && (m->arr)[mp] == 1) //we hit a wall
			dof = m->size[Y]; //finish the loop
		else
		{
			end[X] += rd[X];
			end[Y] += rd[Y];
		}
		++dof;
	}
}

void	ray_end_or(t_map *map, t_player *pl, float ang, t_ray *ray)
{
	float	*hend;
	float	*vend;
	float	h_len;
	float	v_len;

	hend = alloc_floatarr(pl);
	vend = alloc_floatarr(pl);
	horiz_maplines(map, pl, ang, hend);
	ray->end[X] = hend[X];
	ray->end[Y] = hend[Y];
	h_len = sqrt((hend[X] - pl->x) * (hend[X] - pl->x)
		+ (hend[Y] - pl->y) * (hend[Y] - pl->y));
	vertic_maplines(map, pl, ang, vend);
	v_len = sqrt((vend[X] - pl->x) * (vend[X] - pl->x)
		+ (vend[Y] - pl->y) * (vend[Y] - pl->y));
	if ((v_len < h_len && ang != 90 && ang != 270) || ang == 0 || ang == 180)
		v_shorter(hend, vend, ray, ang);
	else
	{
		free(vend);
		if (ang < 180 && ang > 0)
			ray->wall_or = 'S';
		if (ang > 180 && ang < 360)
			ray->wall_or = 'N';
	}
}
