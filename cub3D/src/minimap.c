/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:03:48 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/22 18:10:46 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_map(int *scr, t_data *info)
{
	int	p[2];
	int	pos;
	int	mp;

	p[X] = 8;
	p[Y] = 8;
	pos = p[Y] * WIDTH + p[X];
	mp = 0;
	while (p[Y] < (8 + (SCALE / 4) * info->map.size[Y]))
	{
		while (p[X] < (8 + (SCALE / 4) * info->map.size[X]))
		{
			mp = info->map.size[X] * ((p[Y] - 8) / (SCALE / 4))
				+ ((p[X] - 8) / (SCALE / 4));
			pos = p[Y] * WIDTH + p[X];
			if (info->map.arr[mp] == 1)
				scr[pos] = 0x000000;
			else
				scr[pos] = info->parameters.floor;
			(p[X])++;
		}
		p[X] = 8;
		(p[Y])++;
	}
}

// static void	draw_minipl(int *scr, int xpl, int ypl, int color)
// {
// 	int	x;
// 	int	y;

// 	x = xpl - 3;
// 	y = ypl - 3;
// 	while (++y <= ypl + 2)
// 	{
// 		while (++x <= xpl + 2)
// 			scr[y * WIDTH + x] = color;
// 		x = xpl - 3;
// 	}
// }

static void	print_miniray(int *scr, t_ray *r, t_player *minipl)
{
	t_point	minipts[2];

	minipts[0].x = (int)(minipl->x);
	minipts[0].y = (int)(minipl->y);
	minipts[1].x = 8 + (int)(r->end[X]) / 4;
	minipts[1].y = 8 + (int)(r->end[Y]) / 4;
	draw_line(scr, minipts, 0x00FFFF, 1);
}

void	mini_map(t_data *info)
{
	int i;

	i = -1;
	fill_map(info->mlx->img.img_adr, info);
	// draw_minipl(info->mlx->img.img_adr, info->minipl.x,
	// 	info->minipl.y, 0xFFFF00);
	while (++i < WIDTH)
		print_miniray(info->mlx->img.img_adr, &(info->ray[i]), &(info->minipl));
}
