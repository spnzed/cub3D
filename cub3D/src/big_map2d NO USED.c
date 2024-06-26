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
	while (i < SCALE * map->size[Y])
	{
		while (p < SCALE * map->size[X] + (WIDTH * i))
		{
			scr[p] = 0x808080;
			++p;
		}
		i++;
		p = WIDTH * i;
	}
}

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
		while (i < SCALE * (j + 1))
		{
			while (map->grid[j][k])
			{
				while (++p < (SCALE * (k + 1) + (WIDTH * i)))
				{
					if (map->grid[j][k] == '1' && i % (SCALE) != 0
						&& (p - WIDTH * i) % (SCALE) != 0)
						scr[p] = 0xffffff;
					else if (map->grid[j][k] != '1' && i % (SCALE) != 0
						&& (p - WIDTH * i) % (SCALE) != 0)
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
	paint_gray(info->mlx->img.img_adr, &info->map, 0);
	fill_bigmap(info->mlx->img.img_adr, &info->map, -1, 0);
	return (0);
}
