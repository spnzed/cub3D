/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:31:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/14 19:28:01 by erosas-c         ###   ########.fr       */
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
	// CUIDAO info->map.size[X] puede ser 1 y viceversa, CAMBIAR CON DEFINES
	if ((next_x < info->map.size[X] && next_y < info->map.size[Y]
			&& info->map.grid[next_y][next_x] != '1'))
		return (1);
	return (0);
}*/

void	move_front(t_data *info)
{
	/*if (check_collision(info,
			info->player.x + info->player.dx * SPEED,
			info->player.y + info->player.dy * SPEED))
	{*/
		//printf("hola, info->player.p_dir_y_sin: %f\n", info->player.p_dir_y_sin);
		info->player.x += info->player.dx;
//		printf("BEFORE info->player.y: %f, x: %f\n", info->player.y, info->player.x);
		info->player.y += info->player.dy;
//		printf("AFTER info->player.y: %f, x: %f\n", info->player.y, info->player.x);
		info->minipl.x += info->minipl.dx;
		info->minipl.y += info->minipl.dy;
//	}
}

void	move_back(t_data *info)
{
	/*if (check_collision(info,
			info->player.x - info->player.dx * SPEED,
			info->player.y - info->player.dy * SPEED))
	{*/
	info->player.x -= info->player.dx;
	info->player.y -= info->player.dy;
	info->minipl.x -= info->minipl.dx;
	info->minipl.y -= info->minipl.dy;
	//}
}

void	move_right(t_data *info)
{
	float	new_dir;
	float	new_dx;
	float	new_dy;

	new_dir = angle_correction(90 - info->player.dir);
	new_dx = cos(deg_to_rad(new_dir));
	new_dy = sin(deg_to_rad(new_dir));
	/*if (check_collision(info,
			info->player.x + new_dir_cor[X] * SPEED,
			info->player.y + new_dir_cor[Y] * SPEED))
	{
		info->player.x += new_dir_cor[X] * SPEED;
		info->player.y += new_dir_cor[Y] * SPEED;
	}*/
	info->player.x += new_dx * 6;
	info->player.y += new_dy * 6;
	info->minipl.x += new_dx;
	info->minipl.y += new_dy;
	//CHECKTHIS
	/*int	new_dir;
	int	new_dir_cor[2];

	new_dir = angle_correction(90 - info->player.dir);
	new_dir_cor[X] = cos(deg_to_rad(new_dir));
	new_dir_cor[Y] = sin(deg_to_rad(new_dir));*/
}

void	move_left(t_data *info)
{
	float	new_dir;
	float	new_dx;
	float	new_dy;

	new_dir = angle_correction(90 - info->player.dir);
	new_dx = cos(deg_to_rad(new_dir));
	new_dy = sin(deg_to_rad(new_dir));
	/*if (check_collision(info,
			info->player.x - new_p_dir_x_cos * SPEED,
			info->player.y - new_p_dir_y_sin * SPEED))
	{*/
	info->player.x -= new_dx * 6;
	info->player.y -= new_dy * 6;
	info->minipl.x -= new_dx;
	info->minipl.y -= new_dy;
	//CHECKTHIS
	/*int	new_dir;
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
	}*/
}
