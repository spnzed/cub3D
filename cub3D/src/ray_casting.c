/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:21:29 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/23 17:44:15 by erosas-c         ###   ########.fr       */
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
//	int	or_miss;

	i = 0;
	incr = (float)60 / (float)WIDTH;
	//printf("incr: %f\n", incr);
	ang = (float)info->player.dir - 30.0;
	init_arr(info);
//	printf("info->player.dir: %i, info->player.dir + 30: %i info->player.dir - 30: %i\n", info->player.dir, info->player.dir + 30, info->player.dir - 30);
	while (i < WIDTH)
	{
		fill_ray(info->mlx->img.img_adr, info, angle_correction(ang), i);
		i++;
		ang += incr;
	}
	/*or_miss = orient_missing(info->ray);
	while (or_miss)
	{
		i = -1;
		while (++i < 61)
		{
			if (!(info->ray)[i].wall_or && i > 0)
				(info->ray)[i].wall_or = (info->ray)[i - 1].wall_or;
		}
		or_miss = orient_missing(info->ray);
	}*/
	/*i = -1;
	while(++i < 1920)
		printf("ray[%i].len: %f, ray[%i].wall_or: %c\n", i, (info->ray)[i].len, i, (info->ray)[i].wall_or);*/
}