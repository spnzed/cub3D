/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_linescross.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:09:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/31 20:51:09 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	h_shorter(float *vend, float *hend, t_ray *ray, int h_mpos)
{
	free(vend);
	ray->map_p = h_mpos;
	if (ray->ang < 180 && ray->ang > 0)
		ray->wall_or = 'S';
	if (ray->ang > 180 && ray->ang < 360)
		ray->wall_or = 'N';
	free(hend);
}

static float	*most_hangles(t_map *m, t_player *p, float ang, float *end)
{
	float	atan;
	float	*rd;

	rd = ft_all_floatarr();
	atan = -1 / tan(deg_to_rad(ang));
	if (ang > 0 && ang < 180)
	{
		end[Y] = (((int)(p->y) / m->cell_w) * m->cell_w) - 0.0001 * m->size[X] / 11;
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
	{
		free(rd);
		rd = NULL;
	}
	return (rd);
}

static int	back_rd(float *end, float *rd, int i)
{
	end[X] -= rd[X];
	end[Y] -= rd[Y];
	return (i);
}

int	concave_corner(t_map *m, float a, int mp)
{
	if (((int)a == 45 && (m->arr)[mp - 1] == 1
		&& (m->arr)[mp + m->size[X]] == 1)
		|| ((int)a == 135 && (m->arr)[mp + 1] == 1
		&& (m->arr)[mp + m->size[X]] == 1)
		|| ((int)a == 225 && (m->arr)[mp + 1] == 1
		&& (m->arr)[mp - m->size[X]] == 1)
		|| ((int)a == 315 && (m->arr)[mp - 1] == 1
		&& (m->arr)[mp - m->size[X]] == 1))
		return (1);
	return (0);
}

int	horiz_maplines(t_map *m, t_player *p, float a, float *end)
{
	float	*rd;
	int		dof;
	int		mp;

	rd = most_hangles(m, p, a, end);
	dof = -1;
	if (a == 0 || a == 180 || end[X] < 0 || end[X] > m->cell_w * m->size[X])
		dof = m->size[Y];
	while (++dof < m->size[Y])
	{
		mp = (int)(end[Y]) / m->cell_w * m->size[X]
			+ (int)(end[X]) / m->cell_w;
		if (end[Y] < 0 || end[X] < 0
			|| (mp < m->size[X] * m->size[Y] && (m->arr)[mp] == 1))
			break ;
		else
			upd_end(end, rd);
		if (mp < m->size[X] * m->size[Y] && (m->arr)[mp] == 0
			&& (int)a % 45 == 0 && (int)a % 90 != 0
			&& (concave_corner(m, a, mp) == 1))
			dof = back_rd(end, rd, m->size[Y]);
	}
	free(rd);
	return (mp);
}
