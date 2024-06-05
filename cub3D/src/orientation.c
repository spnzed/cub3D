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

static void	horiz_maplines(t_map *m, t_player *p, float ang, float *end)
{
	float	rd[2];
	float	atan;
	int		dof;
	int		mpos[2];
	int		mp;

	atan = 0;
	//printf("ang: %f\n", ang);
	dof = 0;
	if (ang < 180 && ang > 0)
	{
		atan = - 1 / tan(deg_to_rad(angle_correction(ang)));
		end[Y] = (((int)(p->y) / m->cell_w) * m->cell_w) - 0.0001;
		//printf("tan(ang): %f, atan: %f\n", tan(ang), atan);
		end[X] = (p->y - end[Y]) * -atan + p->x;
		//printf("p->x: %f, p->y: %f, end[X]: %f. end[Y]: %f\n", p->x, p->y, end[X], end[Y]);
		rd[Y] = -(m->cell_w);
		rd[X] = rd[Y] * atan;
		//printf("rd[Y]: %f, rd[X]: %f\n", rd[Y], rd[X]);
	}
	if (ang > 180 && ang < 360)
	{
		atan = - 1 / tan(deg_to_rad(angle_correction(ang)));
		//printf("tan(ang): %f, atan: %f\n", tan(ang), atan);
		end[Y] = (((int)(p->y) / m->cell_w) * m->cell_w) + m->cell_w;
		end[X] = (p->y - end[Y]) * -atan + p->x;
		//printf("p->x: %f, p->y: %f, end[X]: %f. end[Y]: %f\n", p->x, p->y, end[X], end[Y]);
		rd[Y] = m->cell_w;
		rd[X] = rd[Y] * atan;
		//printf("rd[Y]: %f, rd[X]: %f\n", rd[Y], rd[X]);
	}
	if (ang == 0 || ang == 180)
	{
		end[Y] = p->y;
		end[X] = p->x;
		dof = m->size[Y];
	}
	while (dof < m->size[Y])
	{
	//	printf("111 r->end[X]: %f, r->end[Y]: %f\n", r->end[X], r->end[Y]);
		mpos[X] = (int)(end[X]) / m->cell_w;
		mpos[Y] = (int)(end[Y]) / m->cell_w;
		//mpos[Y] = ((int)r->end[Y] - (HEIGHT - m->size[Y] * m->cell_w)) / m->cell_w;
		mp = mpos[Y] * m->size[X] + mpos[X];
	//	printf("mpos[X]: %i, mpos[Y]: %i, mp: %i, m->arr[mp]: %i\n", mpos[X], mpos[Y], mp, (m->arr)[mp]);
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

	hend = ft_calloc(sizeof(float), 2);
	if (!hend)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	vend = ft_calloc(sizeof(float), 2);
	if (!vend)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	hend[X] = pl->x;
	hend[Y] = pl->y;
	vend[X] = pl->x;
	vend[Y] = pl->y;
	horiz_maplines(map, pl, ang, hend);
	ray->end[X] = hend[X];
	ray->end[Y] = hend[Y];
	// else if (ang > 90 && ang < 180)
	// 	second_quadr(scr, pts, ang);
	// else if (ang > 180 && ang < 270)
	// 	third_quadr(scr, pts, ang);
	// else if (ang > 270 && ang < 360)
	// 	fourth_quadr(scr, pts, ang);
}
