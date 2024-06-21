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

static int	wall_found(float x, float y, t_map *m, t_player *p)
{
	int	mp;
	int	mx;
	int	my;

	mx = (int)(x) / m->cell_w;
	my = (int)(y) / m->cell_w;
	mp = my * m->size[X] + mx;
	if ((m->arr)[mp] == 1)
		return (1);
	else if (mp < m->size[X] * m->size[Y] && (m->arr)[mp] == 0
		&& (int)(p->dir) % 45 == 0 && (int)(p->dir) % 90 != 0
		&& (concave_corner(m, p->dir, mp) == 1))
			return (1);
	
	return (0);
}

void	move_front(t_player *p, t_player *minipl, t_map *m)
{
	if (!wall_found(p->x + p->dx, p->y + p->dy, m, p)
		&& !wall_found(p->x + p->dx * 2, p->y + p->dy * 2, m, p)
		&& !wall_found(p->x + p->dx * 3, p->y + p->dy * 3, m, p)
		&& !wall_found(p->x + p->dx * 4, p->y + p->dy * 4, m, p))
	{
		p->x += p->dx * SPEED;
		p->y += p->dy * SPEED;
		minipl->x += p->dx / 4 * SPEED;
		minipl->y += p->dy / 4 * SPEED;
	}
}

void	move_back(t_player *p, t_player *minipl, t_map *m)
{
	if (!wall_found(p->x - p->dx, p->y - p->dy, m, p)
		&& !wall_found(p->x - p->dx * 2, p->y - p->dy * 2, m, p)
		&& !wall_found(p->x - p->dx * 3, p->y - p->dy * 3, m, p)
		&& !wall_found(p->x - p->dx * 4, p->y - p->dy * 4, m, p))
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
	if (!wall_found(p->x + new_dx, p->y + new_dy, m, p)
		&& !wall_found(p->x + new_dx * 2, p->y + new_dy * 2, m, p)
		&& !wall_found(p->x + new_dx * 3, p->y + new_dy * 3, m, p)
		&& !wall_found(p->x + new_dx * 4, p->y + new_dy * 4, m, p))
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
		&& !wall_found(p->x - new_dx * 4, p->y - new_dy * 4, m, p))
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
