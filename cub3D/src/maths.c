/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:50:11 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/15 19:14:27 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calc_positions(t_data *info, int i)
{
	info->ray.camera = 2 * i / (double)WIDTH - 1;
	info->ray.raydir[X] = info->ray.dir[X] + \
		info->ray.plane[X] * info->ray.camera;
	info->ray.raydir[Y] = info->ray.dir[Y] + \
		info->ray.plane[Y] * info->ray.camera;
	info->ray.deltadist[X] = sqrt(1 + (info->ray.raydir[Y] \
		* info->ray.raydir[Y]) / (info->ray.raydir[X] * info->ray.raydir[X]));
	info->ray.deltadist[Y] = sqrt(1 + (info->ray.raydir[X] \
		* info->ray.raydir[X]) / (info->ray.raydir[Y] * info->ray.raydir[Y]));
}

void	calc_step(t_data *info)
{
	if (info->ray.raydir[X] < 0)
	{
		info->ray.step[X] = -1;
		info->ray.sidedist[X] = (info->player.x - info->ray.pos[X]) \
			* info->ray.deltadist[X];
	}
	else
	{
		info->ray.step[X] = 1;
		info->ray.sidedist[X] = (info->ray.pos[X] + 1.0 - info->player.x) \
			* info->ray.deltadist[X];
	}
	if (info->ray.raydir[Y] < 0)
	{
		info->ray.step[Y] = -1;
		info->ray.sidedist[Y] = (info->player.y - info->ray.pos[Y]) \
			* info->ray.deltadist[Y];
	}
	else
	{
		info->ray.step[Y] = 1;
		info->ray.sidedist[Y] = (info->ray.pos[Y] + 1.0 - info->player.y) \
			* info->ray.deltadist[Y];
	}
}

void	calc_hit(t_data *info)
{
	while (1)
	{
		if (info->ray.sidedist[X] < info->ray.sidedist[Y])
		{
			info->ray.sidedist[X] += info->ray.deltadist[X];
			info->ray.pos[X] += info->ray.step[X];
			info->ray.side[X] = 1;
			info->ray.side[Y] = 0;
			if (info->ray.step[X] < 0)
				info->ray.side[X] = -1;
		}
		else
		{
			info->ray.sidedist[Y] += info->ray.deltadist[Y];
			info->ray.pos[Y] += info->ray.step[Y];
			info->ray.side[X] = 0;
			info->ray.side[Y] = 1;
			if (info->ray.step[Y] < 0)
				info->ray.side[Y] = -1;
		}
		if (info->map.grid[(int)info->ray.pos[X]][(int)info->ray.pos[Y]] > 0)
			break ;
	}
}

void	calc_perp(t_data *info)
{
	if (info->ray.side[X] != 0)
		info->ray.perpwalldist = fabs((info->ray.pos[X] - info->ray.pos[X] + \
			(1 - info->ray.step[X]) / 2) / info->ray.dir[X]);
	else
		info->ray.perpwalldist = fabs((info->ray.pos[Y] - info->ray.pos[Y] + \
			(1 - info->ray.step[Y]) / 2) / info->ray.dir[Y]);
	info->ray.lineh = abs((int)(HEIGHT / info->ray.perpwalldist));
}
