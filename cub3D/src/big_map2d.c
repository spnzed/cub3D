/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:11:18 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/14 17:09:57 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_bigpl(int *scr, t_player *pl, int p, int w)
{
	int	c;
	int	po;
	int	h;
	int	i;

	i = 1;
	po = p;
	h = -1;
	c = 0xffff000;
	while (++h < pl->h)
	{
		while (++w < pl->w)
			scr[p++] = c;
		p = po + WIDTH * i;
		w = -1;
		i++;
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
	mp_xp = WIDTH / 2 - info->map.size[0] * col_w / 2;
	mp_yp = HEIGHT / 2 - info->map.size[1] * col_w / 2;
	p = mp_yp * WIDTH + mp_xp;
	fill_bigmap(info->mlx->img.img_adr, &info->map, p, 0);
	fill_bigpl(info->mlx->img.img_adr, &info->player,
		(info->player.y * WIDTH) + info->player.x, -1);
	fill_ray(info->mlx->img.img_adr, &info->player);
}
