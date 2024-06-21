/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:46:33 by erosas-c          #+#    #+#             */
/*   Updated: 2024/06/21 23:43:22 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	*ft_all_floatarr(void)
{
	float	*arr;

	arr = ft_calloc(sizeof(float), 2);
	if (!arr)
		ft_err("Error: Malloc\n");
	return (arr);
}

float	*alloc_floatarr(t_player *pl)
{
	float	*arr;

	arr = ft_calloc(sizeof(float), 2);
	if (!arr)
		ft_err("Error: Malloc\n");
	arr[X] = pl->x;
	arr[Y] = pl->y;
	return (arr);
}

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
