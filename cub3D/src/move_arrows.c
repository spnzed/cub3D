/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_arrows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:34:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/15 15:39:12 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_r_arrow(t_data *info)
{
	/*info->player.angle = angle_correction(info->player.angle+ SPEED);
	info->player.angle[X] = cos(deg_to_rad(info->player.angle));
	info->player.angle[Y] = -sin(deg_to_rad(info->player.angle));*/
	info->player.angle-= 1;
	if (info->player.angle< 0)
		info->player.angle+= 360;
	info->minipl.dir[X] = cos(deg_to_rad(info->player.angle));
	info->minipl.dir[Y] = -sin(deg_to_rad(info->player.angle));
	info->player.dir[X] = info->minipl.dir[X] * 6;
	info->player.dir[Y] = info->minipl.dir[Y] * 6;
	/*info->player.angle = angle_correction(info->player.angle+ SPEED);
	info->player.angle_cor[X] = cos(deg_to_rad(info->player.angle));
	info->player.angle_cor[Y] = -sin(deg_to_rad(info->player.angle));*/
}

void	move_l_arrow(t_data *info)
{
	/*info->player.angle = angle_correction(info->player.angle- SPEED);
	info->player.angle[X] = cos(deg_to_rad(info->player.angle));
	info->player.angle[Y] = -sin(deg_to_rad(info->player.angle));*/
	info->player.angle+= 1;
	if (info->player.angle> 360)
		info->player.angle-= 360;
	info->minipl.dir[X] = cos(deg_to_rad(info->player.angle));
	info->minipl.dir[Y] = -sin(deg_to_rad(info->player.angle));
	info->player.dir[X] = info->minipl.dir[X] * 6;
	info->player.dir[Y] = info->minipl.dir[Y] * 6;
	/*info->player.angle = angle_correction(info->player.angle- SPEED);
	info->player.angle_cor[X] = cos(deg_to_rad(info->player.angle));
	info->player.angle_cor[Y] = -sin(deg_to_rad(info->player.angle));*/
}
