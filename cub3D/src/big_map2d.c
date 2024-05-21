/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:11:18 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/21 20:02:37 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	paint_black(int *scr, t_map *map, int p)
{
	int	po;
	int	i;

	po = p;
	i = 0;
	while (i < SCALE / 8 * 6 * map->size[Y])
	{
		while (p < po + SCALE / 8 * 6 * map->size[X] + (WIDTH * i))
		{
			scr[p] = 0x000000;
			++p;
		}
		i++;
		p = po + WIDTH * i;
	}
}

/*static void	draw_player(int *scr, int xpl, int ypl, int color)
{
	int	x;
	int	y;

	x = xpl - 4;
	y = ypl - 4;
	while (++y <= ypl + 3)
	{
		while (++x <= xpl + 3)
			scr[y * WIDTH + x] = color;
		x = xpl - 4;
	}
}*/

static void	ft_updvalues(int *i, int *p, int po, int *k)
{
	(*i)++;
	*p = po + WIDTH * (*i);
	*k = 0;
}

static void	fill_bigmap(int *scr, t_map *map, int p, int i)
{
	int	j;
	int	k;
	int	po;

	j = -1;
	k = 0;
	po = p;
	paint_black(scr, map, p);
	while (++j < map->size[1])
	{
		while (i < SCALE / 8 * 6 * (j + 1))
		{
			while (map->grid[j][k])
			{
				while (p < po + (SCALE / 8 * 6 * (k + 1) + (WIDTH * i)))
				{
					if (map->grid[j][k] == '1')
						scr[p] = 0xffffff;
					p++;
				}
				k++;
			}
			ft_updvalues(&i, &p, po, &k);
		}
	}
}

void	get_bigmap2d(t_data *info)
{
	int	mp_xp;
	int	mp_yp;
	int	p;
	int	col_w;

	col_w = SCALE / 8 * 6;
	mp_xp = WIDTH / 2 - info->map.size[X] * col_w / 2;
	mp_yp = HEIGHT / 2 - info->map.size[Y] * col_w / 2;
	p = mp_yp * WIDTH + mp_xp;
	fill_bigmap(info->mlx->img.img_adr, &info->map, p, 0);
	fill_ray(info->mlx->img.img_adr, &info->player, info);
	
/*	draw_player(info->mlx->img.img_adr, info->player.x,
		info->player.y, 0xFFFF00);*/
}
