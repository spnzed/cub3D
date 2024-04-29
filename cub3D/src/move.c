/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:31:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/26 15:57:47 by aaronespino      ###   ########.fr       */
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
	// CUIDAO info->map.size[0] puede ser 1 y viceversa, CAMBIAR CON DEFINES
	if ((next_x < info->map.size[0] && next_y < info->map.size[1]
			&& info->map.grid[next_y][next_x] != '1'))
		return (1);
	return (0);
}

void	move_front(t_data *info)
{
	if (check_collision(info,
			info->player.x + info->player.p_dir_x * SPEED,
			info->player.y + info->player.p_dir_y * SPEED))
	{
		info->player.x += info->player.p_dir_x * SPEED;
		info->player.y += info->player.p_dir_y * SPEED;
	}
}

void	move_back(t_data *info)
{
	if (check_collision(info,
			info->player.x - info->player.p_dir_x * SPEED,
			info->player.y - info->player.p_dir_y * SPEED))
	{
		info->player.x -= info->player.p_dir_x * SPEED;
		info->player.y -= info->player.p_dir_y * SPEED;
	}
}

void	move_right(t_data *info)
{
	int	new_p_dir;
	int	new_p_dir_x;
	int	new_p_dir_y;

	new_p_dir = angle_correction(90 - info->player.p_dir);
	new_p_dir_x = cos(deg_to_rad(new_p_dir));
	new_p_dir_y = sin(deg_to_rad(new_p_dir));
	if (check_collision(info,
			info->player.x + new_p_dir_x * SPEED,
			info->player.y + new_p_dir_y * SPEED))
	{
		info->player.x += new_p_dir_x * SPEED;
		info->player.y += new_p_dir_y * SPEED;
	}
}

void	move_left(t_data *info)
{
	int	new_p_dir;
	int	new_p_dir_x;
	int	new_p_dir_y;

	new_p_dir = angle_correction(90 - info->player.p_dir);
	new_p_dir_x = cos(deg_to_rad(new_p_dir));
	new_p_dir_y = sin(deg_to_rad(new_p_dir));
	if (check_collision(info,
			info->player.x - new_p_dir_x * SPEED,
			info->player.y - new_p_dir_y * SPEED))
	{
		info->player.x -= new_p_dir_x * SPEED;
		info->player.y -= new_p_dir_y * SPEED;
	}
}
