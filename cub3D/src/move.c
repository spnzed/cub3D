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

// static int	move_concave(t_player *p, t_map *m)
// {
// 	int curr_mp;
// 	int next_mp;

// 	curr_mp = ((int)(p->y) / m->cell_w) * m->size[X] + (int)(p->x) / m->cell_w;
// 	next_mp = ((int)(p->y + p->dy) / m->cell_w) * m->size[X] + (int)(p->x + p->dx) / m->cell_w;
// 	if (m->arr[curr_mp] == 0 && m->arr[next_mp] == 0)
// 	{
// 		if (m->arr[curr_mp + 1] == 1 && m->arr[curr_mp - m->size[X] == 1]
// 			&& m->arr[next_mp - 1] == 1 && m->arr[next_mp + m->size[X] == 1])
// 			return (1);
// 		else if (m->arr[curr_mp - 1] == 1 && m->arr[curr_mp + m->size[X] == 1]
// 			&& m->arr[next_mp + 1] == 1 && m->arr[next_mp - m->size[X] == 1])
// 			return (1);
// 		else if (m->arr[curr_mp + 1] == 1 && m->arr[curr_mp + m->size[X] == 1]
// 			&& m->arr[next_mp - 1] == 1 && m->arr[next_mp - m->size[X] == 1])
// 			return (1);
// 		else if (m->arr[curr_mp - 1] == 1 && m->arr[curr_mp - m->size[X] == 1]
// 			&& m->arr[next_mp + 1] == 1 && m->arr[next_mp + m->size[X] == 1])
// 			return (1);
// 	}
// 	return (0);
// }

static int	move_concave(float dx, float dy, t_player *p, t_map *m)
{
	m->p[X] = (int)(p->x + dx) / SCALE;
	m->p[Y] = (int)(p->y) / SCALE;
	if (m->arr[m->p[Y] * m->size[X] + m->p[X]] == 1)
		return (1);
	m->p[X] = (int)(p->x) / SCALE;
	m->p[Y] = (int)(p->y + dy) / SCALE;
	if (m->arr[m->p[Y] * m->size[X] + m->p[X]] == 1)
		return (1);
	return (0);
}

static int	wall_found(float x, float y, t_map *m, t_player *p)
{
	int	mp;
	int	mx;
	int	my;
(void)p;
	mx = (int)(x) / SCALE;
	my = (int)(y) / SCALE;
	mp = my * m->size[X] + mx;
	if ((m->arr)[mp] == 1)
		return (1);
		// mp < m->size[X] * m->size[Y] && (m->arr)[mp] == 0
	 	// && (int)(p->dir) % 45 == 0 && (int)(p->dir) % 90 != 0 // aquest no serveix perque sembla que no necessariament creua en aquests angles
	 	// && (concave_corner(m, p->dir, mp) == 1)) //si nomes posem aquest es para on no toca
	 	// 	return (1);
	return (0);
}

void	move_front(t_player *p, t_player *minipl, t_map *m)
{
	// int plus_x_mp;
	// int plus_y_mp;

	// if (p->dx < 0)
	// 	p->o[X] = -20; // o = offset possible desplaçament
	// if (p->dy < 0)
	// 	p->o[Y] = -20;
	// m->p[X] = p->x / SCALE;
	// m->p[Y] = p->y / SCALE;
	// plus_x_mp = (p->x + p->o[X]) / SCALE;
	// plus_y_mp = (p->y + p->o[Y]) / SCALE;
	// if (m->arr[m->p[Y] * m->size[X] + plus_x_mp] == 0
	// 	&& m->arr[plus_y_mp * m->size[X] + m->p[X]] == 0)
	// {
	// 	p->x += p->dx * SPEED;
	// 	minipl->x += p->dx / 4 * SPEED;
	// 	p->y += p->dy * SPEED;
	// 	minipl->y += p->dy / 4 * SPEED;
	// }
	if (!wall_found(p->x + p->dx, p->y + p->dy, m, p)
		&& !wall_found(p->x + p->dx * 2, p->y + p->dy * 2, m, p)
		&& !wall_found(p->x + p->dx * 3, p->y + p->dy * 3, m, p)
		&& !wall_found(p->x + p->dx * 4, p->y + p->dy * 4, m, p)
		&& !move_concave(p->dx, p->dy, p, m))
		// && m->arr[m->p[Y] * m->size[X] + plus_x_mp] == 0
		// && m->arr[plus_y_mp * m->size[X] + m->p[X]] == 0)
	{
		p->x += p->dx * SPEED;
		p->y += p->dy * SPEED;
		minipl->x += p->dx / 4 * SPEED;
		minipl->y += p->dy / 4 * SPEED;
	}
}

