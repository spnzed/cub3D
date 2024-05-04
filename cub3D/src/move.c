/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:31:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/04 10:51:23 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*static int	check_collision(t_data *info, float x, float y)
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
}*/

void	move_front(t_data *info)
{
	/*if (check_collision(info,
			info->player.x + info->player.p_dir_x_cos * SPEED,
			info->player.y + info->player.p_dir_y_sin * SPEED))
	{
		info->player.x += info->player.p_dir_x_cos * SPEED;
		info->player.y += info->player.p_dir_y_sin * SPEED;*/
		info->minipl->y -= 0.5;
		info->bigpl->y -= 1;
	//}
}

void	move_back(t_data *info)
{
	/*if (check_collision(info,
			info->player.x - info->player.p_dir_x_cos * SPEED,
			info->player.y - info->player.p_dir_y_sin * SPEED))
	{
		info->player.x -= info->player.p_dir_x_cos * SPEED;
		info->player.y -= info->player.p_dir_y_sin * SPEED;*/
		info->minipl->y += 0.5;
		info->bigpl->y += 1;
	//}
}

void	move_right(t_data *info)
{
	/*int	new_p_dir;
	int	new_p_dir_x_cos;
	int	new_p_dir_y_sin;

	new_p_dir = angle_correction(90 - info->player.p_dir);
	new_p_dir_x_cos = cos(deg_to_rad(new_p_dir));
	new_p_dir_y_sin = sin(deg_to_rad(new_p_dir));
	if (check_collision(info,
			info->player.x + new_p_dir_x_cos * SPEED,
			info->player.y + new_p_dir_y_sin * SPEED))
	{
		info->player.x += new_p_dir_x_cos * SPEED;
		info->player.y += new_p_dir_y_sin * SPEED;*/
		info->minipl->x += 0.5;
		info->bigpl->x += 1;
	//}
}

void	move_left(t_data *info)
{
	/*int	new_p_dir;
	int	new_p_dir_x_cos;
	int	new_p_dir_y_sin;

	new_p_dir = angle_correction(90 - info->player.p_dir);
	new_p_dir_x_cos = cos(deg_to_rad(new_p_dir));
	new_p_dir_y_sin = sin(deg_to_rad(new_p_dir));
	if (check_collision(info,
			info->player.x - new_p_dir_x_cos * SPEED,
			info->player.y - new_p_dir_y_sin * SPEED))
	{
		info->player.x -= new_p_dir_x_cos * SPEED;
		info->player.y -= new_p_dir_y_sin * SPEED;*/
		info->minipl->x -= 0.5;
		info->bigpl->x -= 1;
	//}
}
