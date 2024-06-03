/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:11:18 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/27 18:06:05 by erosas-c         ###   ########.fr       */
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
			scr[p] = 0x808080;
			++p;
		}
		i++;
		p = po + WIDTH * i;
	}
}

/*static void	paint_black(int *scr)
{
	int	p;

	p = -1;
	while (++p < HEIGHT * WIDTH)
		scr[p] = 0x000000;
}*/

static void	draw_player(int *scr, int xpl, int ypl, int color)
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
}

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
	while (++j < map->size[Y])
	{
		while (i < SCALE / 8 * 6 * (j + 1))
		{
			while (map->grid[j][k])
			{
				while (p < po + (SCALE / 8 * 6 * (k + 1) + (WIDTH * i)))
				{
					if (map->grid[j][k] == '1' && i % 48 != 0 && (p - WIDTH * i) % 48 != 0) 
						scr[p] = 0xffffff;
					else if (map->grid[j][k] != '1' && i % 48 != 0 && (p - WIDTH * i) % 48 != 0)
						scr[p] = 0x000000;
					p++;
				}
				k++;
			}
			ft_updvalues(&i, &p, po, &k);
		}
	}
}

int	get_bigmap2d(t_data *info)
{
	// int	mp_xp;
	// int	mp_yp;
	// int	p;
	//int	col_w;

	info->map2d = ft_calloc(sizeof(int), WIDTH * HEIGHT);
	if (!info->map2d)
	{
		ft_err("Error: Malloc\n");
		return (1);
	}
//	col_w = SCALE / 8 * 6;
	// mp_xp = 0;
	// mp_yp = 0;
	// p = mp_yp * WIDTH + mp_xp;
	//fill_bigmap(info->map2d, &info->map, p, 0);
	fill_bigmap(info->mlx->img.img_adr, &info->map, 0, 0);
	//fill_bigmap(info->mlx->img.img_adr, &info->map, p, 0);
//	fill_ray(info->mlx->img.img_adr, &info->player, info);
	
	draw_player(info->mlx->img.img_adr, info->player.x,
		info->player.y, 0xFFFF00);
	return (0);
}
