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
	if (ang > 180 && ang < 360)
	{
		end[Y] = (((int)(p->y) / m->cell_w) * m->cell_w) + m->cell_w;
		end[X] = (p->y - end[Y]) * -atan + p->x;
		rd[Y] = m->cell_w;
		rd[X] = rd[Y] * atan;
	}
	return (rd);
}

int	horiz_maplines(t_map *m, t_player *p, float ang, float *end)
{
	float	*rd;
	int		dof;
	int		mpos[2];
	int		mp;

	rd = NULL;
	dof = 0;
	if ((ang > 0 && ang < 180) || (ang > 180 && ang < 360))
		rd = most_hangles(m, p, ang, end);
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
			upd_end(end, rd);
		if ((m->arr)[mp] == 0 && (int)ang % 45 == 0 && (int)ang % 90 != 0)  // map, ang, end, rd, mp > massa variables
		{
			if (((int)ang == 45 && (m->arr)[mp - 1] == 1 && (m->arr)[mp + m->size[X]] == 1)
				|| ((int)ang == 135 && (m->arr)[mp + 1] == 1 && (m->arr)[mp + m->size[X]] == 1)
				|| ((int)ang == 225 && (m->arr)[mp + 1] == 1 && (m->arr)[mp - m->size[X]] == 1)
				|| ((int)ang == 315 && (m->arr)[mp - 1] == 1 && (m->arr)[mp - m->size[X]] == 1))
			{
				end[X] -= rd[X];
				end[Y] -= rd[Y];
				dof = m->size[Y];
			}
		}
		++dof;
	}
	return (mp);
}
