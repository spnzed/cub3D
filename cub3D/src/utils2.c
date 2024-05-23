/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:46:33 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/23 17:43:48 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	angle_correction(float ang)
{
	if (ang > 359)
		ang -= 360;
	if (ang < 0)
		ang += 360;
	return (ang);
}

float	deg_to_rad(float d)
{
	return (d * M_PI / 180.0);
}

void	player_direction(char c, t_data *info)
{
	if (c == 'N')
		info->player.dir = 90;
	if (c == 'S')
		info->player.dir = 270;
	if (c == 'W')
		info->player.dir = 180;
	if (c == 'E')
		info->player.dir = 0;
}
