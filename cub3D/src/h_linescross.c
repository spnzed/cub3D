/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_linescross.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:09:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/31 20:51:09 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void  h_shorter(float *vend, t_ray *ray, float ang, int h_mpos)
{
	free(vend);
	ray->map_p = h_mpos;
	if (ang < 180 && ang > 0)
		ray->wall_or = 'S';
	if (ang > 180 && ang < 360)
		ray->wall_or = 'N';
}

static float	*most_hangles(t_map *m, t_player *p, float ang, float *end)
{
	float	atan;
	float	*rd;

	rd = ft_all_floatarr();
	atan = - 1 / tan(deg_to_rad(ang));
	if (ang > 0 && ang < 180)
	{
		end[Y] = (((int)(p->y) / m->cell_w) * m->cell_w) - 0.0001;
		end[X] = (p->y - end[Y]) * -atan + p->x;
		rd[Y] = -(m->cell_w);
		rd[X] = rd[Y] * atan;
	}
	else if (ang > 180 && ang < 360)
	{
		end[Y] = (((int)(p->y) / m->cell_w) * m->cell_w) + m->cell_w;
		end[X] = (p->y - end[Y]) * -atan + p->x;
		rd[Y] = m->cell_w;
		rd[X] = rd[Y] * atan;
	}
	else
		rd = NULL;
	return (rd);
}

static int	horiz_ray(float ang, int i, float *end, t_map *m)
{
	if (ang == 0 || ang == 180 || end[X] < 0 || end[X] > m->cell_w * m->size[X])
		return (i);
	else
		return (-1);
}

static int	back_rd(float *end, float *rd, int i)
{
	end[X] -= rd[X];
	end[Y] -= rd[Y];
	return (i);
}

int	horiz_maplines(t_map *m, t_player *p, float ang, float *end)
{
	float	*rd;
	int		dof;
	int		mp;

	rd = most_hangles(m, p, ang, end);
	dof = horiz_ray(ang, m->size[Y], end, m);
	while (++dof < m->size[Y])
	{
		mp = (int)(end[Y]) / m->cell_w * m->size[X] + (int)(end[X]) / m->cell_w;
		if (end[Y] < 0 || end[X] < 0 || (mp < m->size[X] * m->size[Y] && (m->arr)[mp] == 1))
			break ; //dof = m->size[Y];
		else
			upd_end(end, rd);
		if (mp < m->size[X] * m->size[Y] && (m->arr)[mp] == 0 && (int)ang % 45 == 0 && (int)ang % 90 != 0
			&& (((int)ang == 45 && (m->arr)[mp - 1] == 1
			&& (m->arr)[mp + m->size[X]] == 1)
			|| ((int)ang == 135 && (m->arr)[mp + 1] == 1
			&& (m->arr)[mp + m->size[X]] == 1)
			|| ((int)ang == 225 && (m->arr)[mp + 1] == 1
			&& (m->arr)[mp - m->size[X]] == 1)
			|| ((int)ang == 315 && (m->arr)[mp - 1] == 1
			&& (m->arr)[mp - m->size[X]] == 1)))
			dof = back_rd(end, rd, m->size[Y]);
	}
	return (mp);
}
