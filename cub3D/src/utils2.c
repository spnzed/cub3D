/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:46:33 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/15 15:39:12 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	angle_correction(float ang)
{
	if (ang > 359)
		ang -= 360;
	else if (ang < 0)
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
		info->player.angle = 90;
	if (c == 'S')
		info->player.angle = 270;
	if (c == 'W')
		info->player.angle = 180;
	if (c == 'E')
		info->player.angle = 0;
}
