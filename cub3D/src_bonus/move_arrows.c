/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_arrows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:34:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/14 19:46:17 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	move_concave(float dx, float dy, t_player *p, t_map *m)
{
	m->p[X] = (int)(p->x + dx * 10) / SCALE;
	m->p[Y] = (int)(p->y) / SCALE;
	if (m->arr[m->p[Y] * m->size[X] + m->p[X]] == 1)
		return (1);
	m->p[X] = (int)(p->x) / SCALE;
	m->p[Y] = (int)(p->y + dy * 10) / SCALE;
	if (m->arr[m->p[Y] * m->size[X] + m->p[X]] == 1)
		return (1);
	return (0);
}

void	move_r_arrow(t_data *info)
{
	info->player.dir -= 1;
	if (info->player.dir < 0)
		info->player.dir += 360;
	info->player.dx = cos(deg_to_rad(info->player.dir));
	info->player.dy = -sin(deg_to_rad(info->player.dir));
}

void	move_l_arrow(t_data *info)
{
	info->player.dir += 1;
	if (info->player.dir > 360)
		info->player.dir -= 360;
	info->player.dx = cos(deg_to_rad(info->player.dir));
	info->player.dy = -sin(deg_to_rad(info->player.dir));
}
