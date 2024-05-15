/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_arrows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:34:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/15 13:01:03 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_r_arrow(t_data *info)
{
	/*info->player.p_dir= angle_correction(info->player.p_dir+ SPEED);
	info->player.p_dir[X] = cos(deg_to_rad(info->player.p_dir));
	info->player.p_dir[Y] = -sin(deg_to_rad(info->player.p_dir));*/
	info->player.p_dir-= 1;
	if (info->player.p_dir< 0)
		info->player.p_dir+= 360;
	info->minipl.dir[X] = cos(deg_to_rad(info->player.p_dir));
	info->minipl.dir[Y] = -sin(deg_to_rad(info->player.p_dir));
	info->player.dir[X] = info->minipl.dir[X] * 6;
	info->player.dir[Y] = info->minipl.dir[Y] * 6;
	/*info->player.p_dir= angle_correction(info->player.p_dir+ SPEED);
	info->player.p_dir_cor[X] = cos(deg_to_rad(info->player.p_dir));
	info->player.p_dir_cor[Y] = -sin(deg_to_rad(info->player.p_dir));*/
}

void	move_l_arrow(t_data *info)
{
	/*info->player.p_dir= angle_correction(info->player.p_dir- SPEED);
	info->player.p_dir[X] = cos(deg_to_rad(info->player.p_dir));
	info->player.p_dir[Y] = -sin(deg_to_rad(info->player.p_dir));*/
	info->player.p_dir+= 1;
	if (info->player.p_dir> 360)
		info->player.p_dir-= 360;
	info->minipl.dir[X] = cos(deg_to_rad(info->player.p_dir));
	info->minipl.dir[Y] = -sin(deg_to_rad(info->player.p_dir));
	info->player.dir[X] = info->minipl.dir[X] * 6;
	info->player.dir[Y] = info->minipl.dir[Y] * 6;
	/*info->player.p_dir= angle_correction(info->player.p_dir- SPEED);
	info->player.p_dir_cor[X] = cos(deg_to_rad(info->player.p_dir));
	info->player.p_dir_cor[Y] = -sin(deg_to_rad(info->player.p_dir));*/
}
