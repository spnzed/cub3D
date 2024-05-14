/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_arrows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:34:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/30 15:46:02 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_r_arrow(t_data *info)
{
	info->player.dir= angle_correction(info->player.dir+ SPEED);
	info->player.dir_cor[X] = cos(deg_to_rad(info->player.dir));
	info->player.dir_cor[Y] = -sin(deg_to_rad(info->player.dir));
}

void	move_l_arrow(t_data *info)
{
	info->player.dir= angle_correction(info->player.dir- SPEED);
	info->player.dir_cor[X] = cos(deg_to_rad(info->player.dir));
	info->player.dir_cor[Y] = -sin(deg_to_rad(info->player.dir));
}
