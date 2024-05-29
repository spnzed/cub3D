/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:21:29 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/27 20:07:34 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*static int	orient_missing(t_ray *ray)
{
	int	i;

	i = -1;
	while (++i < 61)
	{
		if (!ray[i].wall_or)
			return (1);
	}
	return (0);
}*/

static void	init_arr(t_data *info)
{
	info->ray = ft_calloc(sizeof(t_ray), WIDTH);
	if (!info->ray)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
}

void	cast_rays(t_data *info)
{
	float	ang;
	int		i;
	float	incr;

	i = 0;
	incr = (float)60 / (float)(WIDTH);
	ang = (float)info->player.dir;// + 30.0;
	init_arr(info);
	while (i < WIDTH)
	{
		//fill_ray(info->map2d, info, angle_correction(ang), i);
		fill_ray(info->mlx->img.img_adr, info, angle_correction(ang), i);
		i++;
		ang = ang - incr;
	}
/*	i = -1;
	while(++i < WIDTH)
		printf("ray[%i].wall_or: %c\n", i, (info->ray)[i].wall_or);*/
}
