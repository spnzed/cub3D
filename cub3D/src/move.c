/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:31:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/30 15:33:58 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_collision(t_data *info, float x, float y)
{
	int	next_x;
	int	next_y;

	next_x = (int)(x) / SCALE;
	next_y = (int)(y) / SCALE;
	if (next_x < 0 || next_y < 0)
		return (0);
	// CUIDAO info->map.size[X] puede ser 1 y viceversa, CAMBIAR CON DEFINES
	if ((next_x < info->map.size[X] && next_y < info->map.size[Y]
			&& info->map.grid[next_y][next_x] != '1'))
		return (1);
	return (0);
}

void	move_front(t_data *info)
{
	if (check_collision(info,
			info->player.x + info->player.dir_cor[X] * SPEED,
			info->player.y + info->player.dir_cor[Y] * SPEED))
	{
		info->player.x += info->player.dir_cor[X] * SPEED;
		info->player.y += info->player.dir_cor[Y] * SPEED;
	}
}

void	move_back(t_data *info)
{
	if (check_collision(info,
			info->player.x - info->player.dir_cor[X] * SPEED,
			info->player.y - info->player.dir_cor[Y] * SPEED))
	{
		info->player.x -= info->player.dir_cor[X] * SPEED;
		info->player.y -= info->player.dir_cor[Y] * SPEED;
	}
}

void	move_right(t_data *info)
{
	int	new_dir;
	int	new_dir_cor[2];

	new_dir = angle_correction(90 - info->player.dir);
	new_dir_cor[X] = cos(deg_to_rad(new_dir));
	new_dir_cor[Y] = sin(deg_to_rad(new_dir));
	if (check_collision(info,
			info->player.x + new_dir_cor[X] * SPEED,
			info->player.y + new_dir_cor[Y] * SPEED))
	{
		info->player.x += new_dir_cor[X] * SPEED;
		info->player.y += new_dir_cor[Y] * SPEED;
	}
}

void	move_left(t_data *info)
{
	int	new_dir;
	int	new_dir_cor[2];

	new_dir = angle_correction(90 - info->player.dir);
	new_dir_cor[X] = cos(deg_to_rad(new_dir));
	new_dir_cor[Y] = sin(deg_to_rad(new_dir));
	if (check_collision(info,
			info->player.x - new_dir_cor[X] * SPEED,
			info->player.y - new_dir_cor[Y] * SPEED))
	{
		info->player.x -= new_dir_cor[X] * SPEED;
		info->player.y -= new_dir_cor[Y] * SPEED;
	}
}
