/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:21:29 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/23 17:44:56 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_arr(t_data *info)
{
	info->ray = ft_calloc(sizeof(t_ray), 61);
	if (!info->ray)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
}

void	cast_rays(t_data *info)
{
	int	ang;
	int	i;

	i = 0;
	ang = info->player.dir - 30;
	init_arr(info);
//	printf("info->player.dir: %i, info->player.dir + 30: %i info->player.dir - 30: %i\n", info->player.dir, info->player.dir + 30, info->player.dir - 30);
	while (ang <= info->player.dir + 30)
	{
		fill_ray(info->mlx->img.img_adr, info, angle_correction(ang), i);
		i++;
		ang++;
	}
/*	i = -1;
	while(++i < 61)
		printf("ray[%i].len: %f, ray[%i].wall_or: %c\n", i, (info->ray)[i].len, i, (info->ray)[i].wall_or);*/
}
