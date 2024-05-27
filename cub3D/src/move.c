/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:31:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/27 18:09:53 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	wall_found(int *scr, float x, float y)
{
	int	pos;
	int	pos_x;
	int	pos_y;

	pos_x = (int)(x);
	pos_y = (int)(y);
	pos = pos_y * WIDTH + pos_x;
	if ((pos_x >= 0 && pos_y >= 0) && (pos_x < WIDTH && pos_y < HEIGHT)
		//&& scr[pos] != 0x000000 && scr[pos] != 0xFFFF00)
		&& scr[pos] == WALL)
		return (1);
	else if ((pos_x >= 0 && pos_y >= 0) && (pos_x < WIDTH && pos_y < HEIGHT)
		&& is_corner(scr, pos) == 1)
		return (1);
	return (0);
}

void	move_front(t_data *info)
{
	/*if (!wall_found(info->map2d, info->player.x + info->player.dx * 2,
		info->player.y + info->player.dy * 2))*/
	if (!wall_found(info->mlx->img.img_adr, info->player.x + info->player.dx * 2,
		info->player.y + info->player.dy * 2))
	/*if (check_collision(info,
			info->player.x + info->player.dx * SPEED,
			info->player.y + info->player.dy * SPEED))*/
	{
		info->player.x += info->player.dx;
		info->player.y += info->player.dy;
		info->minipl.x += info->minipl.dx;
		info->minipl.y += info->minipl.dy;
	}
}

void	move_back(t_data *info)
{
	/*if (!wall_found(info->map2d, info->player.x - info->player.dx * 2,
		info->player.y - info->player.dy * 2))*/
	if (!wall_found(info->mlx->img.img_adr, info->player.x - info->player.dx * 2,
		info->player.y - info->player.dy * 2))
	{
		info->player.x -= info->player.dx;
		info->player.y -= info->player.dy;
		info->minipl.x -= info->minipl.dx;
		info->minipl.y -= info->minipl.dy;
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
	/*if (!wall_found(info->map2d, info->player.x + new_dx * 3 * 2,
		info->player.y + new_dy * 3 * 2))*/
	if (!wall_found(info->mlx->img.img_adr, info->player.x + new_dx * 3 * 2,
		info->player.y + new_dy * 3 * 2))
	{
		info->player.x += new_dx * 3;
		info->player.y += new_dy * 3;
		info->minipl.x += new_dx;
		info->minipl.y += new_dy;
	}
}

	//CHECKTHIS
	/*int	new_dir; 
	int	new_dir_cor[2];
	new_dir = angle_correction(90 - info->player.dir);
	new_dir_cor[X] = cos(deg_to_rad(new_dir));
	new_dir_cor[Y] = sin(deg_to_rad(new_dir));*/
void	move_left(t_data *info)
{
	float	new_dir;
	float	new_dx;
	float	new_dy;

	new_dir = angle_correction(90 - info->player.dir);
	new_dx = cos(deg_to_rad(new_dir));
	new_dy = sin(deg_to_rad(new_dir));
	/*if (!wall_found(info->map2d, info->player.x - new_dx * 3 * 2,
		info->player.y - new_dy * 3 * 2))*/
	if (!wall_found(info->mlx->img.img_adr, info->player.x - new_dx * 3 * 2,
		info->player.y - new_dy * 3 * 2))
	{
		info->player.x -= new_dx * 3;
		info->player.y -= new_dy * 3;
		info->minipl.x -= new_dx;
		info->minipl.y -= new_dy;
	}
}

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