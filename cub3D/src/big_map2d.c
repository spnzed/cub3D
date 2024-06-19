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

static void	paint_gray(int *scr, t_map *map, int p)
{
	int	i;

	i = 0;
	while (i < SCALE / 2 * map->size[Y])
	{
		while (p < SCALE / 2 * map->size[X] + (WIDTH * i))
		{
			scr[p] = 0x808080;
			++p;
		}
		i++;
		p = WIDTH * i;
	}
}

// static void	draw_player(int *scr, int xpl, int ypl, int color)
// {
// 	int	x;
// 	int	y;

// 	x = xpl - 3;
// 	y = ypl - 3;
// 	while (++y < ypl + 3)
// 	{
// 		while (++x < xpl + 3)
// 			scr[y * WIDTH + x] = color;
// 		x = xpl - 3;
// 	}
// }

static void	ft_updvalues(int *i, int *p, int *k)
{
	(*i)++;
	*p = WIDTH * (*i);
	*k = 0;
}

static void	fill_bigmap(int *scr, t_map *map, int p, int i)
{
	int	j;
	int	k;

	j = -1;
	k = 0;
	while (++j < map->size[Y])
	{
		while (i < SCALE / 2 * (j + 1))
		{
			while (map->grid[j][k])
			{
				while (++p < (SCALE / 2 * (k + 1) + (WIDTH * i))) //SCALE * info->map.size[X] >> en comptes de WIDTH ???
				{
					if (map->grid[j][k] == '1' && i % (SCALE / 2) != 0
						&& (p - WIDTH * i) % (SCALE / 2) != 0) //SCALE * info->map.size[X] >> en comptes de WIDTH ???
						scr[p] = 0xffffff;
					else if (map->grid[j][k] != '1' && i % (SCALE / 2) != 0
						&& (p - WIDTH * i) % (SCALE / 2) != 0) //SCALE * info->map.size[X] >> en comptes de WIDTH ???
						scr[p] = 0x000000;
				}
				k++;
			}
			ft_updvalues(&i, &p, &k);
		}
	}
}

int	get_bigmap2d(t_data *info)
{
	// t_point *pts;
	
	// pts = ft_calloc(sizeof(pts), 2);
	// if (!pts)
	// {
	// 	ft_err("Error: Malloc\n");
	// 	return (1);
	// }
	// pts[0].x = (int)(info->player.x);
	// pts[0].y = (int)(info->player.y);
	// pts[1].x = (int)(info->player.x + info->player.dx * 15);
	// pts[1].y = (int)(info->player.y + info->player.dy * 15);
	// info->map2d = ft_calloc(sizeof(int), WIDTH * HEIGHT); //SCALE * info->map.size[X] * SCALE * info->map.size[Y]);
	// if (!info->map2d)
	// {
	// 	ft_err("Error: Malloc\n");
	// 	return (1);
	// }
//	col_w = SCALE / 8 * 6;
	// mp_xp = 0;
	// mp_yp = 0;
	// p = mp_yp * WIDTH + mp_xp;
	//fill_bigmap(info->map2d, &info->map, -1, 0);
	//printf("hola\n");
	paint_gray(info->mlx->img.img_adr, &info->map, 0);
	fill_bigmap(info->mlx->img.img_adr, &info->map, -1, 0);
	//fill_bigmap(info->mlx->img.img_adr, &info->map, p, 0);
	// draw_player(info->mlx->img.img_adr, info->player.x,
	//  	info->player.y, 0x00FFFF);
	//draw_line(info->mlx->img.img_adr, pts, 0x00FFFF, 1);
	return (0);
}
