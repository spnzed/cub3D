/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:31:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/21 20:02:54 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	wall_found(int *scr, t_player *player)
{
	int	pos;

	pos = 0;
	if (player->n[X] != 0 && player->n[Y] != 0)
	{
		pos = player->n[Y] * WIDTH + player->n[X];
		if (scr[pos] == 0xFF0000)
			return (1);
	}
	return (0);
}

void	move_front(t_data *info)
{
	if (!wall_found(info->mlx->img.img_adr, &info->player))
	/*if (check_collision(info,
			info->player.x + info->player.dx * SPEED,
			info->player.y + info->player.dy * SPEED))*/
	{
		info->player.x += info->player.dx;
		info->player.y += info->player.dy;
		info->minipl.x += info->minipl.dx;
		info->minipl.y += info->minipl.dy;
		info->player.n[X] = info->player.x;
		info->player.n[Y] = info->player.y;
	}
}

void	move_back(t_data *info)
{
	if (!wall_found(info->mlx->img.img_adr, &info->player))
	{
		info->player.x -= info->player.dx;
		info->player.y -= info->player.dy;
		info->minipl.x -= info->minipl.dx;
		info->minipl.y -= info->minipl.dy;
		info->player.n[X] = info->player.x;
		info->player.n[Y] = info->player.y;
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
	if (!wall_found(info->mlx->img.img_adr, &info->player))
	{
		info->player.x += new_dx * 6;
		info->player.y += new_dy * 6;
		info->minipl.x += new_dx;
		info->minipl.y += new_dy;
		info->player.n[X] = info->player.x;
		info->player.n[Y] = info->player.y;
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
	if (!wall_found(info->mlx->img.img_adr, &info->player))
	{
		info->player.x -= new_dx * 6;
		info->player.y -= new_dy * 6;
		info->minipl.x -= new_dx;
		info->minipl.y -= new_dy;
		info->player.n[X] = info->player.x;
		info->player.n[Y] = info->player.y;
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