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

	mx = (int)(x) / m->cell_w;
	my = (int)(y) / m->cell_w;
	mp = my * m->size[X] + mx;
	if ((m->arr)[mp] == 1)
		return (1);
	return (0);
}

void	move_front(t_data *info)
{
	
	if (!wall_found(info->player.x + info->player.dx * 2,
		info->player.y + info->player.dy * 2, &(info->map)))
	{
		info->player.x += info->player.dx * 2;
		info->player.y += info->player.dy * 2;
		info->minipl.x += info->player.dx / 8;
		info->minipl.y += info->player.dy / 8;
	}
}

void	move_back(t_data *info)
{
	if (!wall_found(info->player.x - info->player.dx * 2,
		info->player.y - info->player.dy * 2, &(info->map)))
	{
		info->player.x -= info->player.dx * 2;
		info->player.y -= info->player.dy * 2;
		info->minipl.x -= info->player.dx / 8;
		info->minipl.y -= info->player.dy / 8;
	}
}

void	move_right(t_data *info)
{
	float	new_dir;
	float	new_dx;
	float	new_dy;

	new_dir = angle_correction(90 - info->player.dir);
	new_dx = cos(deg_to_rad(new_dir));
	new_dy = sin(deg_to_rad(new_dir));
	if (!wall_found(info->player.x + new_dx * 2,
		info->player.y + new_dy * 2, &(info->map)))
	{
		info->player.x += new_dx * 2;
		info->player.y += new_dy * 2;
		info->minipl.x += new_dx / 4;
		info->minipl.y += new_dy / 4;
	}
}

void	move_left(t_data *info)
{
	float	new_dir;
	float	new_dx;
	float	new_dy;

	new_dir = angle_correction(90 - info->player.dir);
	new_dx = cos(deg_to_rad(new_dir));
	new_dy = sin(deg_to_rad(new_dir));
	if (!wall_found(info->player.x - new_dx * 2,
		info->player.y - new_dy * 2, &(info->map)))
	{
		info->player.x -= new_dx * 2;
		info->player.y -= new_dy * 2;
		info->minipl.x -= new_dx / 4;
		info->minipl.y -= new_dy / 4;
	}
}
