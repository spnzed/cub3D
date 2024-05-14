/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_arrows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:34:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/26 15:57:47 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_r_arrow(t_data *info)
{
	info->player.p_dir = angle_correction(info->player.p_dir + SPEED);
	info->player.p_dir_x = cos(deg_to_rad(info->player.p_dir));
	info->player.p_dir_y = -sin(deg_to_rad(info->player.p_dir));
}

void	move_l_arrow(t_data *info)
{
	info->player.p_dir = angle_correction(info->player.p_dir - SPEED);
	info->player.p_dir_x = cos(deg_to_rad(info->player.p_dir));
	info->player.p_dir_y = -sin(deg_to_rad(info->player.p_dir));
}
