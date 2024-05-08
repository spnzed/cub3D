/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:11:18 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/08 18:46:38 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_ray(int *scr, t_sq *pl)
{
	t_point	*pts;
	//float	tolerance;

	pts = ft_calloc(sizeof(pts), 2);
	if (!pts)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	//tolerance = 0.00001;
	pts[0].x = pl->x + pl->w / 2;
	pts[0].y = pl->y + pl->h / 2;
	pts[1].x = 0;
	pts[1].y = 0;
//	printf("pts[0].x: %i, pts[0].y: %i\n", pts[0].x, pts[0].y);
//	printf("angle: %f, sinus: %f, cos: %f, len: %f\n", pl->ang, sin(pl->ang), cos(pl->ang), pl->len);
	if (pl->ang > 0 && pl->ang < (PI))
	{
		pts[1].x = pts[0].x + cos(pl->ang) * pl->len;
		pts[1].y = pts[0].y - sin(pl->ang) * pl->len;
		//printf("arctan(2.0943951024 radians): %f\n", atan(2.0943951024));
		//printf("arctan(2.0943951024 radians): %f\n", -1 / tan(2.0943951024)); >> AQUESTA ES LA FORMULA BONA
	//	printf("000 pts[1].x: %i, pts[1].y: %i\n", pts[1].x, pts[1].y);
	}
//	printf("111 pts[1].x: %i, pts[1].y: %i\n", pts[1].x, pts[1].y);
	draw_line(scr, pts, 0xFFFF00);
}

static void	fill_bigpl(int *scr, t_sq *pl, int p, int w)
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

static void	fill_bigmap(int *scr, char **grid, int p, int i)
{
	int	j;
	int	k;
	int	po;
	j = -1;
	k = 0;
	po = p;
	while (++j < 5)// j < altura del map quan la tinguem a l'estructura amb la xifra ja parsejada
	{
		while (i < 64 * (j + 1))
		{
			while (grid[j][k])
			{
				while (p < po + (64 * (k + 1) + (WIDTH * i)))
				{
					if (grid[j][k] == '1')
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
	char		*temp[5];
	t_sq		*bigpl;
	int	p = ((HEIGHT / 2 - 160) * WIDTH) + (WIDTH / 2 - 192);

	bigpl = ft_calloc(sizeof(t_sq), 1);
	if (!bigpl)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	temp[0] = "111111";
	temp[1] = "100001";
	temp[2] = "100101";
	temp[3] = "1001E1";
	temp[4] = "111111";
//	bigpl->x = WIDTH / 2 + (64 * 3 / 2); //64 = mida passadissos d'una unitat (utilitzada a fill_map) 3/2 per situar-se just enmig de la columna passadis 2a des del centre del mapa 2D (= WIDTH / 2)
//	bigpl->y = HEIGHT / 2 + 64; // Li sumem 64 pq des del centre de les files (5 files), ens volem posar junt enmig de la 4a fila i la posicio del mig del mapa = HEIGHT / 2
	bigpl->ang = 2.0943951024; //120 graus
	bigpl->len = 32;
	bigpl->w = 8;
	bigpl->h = 8;
	bigpl->x = WIDTH / 2 + (64 * 3 / 2) - (8 / 2); //6 NOMBRE COLUMNES MAP, 64 = mida passadissos d'una unitat (utilitzada a fill_map)
	bigpl->y = HEIGHT / 2 + 64 - (8 / 2);
	fill_bigmap(info->mlx->img.img_adr, temp, p, 0);
	fill_bigpl(info->mlx->img.img_adr, bigpl, (bigpl->y * WIDTH) + bigpl->x, -1);
	fill_ray(info->mlx->img.img_adr, bigpl);
	info->bigpl = bigpl;
}
