/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_angles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:43:13 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/31 21:02:31 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	fourth_quadr(int *scr, t_point *pts, float ang)
// {
// 	int	i;

// 	i = 0;
// 	pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 	pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
// 		&& pts[1].y >= 0 && pts[1].x >= 0
// 		&& pts[1].x < WIDTH && pts[1].y < HEIGHT
// 		&& scr[WIDTH * pts[1].y + pts[1].x + 1] != 0xFFFFFF
// 		&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH]  != 0xFFFFFF)
// 	{
// 		i++;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// 	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF
// 		|| (scr[WIDTH * pts[1].y + pts[1].x - 1] == 0xFFFFFF
// 			&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] == 0xFFFFFF))
// 	{
// 		i -= 1;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// }

// static void	third_quadr(int *scr, t_point *pts, float ang)
// {
// 	int	i;

// 	i = 0;
// 	pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 	pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
// 		&& pts[1].y >= 0 && pts[1].x >= 0
// 		&& pts[1].x < WIDTH && pts[1].y < HEIGHT
// 		&& scr[WIDTH * pts[1].y + pts[1].x - 1] != 0xFFFFFF
// 		&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH] != 0xFFFFFF)
// 	{
// 		i++;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// 	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF
// 		|| (scr[WIDTH * pts[1].y + pts[1].x + 1] == 0xFFFFFF
// 			&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] == 0xFFFFFF))
// 	{
// 		i -= 1;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// }

// static void	second_quadr(int *scr, t_point *pts, float ang)
// {
// 	int	i;

// 	i = 0;
// 	pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 	pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
// 		&& pts[1].y >= 0 && pts[1].x >= 0
// 		&& pts[1].x < WIDTH && pts[1].y < HEIGHT
// 		&& scr[WIDTH * pts[1].y + pts[1].x - 1] != 0xFFFFFF
// 		&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] != 0xFFFFFF)
// 	{
// 		i++;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// 	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF
// 		|| (scr[WIDTH * pts[1].y + pts[1].x + 1] == 0xFFFFFF
// 			&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH] == 0xFFFFFF))
// 	{
// 		i -= 1;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// }

// static void	first_quadr(int *scr, t_point *pts, float ang)
// {
// 	int	i;

// 	i = 0;
// 	pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 	pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
// 		&& pts[1].y >= 0 && pts[1].x >= 0
// 		&& pts[1].x < WIDTH && pts[1].y < HEIGHT
// 		&& scr[WIDTH * pts[1].y + pts[1].x + 1] != 0xFFFFFF
// 		&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] != 0xFFFFFF)
// 	{
// 		i++;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// 	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF
// 		|| (scr[WIDTH * pts[1].y + pts[1].x - 1] == 0xFFFFFF
// 			&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH] == 0xFFFFFF))
// 	{
// 		i -= 1;
// 		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
// 		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
// 	}
// }

static void	horiz_maplines(t_map *m, t_player *p, float ang, t_ray *r)
{
	float	rd[2];
	float	atan;
	int		dof;
	int		mpos[2];
	int		mp;

	atan = -1 / tan(deg_to_rad(ang));
	//printf("atan: %f\n", atan);
	dof = -1;
	
	if (ang == 0 || ang == 180)
	{
		r->end[Y] = p->y;
		r->end[X] = p->x;
		dof = m->size[Y];
	}
	else if (ang < 180)
	{
		r->end[Y] = (((int)(p->y) / m->cell_w) * m->cell_w) - 0.0001;
		r->end[X] = (p->y - r->end[Y]) * atan + p->x;
		rd[Y] = -(m->cell_w);
		rd[X] = rd[Y] * atan;
		printf("rd[Y]: %f, rd[X]: %f\n", rd[Y], rd[X]);
	}
	else
	{
		r->end[Y] = (((int)(p->y) / m->cell_w) * m->cell_w) + m->cell_w;
		r->end[X] = (p->y - r->end[Y]) * atan + p->x;
		rd[Y] = m->cell_w;
		rd[X] = -rd[Y] * atan;
	}
	while (++dof < m->size[Y])
	{
		mpos[X] = (int)(r->end[X] - (WIDTH - m->size[X]) / 2) / m->cell_w;
		mpos[Y] = (int)(r->end[Y] - (HEIGHT - m->size[Y]) / 2) / m->cell_w;
		printf("mpos[X]: %i, mpos[Y]: %i\n", mpos[X], mpos[Y]);
		mp = mpos[Y] * m->size[Y] + mpos[X];
		if (mp < m->size[X] * m->size[Y] && (m->arr)[mp] == 1) //we hit a wall
			dof = m->size[Y]; //finish the loop
		else
		{
			r->end[X] += rd[X];
			r->end[Y] += rd[Y];
		}	
	}
}

void	ray_end_or(t_map *map, t_player *pl, float ang, t_ray *ray)
{
	horiz_maplines(map, pl, ang, ray);
	// else if (ang > 90 && ang < 180)
	// 	second_quadr(scr, pts, ang);
	// else if (ang > 180 && ang < 270)
	// 	third_quadr(scr, pts, ang);
	// else if (ang > 270 && ang < 360)
	// 	fourth_quadr(scr, pts, ang);
}