void	move_back(t_player *p, t_player *minipl, t_map *m)
{
	// int minus_x_mp;
	// int minus_y_mp;

	// if (p->dx < 0)
	// 	p->o[X] = -20; // o = offset possible desplaçament
	// if (p->dy < 0)
	// 	p->o[Y] = -20;
	// m->p[X] = p->x / SCALE;
	// m->p[Y] = p->y / SCALE;
	// minus_x_mp = (p->x - p->o[X]) / SCALE;
	// minus_y_mp = (p->y - p->o[Y]) / SCALE;
	// if (m->arr[m->p[Y] * m->size[X] + minus_x_mp] == 0
	// 	&& m->arr[minus_y_mp * m->size[X] + m->p[X]] == 0)
	// {
	// 	p->x -= p->dx * SPEED;
	// 	minipl->x -= p->dx / 4 * SPEED;
	// 	p->y -= p->dy * SPEED;
	// 	minipl->y -= p->dy / 4 * SPEED;
	// }
	// if (m->arr[m->p[Y] * m->size[X] + minus_x_mp] == 0)
	// {
	// 	p->x -= p->dx * 0.5 * SPEED;
	// 	minipl->x -= p->dx * 0.5 / 4 * SPEED;
	// }
	// if (m->arr[minus_y_mp * m->size[X] + m->p[X]] == 0)
	// {
	// 	p->y -= p->dy * 0.5 * SPEED;
	// 	minipl->y -= p->dy * 0.5 / 4 * SPEED;
	// }
	if (!wall_found(p->x - p->dx, p->y - p->dy, m, p)
		&& !wall_found(p->x - p->dx * 2, p->y - p->dy * 2, m, p)
		&& !wall_found(p->x - p->dx * 3, p->y - p->dy * 3, m, p)
		&& !wall_found(p->x - p->dx * 4, p->y - p->dy * 4, m, p)
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
	// int 	plus_x_mp;
	// int 	plus_y_mp;

	new_dir = angle_correction(90 - p->dir);
	new_dx = cos(deg_to_rad(new_dir));
	new_dy = sin(deg_to_rad(new_dir));
	// if (new_dx < 0)
	// 	p->o[X] = -20; // o = offset possible desplaçament
	// if (new_dy < 0)
	// 	p->o[Y] = -20;
	// m->p[X] = p->x / SCALE;
	// m->p[Y] = p->y / SCALE;
	// plus_x_mp = (p->x + p->o[X]) / SCALE;
	// //minus_x_mp = (p->x - p->o[X]) / SCALE;
	// plus_y_mp = (p->y + p->o[Y]) / SCALE;
	// //minus_y_mp = (p->y - p->o[Y]) / SCALE;
	// if (m->arr[m->p[Y] * m->size[X] + plus_x_mp] == 0
	// 	&& m->arr[plus_y_mp * m->size[X] + m->p[X]] == 0)
	// {
	// 	p->x += new_dx * SPEED;
	// 	minipl->x += new_dx / 4 * SPEED;
	// 	p->y += new_dy * SPEED;
	// 	minipl->y += new_dy / 4 * SPEED;
	// }
	if (!wall_found(p->x + new_dx, p->y + new_dy, m, p)
		&& !wall_found(p->x + new_dx * 2, p->y + new_dy * 2, m, p)
		&& !wall_found(p->x + new_dx * 3, p->y + new_dy * 3, m, p)
		&& !wall_found(p->x + new_dx * 4, p->y + new_dy * 4, m, p)
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
	if (!wall_found(p->x - new_dx, p->y - new_dy, m, p)
		&& !wall_found(p->x - new_dx * 2, p->y - new_dy * 2, m, p)
		&& !wall_found(p->x - new_dx * 3, p->y - new_dy * 3, m, p)
		&& !wall_found(p->x - new_dx * 4, p->y - new_dy * 4, m, p)
		&& !move_concave((new_dx * -1), (new_dy * -1), p, m))
	{
		p->x -= new_dx * SPEED;
		p->y -= new_dy * SPEED;
		minipl->x -= new_dx / 4 * SPEED; //RESIZING
		minipl->y -= new_dy / 4 * SPEED;
	}
}

// void	move_front(t_data *info)
// {
// 	if (!wall_found(info->player.x + info->player.dx * 2,
// 		info->player.y + info->player.dy * 2, &(info->map)))
// 	{
// 		info->player.x += info->player.dx * SPEED;
// 		info->player.y += info->player.dy * SPEED;
// 		info->minipl.x += info->player.dx / 4 * SPEED;
// 		info->minipl.y += info->player.dy / 4 * SPEED;
// 	}
// }

// void	move_back(t_data *info)
// {
// 	if (!wall_found(info->player.x - info->player.dx * 2,
// 		info->player.y - info->player.dy * 2, &(info->map)))
// 	{
// 		info->player.x -= info->player.dx * SPEED;
// 		info->player.y -= info->player.dy * SPEED;
// 		info->minipl.x -= info->player.dx / 4 * SPEED;
// 		info->minipl.y -= info->player.dy / 4 * SPEED;
// 	}
// }

// void	move_right(t_data *info)
// {
// 	float	new_dir;
// 	float	new_dx;
// 	float	new_dy;

// 	new_dir = angle_correction(90 - info->player.dir);
// 	new_dx = cos(deg_to_rad(new_dir));
// 	new_dy = sin(deg_to_rad(new_dir));
// 	if (!wall_found(info->player.x + new_dx * 2,
// 		info->player.y + new_dy * 2, &(info->map)))
// 	{
// 		info->player.x += new_dx * SPEED;
// 		info->player.y += new_dy * SPEED;
// 		info->minipl.x += new_dx / 4 * SPEED;
// 		info->minipl.y += new_dy / 4 * SPEED;
// 	}
// }

// void	move_left(t_data *info)
// {
// 	float	new_dir;
// 	float	new_dx;
// 	float	new_dy;

// 	new_dir = angle_correction(90 - info->player.dir);
// 	new_dx = cos(deg_to_rad(new_dir));
// 	new_dy = sin(deg_to_rad(new_dir));
// 	if (!wall_found(info->player.x - new_dx * 2,
// 		info->player.y - new_dy * 2, &(info->map)))
// 	{
// 		info->player.x -= new_dx * SPEED;
// 		info->player.y -= new_dy * SPEED;
// 		info->minipl.x -= new_dx / 4 * SPEED;
// 		info->minipl.y -= new_dy / 4 * SPEED;
// 	}
// }
