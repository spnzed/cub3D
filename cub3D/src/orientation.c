/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:43:13 by erosas-c          #+#    #+#             */
/*   Updated: 2024/06/11 22:39:13 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	v_shorter(float *hend, float *vend, t_ray *ray, float ang)
{
	free(hend);
	ray->end[X] = vend[X];
	ray->end[Y] = vend[Y];
	if (ang > 90 && ang < 270)
		ray->wall_or = 'E';
	if (ang < 90 || ang > 270)
		ray->wall_or = 'W';
	free(vend);
}

static float	*most_vangles(t_map *m, t_player *p, float ang, float *end)
{
	float	ntan;
	float	*rd;

	rd = ft_all_floatarr();
	ntan = tan(deg_to_rad(ang));
	if (ang > 90 && ang < 270)
	{
		end[X] = (((int)(p->x) / m->cell_w) * m->cell_w) - 0.0001 * m->size[X] / 11;
		end[Y] = (p->x - end[X]) * ntan + p->y;
		rd[X] = -(m->cell_w);
		rd[Y] = rd[X] * -ntan;
	}
	if (ang < 90 || ang > 270)
	{
		end[X] = (((int)(p->x) / m->cell_w) * m->cell_w) + m->cell_w;// + 0.0001 * m->size[Y] / 1;
		end[Y] = (p->x - end[X]) * ntan + p->y;
		rd[X] = m->cell_w;
		rd[Y] = rd[X] * -ntan;
	}
	return (rd);
}

void	upd_end(float *end, float *rd)
{
	end[X] += rd[X];
	end[Y] += rd[Y];
}

static int	vertic_maplines(t_map *m, t_player *p, float ang, float *end)
{
	float	*rd;
	int		dof;
	int		mpos[2];
	int		mp;

	rd = NULL;
	dof = 0;
	if ((ang > 90 && ang < 270) || (ang < 90 || ang > 270))
		rd = most_vangles(m, p, ang, end);
	if (ang == 90 || ang == 270 || end[Y] < 0)
		dof = m->size[X];
	while (dof < m->size[X])
	{
		mpos[X] = (int)(end[X]) / m->cell_w;
		mpos[Y] = (int)(end[Y]) / m->cell_w;
		mp = mpos[Y] * m->size[X] + mpos[X];
		if (end[Y] < 0 || end[X] < 0 || (mp < m->size[X] * m->size[Y]
				&& (m->arr)[mp] == 1))
			break ;
		else
			upd_end(end, rd);
		++dof;
	}
	free(rd);
	return (mp);
}

void	ray_end_or(t_map *map, t_player *pl, float ang, t_ray *ray)
{
	float	*hend;
	float	*vend;
	float	v_len;
	int		h_mpos;

	hend = alloc_floatarr(pl);
	vend = alloc_floatarr(pl);
	h_mpos = horiz_maplines(map, pl, ang, hend);
	ray->end[X] = hend[X];
	ray->end[Y] = hend[Y];
	ray->len = sqrt((hend[X] - pl->x) * (hend[X] - pl->x)
			+ (hend[Y] - pl->y) * (hend[Y] - pl->y)); //RESIZING * 2
	vend[X] = pl->x;
	vend[Y] = pl->y;
	ray->map_p = vertic_maplines(map, pl, ang, vend);
	v_len = sqrt((vend[X] - pl->x) * (vend[X] - pl->x)
			+ (vend[Y] - pl->y) * (vend[Y] - pl->y)); //RESIZING * 2
	if ((v_len < ray->len && ang != 90 && ang != 270) || ang == 0 || ang == 180)
	{
		v_shorter(hend, vend, ray, ang);
		ray->len = v_len;
	}
	else
		h_shorter(vend, hend, ray, h_mpos);
}
