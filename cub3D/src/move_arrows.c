/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_arrows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:34:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/13 17:02:08 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_r_arrow(t_data *info)
{
	info->player.dir = angle_correction(info->player.dir + SPEED);
	info->player.dx = cos(deg_to_rad(info->player.dir));
	info->player.dy = -sin(deg_to_rad(info->player.dir));
	/*info->bigpl->ang -= 0.1;
	if (info->bigpl->ang < 0)
		info->bigpl->ang += 2 * PI;
	info->bigpl->dx = cos(info->bigpl->ang) * 2;
	info->bigpl->dy = sin(info->bigpl->ang) * 2;
	printf("info->bigpl->dy: %f, info->bigpl->dx: %f\n", info->bigpl->dy, info->bigpl->dx);
	info->minipl->ang = info->bigpl->ang;
	info->minipl->dx = info->bigpl->dx / 2;
	info->minipl->dy = info->bigpl->dy / 2;*/
}

void	move_l_arrow(t_data *info)
{
	info->player.dir = angle_correction(info->player.dir - SPEED);
	info->player.dx = cos(deg_to_rad(info->player.dir));
	info->player.dy = -sin(deg_to_rad(info->player.dir));
}
