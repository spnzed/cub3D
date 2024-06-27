/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:31:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/17 21:18:36 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	wall_found(float x, float y, t_map *m)
{
	int	mp;
	int	mx;
	int	my;

	mx = (int)(x) / SCALE;
	my = (int)(y) / SCALE;
	mp = my * m->size[X] + mx;
	if ((m->arr)[mp] == 1)
		return (1);
	return (0);
}

void	move_front(t_player *p, t_player *minipl, t_map *m)
{
	if (!wall_found(p->x + p->dx, p->y + p->dy, m)
		&& !wall_found(p->x + p->dx * 2, p->y + p->dy * 2, m)
		&& !wall_found(p->x + p->dx * 3, p->y + p->dy * 3, m)
		&& !wall_found(p->x + p->dx * 4, p->y + p->dy * 4, m)
		&& !move_concave(p->dx, p->dy, p, m))
	{
		p->x += p->dx * SPEED;
		p->y += p->dy * SPEED;
		minipl->x += p->dx / 4 * SPEED;
		minipl->y += p->dy / 4 * SPEED;
	}
}

void	move_back(t_player *p, t_player *minipl, t_map *m)
{
	if (!wall_found(p->x - p->dx, p->y - p->dy, m)
		&& !wall_found(p->x - p->dx * 2, p->y - p->dy * 2, m)
		&& !wall_found(p->x - p->dx * 3, p->y - p->dy * 3, m)
		&& !wall_found(p->x - p->dx * 4, p->y - p->dy * 4, m)
		&& !move_concave((p->dx * -1), (p->dy * -1), p, m))
	{
		p->x -= p->dx * SPEED;
		p->y -= p->dy * SPEED;
		minipl->x -= p->dx / 4 * SPEED;
		minipl->y -= p->dy / 4 * SPEED;
	}
}

void	move_right(t_player *p, t_player *minipl, t_map *m)
{
	float	new_dir;
	float	new_dx;
	float	new_dy;

	new_dir = angle_correction(90 - p->dir);
	new_dx = cos(deg_to_rad(new_dir));
	new_dy = sin(deg_to_rad(new_dir));
	if (!wall_found(p->x + new_dx, p->y + new_dy, m)
		&& !wall_found(p->x + new_dx * 2, p->y + new_dy * 2, m)
		&& !wall_found(p->x + new_dx * 3, p->y + new_dy * 3, m)
		&& !wall_found(p->x + new_dx * 4, p->y + new_dy * 4, m)
		&& !move_concave(new_dx, new_dy, p, m))
	{
		p->x += new_dx * SPEED;
		p->y += new_dy * SPEED;
		minipl->x += new_dx / 4 * SPEED;
		minipl->y += new_dy / 4 * SPEED;
	}
}

void	move_left(t_player *p, t_player *minipl, t_map *m)
{
	float	new_dir;
	float	new_dx;
	float	new_dy;

	new_dir = angle_correction(90 - p->dir);
	new_dx = cos(deg_to_rad(new_dir));
	new_dy = sin(deg_to_rad(new_dir));
	if (!wall_found(p->x - new_dx, p->y - new_dy, m)
		&& !wall_found(p->x - new_dx * 2, p->y - new_dy * 2, m)
		&& !wall_found(p->x - new_dx * 3, p->y - new_dy * 3, m)
		&& !wall_found(p->x - new_dx * 4, p->y - new_dy * 4, m)
		&& !move_concave((new_dx * -1), (new_dy * -1), p, m))
	{
		p->x -= new_dx * SPEED;
		p->y -= new_dy * SPEED;
		minipl->x -= new_dx / 4 * SPEED;
		minipl->y -= new_dy / 4 * SPEED;
	}
}
