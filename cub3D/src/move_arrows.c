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

void	move_r_arrow(t_data *info)
{
	/*info->player.dir = angle_correction(info->player.dir + SPEED);
	info->player.dx = cos(deg_to_rad(info->player.dir));
	info->player.dy = -sin(deg_to_rad(info->player.dir));*/
	info->player.dir -= 1;
	if (info->player.dir < 0)
		info->player.dir += 360;
	info->minipl.dx = cos(deg_to_rad(info->player.dir));
	info->minipl.dy = -sin(deg_to_rad(info->player.dir));
	info->player.dx = info->minipl.dx * 3;
	info->player.dy = info->minipl.dy * 3;
	/*info->player.dir= angle_correction(info->player.dir+ SPEED);
	info->player.dir_cor[X] = cos(deg_to_rad(info->player.dir));
	info->player.dir_cor[Y] = -sin(deg_to_rad(info->player.dir));*/
}

void	move_l_arrow(t_data *info)
{
	/*info->player.dir = angle_correction(info->player.dir - SPEED);
	info->player.dx = cos(deg_to_rad(info->player.dir));
	info->player.dy = -sin(deg_to_rad(info->player.dir));*/
	info->player.dir += 1;
	if (info->player.dir > 360)
		info->player.dir -= 360;
	info->minipl.dx = cos(deg_to_rad(info->player.dir));
	info->minipl.dy = -sin(deg_to_rad(info->player.dir));
	info->player.dx = info->minipl.dx * 3;
	info->player.dy = info->minipl.dy * 3;
	/*info->player.dir= angle_correction(info->player.dir- SPEED);
	info->player.dir_cor[X] = cos(deg_to_rad(info->player.dir));
	info->player.dir_cor[Y] = -sin(deg_to_rad(info->player.dir));*/
}
