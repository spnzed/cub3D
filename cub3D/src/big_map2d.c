/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:11:18 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/11 14:26:04 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_ray(int *scr, t_player *pl, t_data *info)
{
	t_point	*pts;

	pts = ft_calloc(sizeof(pts), 2);
	if (!pts)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	pts[0].x = pl->x + pl->w / 2;
	pts[0].y = pl->y + pl->h / 2;
//	printf("pl->x: %f, pl->w: %i, pts[0].x: %i\n", pl->x, pl->w, pts[0].x);
//	printf("pl->y: %f, pl->y: %i, pts[0].y: %i\n", pl->y, pl->h, pts[0].y);
	pts[1].x = 0;
	pts[1].y = 0;
	if (pl->dir == 90)
	{
		pts[1].x = pts[0].x;
		pts[1].y = pts[0].y - pl->len;
	}
	else if (info->player.dir > 0 && pl->dir < (M_PI))
	{
		pts[1].x = pts[0].x + cos(pl->dir) * pl->len;
		pts[1].y = pts[0].y - sin(pl->dir) * pl->len;
	}
	draw_line(scr, pts, 0xFFFF00);
}

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

static void	fill_bigmap(int *scr, t_map *map, int p, int i)
{
	int	j;
	int	k;
	int	po;
	//t = t / 2;  // MacBook Ester
	j = -1;
	k = 0;
	po = p;
	while (++j < map->size[1])
	{
		while (i < SCALE / 2 * (j + 1))
		{
			while (map->grid[j][k])
			{
				while (p < po + (SCALE / 2 * (k + 1) + (WIDTH * i)))
				{
					if (map->grid[j][k] == '1')
						scr[p] = 0xffffff;
					p++;
				}
				k++;
			}
			i++;
			p = po + WIDTH * i;
			k = 0;
		}
	}
}

void	get_bigmap2d(t_data *info)
{
	int	mp_xp;
	int	mp_yp;
	int	p;

	mp_xp = WIDTH / 2 - info->map.size[0] * SCALE / 2 / 2;
	mp_yp = HEIGHT / 2 - info->map.size[1] * SCALE / 2 / 2;
	p = mp_yp * WIDTH + mp_xp;
/*	char	*temp[5];
	temp[0] = "111111";
	temp[1] = "100001";
	temp[2] = "100101";
	temp[3] = "1001E1";
	temp[4] = "111111";
	bigpl->x = WIDTH / 2 + (64 * 3 / 2); //64 = mida passadissos d'una unitat (utilitzada a fill_map) 3/2 per situar-se just enmig de la columna passadis 2a des del centre del mapa 2D (= WIDTH / 2)
	bigpl->y = HEIGHT / 2 + 64; // Li sumem 64 pq des del centre de les files (5 files), ens volem posar junt enmig de la 4a fila i la posicio del mig del mapa = HEIGHT / 2*/
	fill_bigmap(info->mlx->img.img_adr, &info->map, p, 0);
	fill_bigpl(info->mlx->img.img_adr, &info->player, (info->player.y * WIDTH) + info->player.x, -1);
	fill_ray(info->mlx->img.img_adr, &info->player, info);
}
